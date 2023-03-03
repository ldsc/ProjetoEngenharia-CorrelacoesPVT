//trabalho_programacao_pratica
//dupla_alex_aline

#include "CViscosidadeOleoSat_BR.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CViscosidadeOleoSat_BR :: ViscosidadeOleoSat_BR()

{
  
/*Viscosidade do oleo - metodo de Beggs-Robinson para oleos saturados
 A fucao miombr calcula a viscosidade de oleos saturados pelo metodo de
 Beggs, HD and Robinson, JR, "Estimating the viscosity of crude oil
 systems"(1975)

 Entrada:
 Rs = razao de solubilidade(scf/STB);
 miod = viscosidade do oleo morto(cp); */

fstream fin;
fin.open("dados_viscosidade_oleo_sat_BR.dat");


while(!fin.eof())
{
  
   double miob;
  fin >> miob;
  cout<<miob<<endl;
  
   double Rs;
  fin >> Rs;
  cout<<Rs<<endl;

//entrada de dados
/*cout << "Entre com o valor da viscosidade do oleo saturado\n";
  cin >> miob;
  cin.get();
  
  cout << "Entre com o valor da razao de solubilidade\n";
  cin >> Rs;
  cin.get();
*/ 
  //calculo de a e b
double a = 10.715 * pow((Rs +100),-0.515);
double b = 5.44 * pow((Rs + 150),-0.338);

 //calculo da viscosidade do oleo saturado
double viscosidadedooleosaturado_BR = a * pow(miob,b);
 
//mostra na tela o resultado da viscosidade do oleo saturado
cout << "\nO valor da viscosidade do oleo saturado pelo metodo de Beggs-Robbinson e" << viscosidadedooleosaturado_BR << endl;

}
}