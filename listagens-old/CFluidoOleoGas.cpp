//trabalho_programacao_pratica
//dupla_alex_aline

#include "CFluidoOleoGas.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CFluidoOleoGas::DensidadeGasSup()

{
/*Densidade do gas na superficie

gammag(gammagSP, pSP, RSP,API) calcula a densidade do gas, utilizando os
metodo de McCain, W.D. and Spivey, J.P. and Lenn, C.P., Petroleum
Reservoir Fluid Property Correlations (Oklahoma: PennWell Corporation,
2010) e o metodo de Velarde, J. and Blasingame, T. and McCain, Jr, W.,
"Correlation of Black Oil Properties at Pressures Below Bubble Point 
Pressure-A New Approach", in Annual Technical Meeting (1999)
em que:
gammagSP= densidade do gas no separador

*/

fstream fin;
fin.open("dados_fluido_oleogas_dens_gas_sup.dat");


while(!fin.eof())
{
  double gammagSP;
  fin >> gammagSP;
  cout<<gammagSP<<endl; 

    //entrada de dados
/*  cout<<"Entre com o valor da densidade do gas no separador."<<endl;
  cin>> gammagSP;  cin.get();
*/     
   //calculo da densidade do gas na superficie
  double densidadegassurperficie = 1.066*gammagSP;
  
   //mostra na tela o resultado do gas em superficie
  cout<<"O valor da densidade do gas em superficie e:" <<densidadegassurperficie << endl;  

  
}
}