#include "CFatorVolFormacao_GEF.h"

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void CFatorVolFormacao_GEF::FatorVolFormacao_GEF()

{
/*Fator volume formacao - metodo Pettrosky e Farshad

 Programa calcula o fator volume formacao do oleo em pressoes de 
reservatorio maiores que a pressao de bolha, utilizando o metodo
apresentado por  Petrosky, GE and Farshad, FF, "Pressure-Volume-Temperature
Correlations for Gulf of Mexico Crude Oils" (1993)

Entrada:

rsb= razao de solubilidade no ponto de bolha (scf/STB)
gammag = densidade do gas em p,T
gammaSTO = densidade oleo em p,T 
tr= Temperatura de reservatorio(F) 
p= pressao atual(psia)
pb= pressao de bolha(psia)

Saida:

Bo= fator volume formacao do oleo (bbl/STB) */

fstream fin;
fin.open("dados_fator_vol_for_GEF.dat");


while(!fin.eof())
{
  double rsb;
  fin >> rsb;
  cout<<rsb<<endl; 
  
  double gammag;
  fin >> gammag;
  cout<<gammag<<endl;
  
  double gammaSTO;
  fin >> gammaSTO;
  cout<<gammaSTO<<endl;
  
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

/*cout<<"Entre com o valor da razao de solubilidade no ponto de bolha"<<endl;
cin>>rsb;  cin.get();

cout<<"Entre com o valor da densidade do gas"<<endl;
cin>>gammag;  cin.get();

cout<<"Entre com o valor da densidade do oleo"<<endl;
cin>>gammaSTO;  cin.get();

cout<<"Entre com o valor da temperatura do reservatorio"<<endl;
cin>>tr;  cin.get();

cout<<"Entre com o valor da rpressao atual"<<endl;
cin>>p;  cin.get();

cout<<"Entre com o valor da pressao de bolha"<<endl;
cin>>pb;  cin.get();
*/
//calculo do grau API do oleo
double API=((141.5)/(gammaSTO))-131.5;

//calculo da variavel a
double A=4.1646*pow(10,-7)*pow(rsb,0.69357)*pow(gammag,0.1885)*
    pow(API,0.3272)*(tr,0.6729);

//calculo do fator volume formacao
double fatorvolumeformacao= exp(-A*(pow(p,0.4094)-pow(pb,0.4094)));

//mostra na tela o resultado do fator volume formacao
cout<<"O valor do fator volume formacao e :"<<fatorvolumeformacao<<endl;

}
}
