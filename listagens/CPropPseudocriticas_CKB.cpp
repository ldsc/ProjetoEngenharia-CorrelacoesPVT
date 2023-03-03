#include "CPropPseudocriticas_CKB.h"
#include <iostream>
#include <fstream>

using namespace std;

void CPropPseudocriticas_CKB :: PropPseudocriticas_CKB()

{
/*Correcao para caulcular as propriedades pseudocriticas de gases com 
contaminates utilizando metodo de Carr, N. and Kobayashi, R. and Burrows,
D., Viscosity of hydrocarbon gases under pressure vol. 6 1954.

 Este metodo correlaciona as Propriedade de pseudocriticas do gas com a
densidade do gas, porcentagem de contaminantes.

 yN2 =  porcentagem de N2
 yH2S = porcentagem de H2S
 yCO2 = pocentagem de CO2
 gammag = densidade do gas (hidrocarbonetos gasosos e contaminates)
 
retorna:

ppcc= pressao pseudo-critica com correcao de contaminates (psia)
Tpcc= temperatura pseudo-critica com correcao de contaminates (R)*/

//propriedades dos hidrocarbonetos

fstream fin;
fin.open("dados_prop_pseudocritica_CKB.dat");


while(!fin.eof())
{
  double ppc;
  fin >> ppc;
  cout<<ppc<<endl; 
  
  double Tpc;
  fin >> Tpc;
  cout<<Tpc<<endl; 


//entrada de dados
/*cout<<"Entre com o valor da pressao pseudocritica.";
cin>>ppc; cin.get();
cout<<"Entre com o valor da temperatura pseudocritica.";
cin>>Tpc; cin.get();
*/
//calculo da pressao pseudocritica
double ppcc = ppc + 440*yCO2 + 600*yH2S - 170*yN2;

//calculo da temperatura pseudocritica
double Tpcc = Tpc -80*yCO2 + 130*yH2S - 250*yN2;

//mostra na tela o resultado das propriedades pseudocriticas
cout<<"O valor da pressao e temperatura pseudiocriticas com correcao de contaminantes sao respectivamente:"
    <<"  ...  "<<ppcc<<"  ...  "<<Tpc<<endl;
}
}