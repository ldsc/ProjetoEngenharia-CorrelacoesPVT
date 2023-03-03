//trabalho_programacao_pratica
//dupla_alex_aline

#include "CPressaoBolha_SM.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CPressaoBolha_SM::PressaoBolha_SM()
{
/* Programa para estimar a pressao de bolha do oleo utilizando a 
correlacao de Standing, M.B.(1981), Volumetric and phase behavior
of oil field hydrocarbon systems9th e a troca da densidade do gas pela
densidade do gas no separador proposto por McCain(1991) The properties of
petroleum fluids

Entrada:

rsp= razão de solubilidade no separador(scf/STB)
API =  densidade oleo, grau API, (API)
gammagSP= densidade do gas no separador
tr= Temperatura do reservatorio (F) 

Saida:

pb=pressao de bolha do oleo(psia) */

fstream fin;
fin.open("dados_pressao_bolha_SM.dat");


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
/*cout<<"Entre com o valor da razao de solubilidade no separador."<<endl;
cin>>rsp;  cin.get();

cout<<"Entre com o valor do grau API do oleo."<<endl;
cin>>API;  cin.get();

cout<<"Entre com o valor da densidade do gas no separador."<<endl;
cin>>gammagSP;  cin.get();

cout<<"Entre com o valor da temperatura do reservatorio."<<endl;
cin>>tr;  cin.get();
*/
//calculo da pressao de bolha
double pressaodebolha = 18.2*((pow((rsp/gammagSP),0.83))*(pow(10,(0.00091* tr - 0.0125*API)))-1.4);

//mostra na tela o resutado da pressao de bolha
cout<<"O valor da pressao de bolha pelo metodo de Standing e McCain e:"<<pressaodebolha<<endl;
}
}
