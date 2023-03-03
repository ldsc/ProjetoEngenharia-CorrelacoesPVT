//trabalho_programacao_pratica
//dupla_alex_aline

#include "CViscosidadeOleoSat_AKM.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CViscosidadeOleoSat_AKM :: ViscosidadeOleoSat_AKM()

{
  
/*Viscosidade do oleo - metodo de Abu-Khamsim e Al-Marhoun para oleos 
  saturados.
 O programa calcula a viscosidade de oleos saturados pelo metode  de
 Abu-Khamsin, A. and Al-Marhoun,M., "Development of a New Correlation for
 Bubllepoint Viscosity"


roob = massa especifica do oleo na pressao de bolha, (lb/ cu ft)

 */


fstream fin;
fin.open("dados_viscosidade_oleo_sat_AKM.dat");


while(!fin.eof())
{
  
   double roob;
  fin >> roob;
  cout<<roob<<endl;
  
  
//entrada de dados
/*cout << "Entre com o valor da massa especifica do oleo na pressao de bolha\n";
  cin >> roob;
  cin.get();
*/
 //calculo da massa especifica do oleo na pressao de bolha 
double roob1 = roob/62.4;
 
//calculo da viscosidade do oleo saturado
double viscosidadedooleosaturado_AKM = exp(8.484462 * pow(roob1,4)-2.652294);

//mostra na tela o resultado da viscosidade do oleo saturado
cout << "\nO valor da viscosidade do oleo saturado pelo metodo de Abu-Khamsim e Al-Marhoun e" << viscosidadedooleosaturado_AKM << endl;

}
}
