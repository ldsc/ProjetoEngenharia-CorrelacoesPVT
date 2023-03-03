//trabalho_programacao_pratica
//dupla_alex_aline

/*Correcao para calcular as propriedades pseudocriticas de gases com 
contaminates utilizando metodo de  Wichert, E. AND Aziz, K, Calculation
of Z's for Sour Gases vol.51, 1972

 Este metodo correlaciona as Propriedade de pseudocriticas do gas com a
densidade do gas, porcentagem de contaminantes.

 yN2 =  porcentagem molar de N2
 yH2S = porcentagem molar de H2S
 yCO2 = pocentagem molar de CO2
 gammag = densidade da mistura de hidrocarbonetos gasosos e contaminates

retorna:
ppcc= pressao pseudo-critica com correcao de contaminates (psia)
tpcc= temperatura pseudo-critica com correcao de contaminates (R)*/

#include "CPropPseudocriticas_WA.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void CPropPseudocriticas_WA :: PropPseudocriticas_WA()
{
  
fstream fin;
fin.open("dados_prop_pseudocritica_WA.dat");


while(!fin.eof())
{
  double gammag;
  fin >> gammag;
  cout<<gammag<<endl; 
  
  double yH2S;
  fin >> yH2S;
  cout<<yH2S<<endl; 
  
  double yCO2;
  fin >> yCO2;
  cout<<yCO2<<endl;
  
  double yN2;
  fin >> yN2;
  cout<<yN2<<endl; 
  
   double ppc;
  fin >> ppc;
  cout<<ppc<<endl;
  
  double Tpc;
  fin >> Tpc;
  cout<<Tpc<<endl; 
  
  
//entrada de dados  
/*cout<<"Entre com o valor da densidade do gas.";
cin>>gammag; cin.get();

cout<<"Entre com o valor da porcentagem molar do H2S.";
cin>>yH2S; cin.get();

cout<<"Entre com o valor da porcentagem molar do CO2.";
cin>>yCO2; cin.get();

cout<<"Entre com o valor da porcentagem molar do N2.";
cin>>yN2; cin.get();
*/  
//densidade de hidrocarbonetos
  
double dg = (gammag - 0.967 * yN2 - 1.52*yCO2-1.18*yH2S)/ (1.0- yN2 -yCO2 - yH2S);

//propriedades dos hidrocarbonetos
//entrada de dados
/*cout<<"Entre com o valor da pressão pseudocritica.";
cin>>ppc; cin.get();
cout<<"Entre com o valor da temperatura pseudocritica.";
cin>>Tpc; cin.get();
*/
//propriedades da mistura

double ppcm = (1.0- yN2 -yCO2 - yH2S)*ppc + 493.0*yN2 + 1071.0*yCO2 + 1306.0* yH2S;
 
double Tpcm = (1.0- yN2 -yCO2 - yH2S)*Tpc + 227.0*yN2 + 548.0*yCO2 + 672.0* yH2S;

//ajustes

double e = 120.0* (((pow((yCO2+yH2S),0.9)) - (pow((yCO2 + yH2S),1.6))) + 15.0*((pow(yH2S,0.5)) -(pow(yH2S,4.0)))); 

ppcc = (ppcm*( Tpcm - e))/(Tpcm + yH2S*(1.0-yH2S)* e);
tpcc = (Tpcm - e);

//mostra na tela o resultado das propriedades pseudocriticas
cout<<"A pressão e a temperatura pseudocriticas com correcao de contaminante sao respectivamente:"
    <<ppcc<<" ...  "<<tpcc<<endl;
  
}
}