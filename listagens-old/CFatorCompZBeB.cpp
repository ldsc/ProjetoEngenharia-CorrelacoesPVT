#include "CFatorCompZ_BeB.h"

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void CFatorCompZ_BeB::FatorCompZ_BeB()

{
/* Programa estima o valor do fator de compressibilidade gas Z com ppr e tpr
utilizando o metodo apresentado po Brill e Beggs (1974)- Two-phase flow in pipes.

ENTRADA:

ppr = pressao pseudo-reduzida
tpr = temperatura pseudo-reduzida

SAIDA:

Z = fator de compressibilidade do gas */
 
//entrada de dados

fstream fin;
fin.open("dados_fator_comp_Z_BeB.dat");


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

   double A = 1.39*pow(tpr - 0.92,2) - 0.36*tpr - 0.101;
   double  B = (0.62 - 0.23*tpr)*ppr + pow((0.066/(tpr - 0.86) - 0.037)*ppr,2)
        + pow(0.32*ppr,6)/pow(10,(9*(tpr - 1)));
   double  C = 0.132 - 0.32*tpr;
   double D = pow(10,(0.3106 - 0.49*tpr + pow(0.1824*tpr,2)));

   double Z = A + (1 - A)/exp(B) + pow(C*ppr,D);

//mostra na tela o valor do fator de compressibilidade Z   
   
cout<<"O valor do fator de compressibilidade Z e: "<< Z <<endl;

}
}