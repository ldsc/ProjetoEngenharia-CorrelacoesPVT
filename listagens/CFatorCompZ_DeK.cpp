//trabalho_programacao_pratica
//dupla_alex_aline

#include "CFatorCompZ_DeK.h"

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void CFatorCompZ_DeK::FatorCompZ_DeK()
{
/*Programa extima o valor do fator de compressibilidade gas Z com ppr e tpr
utilizando o metodo apresentado por  Dranchuk and Abou-Kassem (1975)
- Calculation of Z factors for natural gases using equations of state.

ENTRADA:

ppr = pressao pseudo-reduzida
tpr = temperatura pseudo-reduzida

SAIDA:

Z = fator de compressibilidade do gas*/


//inicializacao de variaveis

double A1  = +0.32650;
double A2  = -1.07000;
double A3  = -0.53390;
double A4  = +0.01569;
double A5  = -0.05165;
double A6  = +0.54750;
double A7  = -0.73610;
double A8  = +0.18440;
double A9  = +0.10560;
double A10 = +0.61340;
double A11 = +0.72100;

//entrada de dados

fstream fin;
fin.open("dados_fator_comp_Z_Dek.dat");


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

//calculo do fator de compressibilidade Z

      double  Z =  A1 + A2/tpr + A3/pow(tpr,3) + A4/pow(tpr,4) + A5/pow(tpr,5)*(0.27*ppr/tpr)
            + (A6 + A7/tpr) + A8/pow(tpr,2)*pow(0.27*ppr/tpr,2) 
            - A9*(A7/tpr + A8/pow(tpr,2)*pow(0.27*ppr/tpr,5)
            + A10*(1 + A11*((0.27*ppr)/pow(tpr,2))*((pow(0.27*ppr/tpr,2)/pow(tpr,3))
            * exp( -A11 * pow(0.27*ppr/tpr,2)))));
	    
    cout<<"O valor do fator de compressibilidade do gas Z e:"<<endl;
    cout<<Z<<endl;
}
}