//trabalho_programacao_pratica
//dupla_alex_aline

#include "CViscosidadeOleoMorto_G.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CViscosidadeOleoMorto_G :: ViscosidadeOleoMorto_G() 

{
  
fstream fin;
fin.open("dados_viscosidade_oleo_morto_G.dat");


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
double A= 10.313 * (log10(t)) - 36.447;
  
  //calculo da viscosidade do oleo morto
double viscosidadedooleomorto_G = (3.141 * (10^10)) * pow(t,-3.444) * pow(log10(API),A);

  //mostra na tela o resultado da viscosidade do oleo morto
cout << "\nO valor da viscosidade do oleo morto pelo metodo de Glaso e" << viscosidadedooleomorto_G << endl;

}
}
  
  