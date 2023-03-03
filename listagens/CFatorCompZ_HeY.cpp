//trabalho_programacao_pratica
//dupla_alex_aline

#include "CFatorCompZ_HeY.h"

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void CFatorCompZ_HeY::FatorCompZ_HeY()

{

/*
Z_Hall extima o valor do fator de compressibilidade gas Z com ppr e tpr
utilizando o metodo apresentado por  Hall-Yarborough (1973)-A New
Equation of State for Z-factor Calculations

Z_Hall - Calculation of Z factors for natural gases using equations of state.

ENTRADA:
Z_Hall(ppr,Tpr)

Ppr = pressao pseudo-reduzida
Tpr = temperatura pseudo-reduzida

SAIDA
Z = fator de compressibilidade do gas
*/

//Hall & Yaborough


//entrada de dados

fstream fin;
fin.open("dados_fator_comp_Z_HeY.dat");


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

//inicializacao de variavel
double y0 = 0.001;

//calculo temperatura atual
double t = 1./tpr;


//calculo fator de compressibilidade Z
double FZ = ((1+ y0 + pow(y0,2) + pow(y0,3))/pow((1-y0),3))- (14.7*t - 9.76*pow(t,2)
    + 4.58*pow(t,3))*(y0)+ (90.7*t - 242.2*pow(t,2)+ 
    42.4*pow(t,3))*pow(y0,(1.18 + 2.82*t));
    
//mostra na tela o valor do fator de compressibilidade Z    
    cout<<"O valor do fator de compressibilidade Z e:" << FZ << endl;

}
}