#include  "CRazaoSolubilidade_VB.h"

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CRazaoSolubilidade_VB::razaoSolubilidade_VB()

{
/* Razao de solubilidade gas-oleo 

Programa cacula a razao desolubilidade gas-oleo utilizando o metodo
de Vazquez, M. and Beggs, H.D., "Correlations for fluid physical property
prediction (1980).

Entrada:

gammag = densidade do gas ou densidade do gas no separador;
p = pressao em que ser quer calcular a razao de solibilidade, (psia)
pb = pressao de bolha, (psia)
t= temperatura em que ser quer calcular a razao de solibilidade, (F)
API =  densidade oleo, grau API, (API)
psp = pressao no separador, (psia)
tsp = Temperatura no separador, (F)

SAIDA:
Razao de solubilidade (scf/STB) */

fstream fin;
fin.open("dados_razao_solub_VB.dat");


while(!fin.eof())
{
  double gammag;
  fin >> gammag;
  cout<<gammag<<endl; 
  
  double p;
  fin >> p;
  cout<<p<<endl; 
  
  double pb;
  fin >> pb;
  cout<<pb<<endl;
  
  double t;
  fin >> t;
  cout<<t<<endl; 
  
   double API;
  fin >> API;
  cout<<API<<endl;
  
  double psp;
  fin >> psp;
  cout<<psp<<endl;
  
  double tsp;
  fin >> tsp;
  cout<<tsp<<endl; 

//entrada de dados
/*cout<<"Entre com o valor da densidade do gas"<<endl;
cin>>gammag;  cin.get();

cout<<"Entre com o valor da pressao em que se quer calcular a razao de solubilidade"<<endl;
cin>>p;  cin.get();

cout<<"Entre com o valor da pressao de bolha"<<endl;
cin>>pb;  cin.get();

cout<<"Entre com o valor da temperatura em que se quer calcular a razao de solubilidade"<<endl;
cin>>t;  cin.get();

cout<<"Entre com o valor do grau API do oleo"<<endl;
cin>>API;  cin.get();

cout<<"Entre com o valor da pressao no separador"<<endl;
cin>>psp;  cin.get();

cout<<"Entre com o valor da temperatura no separador"<<endl;
cin>>tsp;  cin.get();
*/
double C1;
double C2;
double C3;

//contantes do grau API
 if(API <= 30)
     {
     C1=0.0362;
     C2= 1.0937;
     C3= 25.7240;
     }
 else 
     {
     C1=0.0178;
     C2= 1.1870;
     C3= 23.931;
     }
     
     double razaodesolubilidade;
     double gammagsp;
     
 //teste da pressao
 if(p>pb)
{
     gammagsp= gammag*(1 + 5.912*pow(10,-5)*(API)*tsp*log10(psp/114.7));
        
       razaodesolubilidade = C1*gammagsp*pow(pb,C2)*exp(C3*(API/(t+460)));
}
        else
	{ 
        gammagsp= gammag*(1 + 5.912*pow(10,-5)*(API)*tsp*log10(psp/114.7));
        
        razaodesolubilidade = C1*gammagsp*pow(p,C2)*exp(C3*(API/(t+460)));
	}
	
	//mostra na tela o resultado da razao de solubilidade
  cout<<"O valor da razao de solubilidade e:"<<razaodesolubilidade<<endl;	
}
}