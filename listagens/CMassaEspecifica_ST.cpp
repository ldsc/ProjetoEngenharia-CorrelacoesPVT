#include "CMassaEspecifica_ST.h"

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CMassaEspecifica_ST::MassaEspecifica_ST()

{
/* Massa especifica Oleo - Standing
A funcao calcula a massa especifica do oleo em pressoes menores e igual
a pressao de bolha , utilizando o metodo proposto por Standing, M.B., 
Volumetric and phase behavior of oil field hydrocarbon systems9th(1981).

Entrada:

rs = razao gas-oleo , scf/STB
gammag= media ponderada da densidade dos gases em superficie
gammaSTO= densidade oleo no tanque
tr= temperatura do reservatorio em F
p= pressao atual (psia)
pb= pressao de bolha (psia)

SAIDA:

massa especifica do oleo( lb/cu ft) */

fstream fin;
fin.open("dados_mass_especifica_ST.dat");


while(!fin.eof())
{
  double rs;
  fin >> rs;
  cout<<rs<<endl; 
  
  double gammag;
  fin >> gammag;
  cout<<gammag<<endl; 
  
  double gammagSTO;
  fin >> gammagSTO;
  cout<<gammagSTO<<endl; 
  
  double tr;
  fin >> tr;
  cout<<tr<<endl; 
  
  double p;
  fin >> p;
  cout<<p<<endl; 
  
  double pb;
  fin >> pb;
  cout<<pb<<endl; 

//entrada de dados
/*cout<<"Entre com o valor da razao gas-oleo."<<endl;
cin>>rs;  cin.get();

cout<<"Entre com o valor da media ponderada da densidade dos gases em superficie."<<endl;
cin>>gammag;  cin.get();

cout<<"Entre com o valor da densidade do oleo no tanque."<<endl;
cin>>gammaSTO;  cin.get();

cout<<"Entre com o valor da temperatura do reservatorio."<<endl;
cin>>tr;  cin.get();

cout<<"Entre com o valor da pressao atual."<<endl;
cin>>p;  cin.get();

cout<<"Entre com o valor da pressao de bolha."<<endl;
cin>>pb;  cin.get();
*/

double massaespecificaooleopb;

//teste da pressao
if( p<=pb)
{
massaespecificaooleopb= (62.4*gammaSTO + 0.0136*rs*gammag)/
    (0.972+0.000147*pow((rs*pow((gammag/gammaSTO),0.5)+1.25*tr),1.175));
}
    else 
 {
 
 cout<<"Programa so calcula a massa especifica em pressoes de reservatorio menores ou iguais a pressao de bolha"<<endl;

 }
}
}