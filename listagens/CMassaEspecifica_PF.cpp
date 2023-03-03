#include "CMassaEspecifica_PF.h"

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CMassaEspecifica_PF::MassaEspecifica_PF()
{
/* Massa especifica Oleo - Standing
A funcao calcula a massa especifica do oleo em pressoes maiores que
a pressao de bolha , utilizando o metodo proposto por GE, Petrosky. & Farshad, F.
Pressure-Volume-Temperature Correlations for Gulf of Mexico Crude Oils

Entrada:

rsb = razao gas-oleo no ponto de bolha , scf/STB
gammag= media ponderada da densidade dos gases em superficie
gammaSTO= densidade oleo no tanque
tr= temperatura do reservatorio em F
p= pressao atual (psia)
pb= pressao de bolha (psia)

SAIDA:

massa especifica do oleo( lb/cu ft) */

fstream fin;
fin.open("dados_mass_especifica_PF.dat");


while(!fin.eof())
{
  double rsb;
  fin >> rsb;
  cout<<rsb<<endl; 
  
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
  
  double mepb1;
  fin >> mepb1;
  cout<<mepb1<<endl; 


//entrada de dados
/*cout<<"Entre com o valor da razao gas ole no ponto de bolha"<<endl;
cin>>rsb;  cin.get();

cout<<"Entre com o valor da média ponderada da densidade dos gáses em superfície"<<endl;
cin>>gammag;  cin.get();

cout<<"Entre com o valor da densidade do oleo no tanque"<<endl;
cin>>gammaSTO;  cin.get();

cout<<"Entre com o valor da temperatura do reservatorio"<<endl;
cin>>tr;  cin.get();

cout<<"Entre com o valor da pressao atual"<<endl;
cin>>p;  cin.get();

cout<<"Entre com o valor da pressao de bolha"<<endl;
cin>>pb;  cin.get();
*/
 //calculo do grau API
 double API=((141.5)/(gammaSTO))-131.5;
  
 //entrada de dados
cout<<"Entre com o valor da massa especifica calculada pelo metodo de Standing"<<endl;
cin>>mepb1;  cin.get();    

  //calculo da massa especifica
 double  A=4.1646*pow(10,-7)*pow(rsb,0.69357)*pow(gammag,0.1885)*pow(API,0.3772)*pow(tr,0.6729);
 double massaespecifica = mepb1* exp(A*(pow(p,0.4094)-pow(pb,0.4094)));
 
 //mostra na tela o resultado da massa especifica do oleo
 cout<<"O valor da massa especifica do oleo e:"<< massaespecifica <<endl;

}
}