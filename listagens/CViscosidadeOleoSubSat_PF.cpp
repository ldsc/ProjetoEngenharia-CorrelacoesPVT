//trabalho_programacao_pratica
//dupla_alex_aline

#include "CViscosidadeOleoSubSat_PF.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CViscosidadeOleoSubSat_PF :: ViscosidadeOleoSubSat_PF() 

{
  
fstream fin;
fin.open("dados_viscosidade_oleo_sub_sat_PF.dat");


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

/*cout << "Entre com o valor da viscosidade do óleo saturado\n";
  cin >> miob;
  cin.get();
  
  cout << "Entre com o valor da pressão do reservatório\n";
  cin >> p;
  cin.get();
  
  cout << "Entre com o valor da pressão de bolha\n";
  cin >> pb;
  cin.get();
*/  
  double A;
  
  //calculo de A
  A= -1.0146 + 1.3322 * (log10(miob)) - 0.4876 * pow(log10(miob),2)- 1.15036 * pow(log10(miob),3);
 
  //calculo viscosidade do oleo subsaturado
double viscosidadedooleosubsaturado_PF = miob + 1.3449 * pow(10,-3) * (p-pb) * pow(10,A); 

  //mostra na tela o resultado da viscosidade do oleo subsaturado
cout << "\nO valor da viscosidade do oleo sub saturado pelo metodo de Petrosky e Farshad e" << viscosidadedooleosubsaturado_PF << endl;

}
}