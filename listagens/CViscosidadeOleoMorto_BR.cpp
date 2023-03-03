//trabalho_programacao_pratica
//dupla_alex_aline

#include "CViscosidadeOleoMorto_BR.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CViscosidadeOleoMorto_BR :: ViscosidadeOleoMorto_BR() 

{
  
fstream fin;
fin.open("dados_viscosidade_oleo_morto_BR.dat");


while(!fin.eof())
{
  
   double API;
  fin >> API;
  cout<<API<<endl;
  
  double t;
  fin >> t;
  cout<<t<<endl;
  
  //entrada de dados
/*  cout << "Entre com o valor da densidade API\n";
  cin >> API;
  cin.get();
  
  cout << "Entre com o valor da temperatura\n";
  cin >> t;
  cin.get();
*/  
  //calculo de A
double A= pow(10,(3.0324 - 0.02023 * API));

  //calculo da viscosidade do oleo morto
double viscosidadedooleomorto_G = pow(10,(A * pow(t,-1.163)))-1;

 //mostra na tela o resultado da viscosidade do oleo morto
cout << "\nO valor da viscosidade do óleo morto pelo método de Beggs-Robbinson é" << viscosidadedooleomorto_G << endl;


}
}