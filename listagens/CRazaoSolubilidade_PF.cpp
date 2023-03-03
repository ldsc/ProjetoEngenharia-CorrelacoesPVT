#include "CRazaoSolubilidade_PF.h"

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CRazaoSolubilidade_PF::RazaoSolubilidade_PF()

{
/* Razao de solubilidade gas-oleo 
 Programa calcula a razao de solubilidade gas-oleo utilizando o metodo
 de Petrosky, G. E., and F. Farshad. Pressure-Volume-Temperature 
Correlations for Gulf of Mexico Crude Oils."(1993). 

Entrada:

gammag = densidade do gas ou densidade do gas no separador;
p = pressao em que ser quer calcular a razao de solibilidade, (psia)
pb = pressao de bolha, (psia)
t = temperatura em que ser quer calcular a razao de solibilidade, (F)
API =  densidade oleo, grau API, (API)

SAIDA:

Razao de solubilidade (scf/STB) */

fstream fin;
fin.open("dados_razao_solub_PF.dat");


while(!fin.eof())
{
  double gammag;
  fin >> gammag;
  cout<<gammag<<endl; 
  
  double API;
  fin >> API;
  cout<<API<<endl; 
  
  double t;
  fin >> t;
  cout<<t<<endl;
  
  double pb;
  fin >> pb;
  cout<<pb<<endl; 
  
   double p;
  fin >> p;
  cout<<p<<endl;
  

//entrada de dados
/*cout<<"Entre com o valor a densidade do gas"<<endl;
cin>>gammag;  cin.get();

cout<<"Entre com o valor do grau API do oleo"<<endl;
cin>>API;  cin.get();

cout<<"Entre com o valor da temperatura em que se quer calcular a razao de solubilidade"<<endl;
cin>>t;  cin.get();

cout<<"Entre com o valor da pessao de bolha"<<endl;
cin>>pb;  cin.get();

cout<<"Entre com o valor da pressao em que se quer calcular a razao de solubilidade"<<endl;
cin>>p;  cin.get();
*/
double razaodesolubidade;

//teste da pressao
if (p>pb)
{
  double x = 7.916*pow(10,-4)*pow(API,1.5410)- 4.561*pow(10,-5)*pow(t,1.3911);

   razaodesolubidade = ((pb/112.727)+12.340)*pow(gammag,0.8439)*pow(pow(10,x),1.73184);
}
else
{
 double x = 7.916*pow(10,-4)*pow(API,1.5410)- 4.561*pow(10,-5)*pow(t,1.3911);

  razaodesolubidade = ((p/112.727)+12.340)*pow(gammag,0.8439)*pow(pow(10,x),1.73184);
}

//mostra na tela o resultado da razao de solubilidade
cout<<"O valor da razao de solubilidade e:"<<razaodesolubidade<<endl;
}
}