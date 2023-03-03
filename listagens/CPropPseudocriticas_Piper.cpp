//trabalho_programacao_pratica
//dupla_alex_aline

#include "CPropPseudocriticas_Piper.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CPropPseudocriticas_Piper::PropPseudocriticas_Piper()
{
/*Correcao para calcular as propriedades pseudocriticas de gases com 
contaminates utilizando metodo - Piper, L.D AND McCain, Jr. and Corredor,
J.H,, "Compressibility Factors for Naturally Occurring Petroleum Gases. 
Gas Reservoir Engineering. Reprint Series", v.52 (1999), pp. p.186-200.


Este metodo correlaciona as Propriedade de pseudocriticas do gas com a
densidade do gas, porcentagem de contaminantes, e temperatura e pressao
critica dos contaminantes.


 gammag = densidade do gas (hidrocarbonetos gasosos e contaminates)
 yN2 =  porcentagem molar de N2 (ex: 35% entre com 0.35)
 yH2S = porcentagem molar de H2S
 yCO2 = pocentagem molar de CO2
 pcN2 = pressao critica do N2 (psia)
 pcH2S = pressao critica do H2S (psia)
 pcCO2 = pressao critica do CO2 (psia)
 TcN2 = Temperatura critica de N2 (R) 
 TcH2S = Temperatura critica de H2S (R)
 TcCO2 = Temperatura critica de CO2 (R)

retorna:

Ppcc= pressao pseudo-critica com correcao de contaminates (psia)
Tpcc= temperatura pseudo-critica com correcao de contaminates (R) */

//inicializacao de variaveis
double a0= 1.1582*(0.1);
double a1= -4.5820*(0.1);
double a2= -9.0348*(0.1);
double a3= -6.6026*(0.1);
double a4= 7.0729*(0.1);
double a5= -9.9397*(0.01);

double b0= 3.8216;
double b1= -6.5340*(0.01);
double b2= -4.2113*(0.1);
double b3= -9.1249*(0.1);
double b4= 1.7438*(0.1);
double b5= -3.2191;

fstream fin;
fin.open("dados_prop_pseudocritica_Piper.dat");


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
  
  double PcH2S;
  fin >> PcH2S;
  cout<<PcH2S<<endl;
  
  double PcCO2;
  fin >> PcCO2;
  cout<<PcCO2<<endl; 
  
  double PcN2;
  fin >> PcN2;
  cout<<PcN2<<endl;
  
  double TcH2S;
  fin >> TcH2S;
  cout<<TcH2S<<endl;
  
  double TcCO2;
  fin >> TcCO2;
  cout<<TcCO2<<endl; 
  
  double TcN2;
  fin >> TcN2;
  cout<<TcN2<<endl;

//entrada de dados
/*cout<<"Entre com o valor da densidade do gas.";
cin>>gammag; cin.get();

cout<<"Entre com o valor da porcentagem molar do H2S.";
cin>>yH2S; cin.get();

cout<<"Entre com o valor da porcentagem molar do CO2.";
cin>>yCO2; cin.get();

cout<<"Entre com o valor da porcentagem molar do N2.";
cin>>yN2; cin.get();

cout<<"Entre com o valor da pressao critica do H2S.";
cin>>PcH2S; cin.get();

cout<<"Entre com o valor da pressao critica do CO2.";
cin>>PcCO2; cin.get();

cout<<"Entre com o valor da pressao critica do N2.";
cin>>PcN2; cin.get();

cout<<"Entre com o valor da temperatura critica do H2S.";
cin>>TcH2S; cin.get();

cout<<"Entre com o valor da temperatura critica do CO2.";
cin>>TcCO2; cin.get();

cout<<"Entre com o valor da temperatura critica do N2.";
cin>>TcN2; cin.get();
*/
//calculo de j
double J = a0 + a1*yH2S*(TcH2S/PcH2S)+ a2*yCO2*(TcCO2/PcCO2) + a3*yN2*(TcN2/PcN2) + a4*gammag + a5*gammag*gammag;

//calculo de k
double K = b0 + b1*yH2S*(TcH2S/(pow(PcH2S,(1/2))))+ b2*yCO2*(TcCO2/(pow(PcCO2,(1/2)))) + b3*yN2*(TcN2/(pow(PcN2,(1/2)))) + b4*gammag + b5*gammag*gammag;

//calculo da temperatura pseudocritica
double tpcc = (K*K)/J;

//calculo da pressao pseudocriticas
double ppcc = tpcc/J ;

//mostra na tela o resultado das propriedades pseudocriticas
cout<<"O valor da temperatura e pressao pseudocriticas com correcao de contaminantes sao respectivamente:"<<tpcc<<"    "<<ppcc<<endl;


}
}