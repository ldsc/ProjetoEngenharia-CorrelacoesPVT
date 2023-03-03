//trabalho_programacao_pratica
//dupla_alex_aline

#include "CFatorCompZ_Lond.h"

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void CFatorCompZ_Lond::FatorCompZ_Lond()

{
/*
londono extima o valor do fator de compressibilidade gas Z com ppr e tpr
utilizando o metodo apresentado por Londono et al (2002) - Simplified
Correlations for Hydrocarbon Gas Viscosity and Gas Density - Validation 
and Correlation of Behavior Using a Large-Scale Database.

ENTRADA:

zlondono(ppr,Tpr)

ppr = pressao pseudo-reduzida
Tpr = temperatura pseudo-reduzida

SAIDA:

Z = fartor de compressibilidade do gas


*/

//inicilizacao de variavel

double A1  = +0.3024696;
double A2  = -1.046964;
double A3  = -0.1078916;
double A4  = -0.7694186;
double A5  = 0.1965439;
double A6  = +0.6527819;
double A7  = -1.118884;
double A8  = +0.3951957;
double A9  = +0.09313593;
double A10 = +0.8483081;
double A11 = +0.7880011;

//entrada de dados

fstream fin;
fin.open("dados_fator_comp_Z_Lond.dat");


while(!fin.eof())
{
  double ppr;
  fin >> ppr;
  cout<<ppr<<endl;
  
  double tpr;
  fin >> tpr;
  cout<<tpr<<endl;
  
/* cout<<"Entre com o valor da pressao pseudo-reduzida"<<endl;
cin>>ppr;  cin.get();

cout<<"Entre com o valor da temperatura pseudo-reduzida"<<endl;
cin>>tpr;  cin.get(); */

//calculo do fator de compressibilidade 
double  F = (A1 + A2/tpr + A3 / pow(tpr,3) + A4/pow(tpr,4) + A5/pow(tpr,5))*(0.27*ppr/(tpr))
            + (A6 + A7/tpr + A8/pow(tpr,2))*pow((0.27*ppr/(tpr)),2)
            - A9*(A7/tpr + A8/pow(tpr,2))*pow((0.27*ppr/(tpr)),5)
            + A10*(1 + A11*pow((0.27*ppr/(tpr)),2))*(pow((0.27*ppr/(tpr)),2)/pow(tpr,3))
            * exp( -A11 * pow((0.27*ppr/(tpr)),2) );
  
	//mostra na tela o valor do fator de compressibilidade
 cout<<"O valor do fator de compressibilidade e"<< F <<endl;
 
}
}
  