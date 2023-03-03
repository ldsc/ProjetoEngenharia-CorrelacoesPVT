#include "CPropPseudocriticas_ST.h"
#include <iostream>
#include <fstream>

using namespace std;

void CPropPseudocriticas_ST::PropPseudocriticas_ST()
{
/*Propriedades pseudocriticas de gases naturais puros, utilizando o metodo
de Standing, M.B., Volumetric and Phase Behavior of Oil Field Hydrocarbon
Systems, 1977.

PropcST retorna os valores de ppc e Tpc para gases naturais puros
, utilizando as equacoes de STANDING (1977).*/

fstream fin;
fin.open("dados_prop_pseudocritica_ST.dat");


while(!fin.eof())
{
  double gammag;
  fin >> gammag;
  cout<<gammag<<endl; 
  
  int tipodegas;
  fin >> tipodegas;
  cout<<tipodegas<<endl; 
  
 

//entrada de dados
/*cout<<"Entre com o valor da densidade do gas"<<endl;
cin>>gammag; cin.get();
*/


 while ( true )
 { 
/* cout<<"Entre com o tipo de gas que deseja.Digite 1 para gas seco e 2 para gas umido."<<endl;
 cin>>tipodegas; cin.get();
*/ 
 switch ( tipodegas ) 
 {
 case 1: tpc = 168 + 325*gammag - 12.5*gammag*gammag;  //gas seco
         ppc = 677 + 15*gammag - 37.5*gammag*gammag;  // gas seco 
         break ;
	 
 case 2:  tpc = 187 + 330 * gammag - 71.5 * gammag*gammag ; //gas umido
          ppc = 706 - 51.7*gammag - 11.1* (gammag*gammag) ; //gas umido
         break ;

 default :  tpc = 168 + 325*gammag - 12.5*gammag*gammag;  //gas seco
            ppc = 677 + 15*gammag - 37.5*gammag*gammag ; //gas seco 
           break ;
 }
  
 }
 //mostra na tela os resultados das propriedades pseudocriticas
 cout<<"Os valores da pressao e temperatura pseudocriticas sao respectivamente:"<<ppc<<"   "<<tpc<<endl;
  
 }
}