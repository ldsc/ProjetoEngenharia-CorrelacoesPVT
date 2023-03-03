//trabalho_programacao_pratica
//dupla_alex_aline

#include "CPressaoBolha_VA.h"

#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void CPressaoBolha_VA::PressaoBolha_VA()
{
/* Programa para estimar a pressao de bolha do oleo utilizando o metodo 
de Valko(2003)- Reservoir oil bubblepoint pressures revisited; solution 
gas--oil ratios and surface gas specific gravities


Entrada:

rsp= razao de solubilidade no separador(scf/STB)
API =  densidade oleo, grau API, (API)
gammagSP= densidade do gas no separador
tr= Temperatura do reservatorio (F) 

Saida:

pb=pressao de bolha do oleo(psia) */

fstream fin;
fin.open("dados_pressao_bolha_VA.dat");


while(!fin.eof())
{
  double rsp;
  fin >> rsp;
  cout<<rsp<<endl; 
  
  double API;
  fin >> API;
  cout<<API<<endl; 
  
  double gammagSP;
  fin >> gammagSP;
  cout<<gammagSP<<endl; 
  
  double tr;
  fin >> tr;
  cout<<tr<<endl; 

//entrada de dados
/*cout<<"Entre com o valor da razão de solubilidade no separador."<<endl;
cin>>rsp;  cin.get();

cout<<"Entre com o valor do grau API do oleo."<<endl;
cin>>API;  cin.get();

cout<<"Entre com o valor da densidade do gas no separador."<<endl;
cin>>gammagSP;  cin.get();

cout<<"Entre com o valor da temperatura do reservatorio."<<endl;
cin>>tr;  cin.get();
*/
//atribuicao de variaveis
double VAR_1 = log(rsp);
double VAR_2 = API;
double VAR_3 = gammagSP;
double VAR_4 = tr;

//inicializacao de variaveis
double C0_1 = -5.48;
double C0_2 = 1.27;
double C0_3 = 4.51;
double C0_4 = -0.7835;
 
double C1_1 = -0.0378;
double C1_2 = -0.0449;
double C1_3 = -10.84;
double C1_4 = 6.23*(pow(10,(-3)));

double C2_1 = 0.281;
double C2_2 = 4.36*(pow(10,(-4)));
double C2_3 = 8.39;
double C2_4 = -1.22*(pow(10,(-5)));

double C3_1 = -0.0206;
double C3_2 = -4.76*(pow(10,(-6)));
double C3_3 = -2.34;
double C3_4 = 1.03*(pow(10,(-8)));

double Z[4];

//calculo dos componentes de Z
Z[0]= C0_1 + C1_1*VAR_1 + C2_1*(VAR_1*VAR_1)+ C3_1*(pow(VAR_1,3));

Z[1]= C0_2 + C1_2*VAR_2 + C2_2*(VAR_2*VAR_2)+ C3_2*(pow(VAR_2,3));

Z[2]= C0_3 + C1_3*VAR_3 + C2_3*(VAR_3*VAR_3)+ C3_3*(pow(VAR_3,3));

Z[3]= C0_4 + C1_4*VAR_4 + C2_4*(VAR_4*VAR_4)+ C3_4*(pow(VAR_4,3));

double z= Z[0] + Z[1] + Z[2] + Z[3];

//calculo da pressao de bolha
double pressaodebolha = exp(7.475 + 0.713*z + 0.0075*(z*z));

//mostra na tela o resultado da pressao de bolha
cout<<"O valor da pressao de bolha pelo metodo de Valko e: "<<pressaodebolha<<endl;

}
}