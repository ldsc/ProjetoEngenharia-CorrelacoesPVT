//trabalho_programacao_pratica
//dupla_alex_aline

#include "CViscosidadeOleoSubSat_VB.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CViscosidadeOleoSubSat_VB :: ViscosidadeOleoSubSat_VB() 

{
  
fstream fin;
fin.open("dados_viscosidade_oleo_sub_sat_VB.dat");


while(!fin.eof())
{
  
   double miob;
  fin >> miob;
  cout<<miob<<endl;
  
   double p;
  fin >> p;
  cout<<p<<endl;
  
  double pb;
  fin >> pb;
  cout<<pb<<endl;
  
  //entrada de dados
/*  cout << "Entre com o valor da viscosidade do oleo saturado\n";
  cin >> miob;
  cin.get();
  
  cout << "Entre com o valor da pressao do reservatorio\n";
  cin >> p;
  cin.get();
  
  cout << "Entre com o valor da pressao de bolha\n";
  cin >> pb;
  cin.get();
*/

  double m;
  
  //calculo de m
  m= 2.6 * pow(p,1.187) * pow(10,(-3.9 * pow(10,-5) *p -5));
  
  //calculo viscosidade do oleo subsaturado
double viscosidadedooleosubsaturado_VB = (miob) * pow((p/pb),m);

 //mostra na tela o resultado da viscosidade do oleo subsaturado
cout << "\nO valor da viscosidade do oleo sub saturado pelo metodo de Vazquez-Beggs e" << viscosidadedooleosubsaturado_VB << endl;

}
}