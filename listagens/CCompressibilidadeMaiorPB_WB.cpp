//trabalho_programacao_pratica
//dupla_alex_aline

#include "CCompressibilidadeMaiorPB_WB.h"

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CCompressibilidadeMaiorPB_WB::CompressibilidadeMaiorPB_WB()

{
/* Coeficiente de compressibilidade isotermica do oleo(compressibilidade 
do oleo) em pressoes de reservatorio maiores que a pressao de bolha
utilizando o metodo de Whitson, C.H. and Brule, M.R., Phase behavior,
(2000), que correlaciona a compressibilidade isotermica com a pressao,
pressao de bolha, e massa especifica na pressao de bolha.

Entrada:

p = pressao atual (psia)
pb = pressao de bolha (psia)
rhoob = massa especifica oleo na pressao de bolha (lb/ cu ft)

SAIDA:

Co= compressibilidade do oleo,(1/psi) */

//entrada de dados

fstream fin;
fin.open("dados_comp_maior_wb.dat");


while(!fin.eof())
{
  double rhoob;
  fin >> rhoob;
  cout<<rhoob<<endl; 
  
  double pb;
  fin >> pb;
  cout<<pb<<endl;
  
  double p;
  fin >> p;
  cout<<p<<endl;
  

/* cout<<"Entre com o valor da massa especifica do oleo na pressao de bolha"<<endl;
double rhoob;
cin>>rhoob;  cin.get();

cout<<"Entre com o valor da pressao de bolha"<<endl;
double pb;
cin>>pb;  cin.get();

cout<<"Entre com o valor pressao atual"<<endl;
double p;
cin>>p;  cin.get(); */

double compressibilidadeoleowb;

//teste do valor da pressao

if( p <= pb)
{
 cout<<"p <= pb, O programa calcula a compressibilidade do oleo em pressoes maiores que a pressao de bolha"<<endl;
}    
else
{
 compressibilidadeoleowb = (pow(10,(-6)))*exp((rhoob + 0.00434*(p-pb)-79.1)/(0.0007141*(p-pb)-12.938));
}

cout<<"A compressibilidade do oleo para pressoes maiore que a pressao de bolha pelo metodo de Whitson, C.H. and Brulé, M.R. e:"<<compressibilidadeoleowb<<endl;
}
}