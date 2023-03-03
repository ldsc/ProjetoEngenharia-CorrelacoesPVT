//trabalho_programacao_pratica
//dupla_alex_aline

#include "CCompressibilidadeMenorPB.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

/*Coeficiente de compressibilidade isotermica do oleo(compressibilidade 
do oleo) em pressoes de reservatorio menores ou igual a pressao de bolha-
utilizando o metodo de McCainJr, W. and Rollins, J. and Lanzi, Alejandro,
J., "The coefficient of isothermal compressibility of black oils at 
pressures below the bubblepoint", SPE formation evaluation 3, 3 (1988),
pp. 659--662.

Entrada:

pressao = pressão atual (psia)
pressaoBolha= pressão de bolha
rsb= razão de solubilidade no ponto de bolha (scf/STB) 
t= temperatura (°F)
API= densidade API do óleo

Saida:

Co= compressibilidade do óleo (1/psia)*/


void CCompressibilidadeMenorPB::CompressibilidadeMenorPB()

{
  
//entrada de dados  
  
fstream fin;
fin.open("dados_comp_menor.dat");


while(!fin.eof())
{
  double pressao;
  fin >> pressao;
  cout<<pressao<<endl;  
  
  double pressaoBolha;
  fin >> pressaoBolha;
  cout<<pressaoBolha<<endl;
  
  double t;
  fin >> t;
  cout<<t<<endl;
  
  double API;
  fin >> API;
  cout<<API<<endl;
  
  double rsb;
  fin >> rsb;
  cout<<rsb<<endl;
  
/*cout<<"Entre com o valor da pressao atual."<<endl;
double pressao;
cin>>pressao; cin.get();

cout<<"Entre com o valor da pressao de bolha."<<endl;
double pressaoBolha;
cin>>pressaoBolha; cin.get();

cout<<"Entre com o valor da temperatura."<<endl;
double t;
cin>>t; cin.get();

cout<<"Entre com o valor do grau API."<<endl;
double API;
cin>>API; cin.get();

cout<<"Entre com o valor da razao de solubilidade."<<endl;
double rsb;
cin>>rsb; cin.get(); */

double A;

//teste do valor da pressao

if (pressao >= pressaoBolha)
{  
cout<<"error(' p=> pb, A função Co_menorpbMR calcula a compressibilidade do oleo em pressoes menores que a pressao de bolha')"<<endl;
}    
else
{
  A = -7.573-1.45*log(pressao)-0.383*log(pressaoBolha)+1.402*log(t+459.67)+
    0.256*log(API)+0.449*log(rsb);
}

double compressibilidadeoleo = exp(A);

cout<<"O valor da compressibilidade do oleo e: "<<"   "<<compressibilidadeoleo<<endl;

}
}