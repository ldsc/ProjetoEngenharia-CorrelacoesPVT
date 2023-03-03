#include "CFatorVolFormacao_McC.h"

#include <iostream>
#include <fstream>

using namespace std;

void CFatorVolFormacao_McC::FatorVolFormacao_McC()
{
/*Fator volume formacao - metodo  Ahmed, T

 Programa calcula o fator volume formacao do oleo em pressoes de 
reservatorio menores e iguais a pressao de bolha, utilizando o metodo
apresentado por Ahmed, T., Equations of State and PVT Analysis (2007)

Entrada:

rs= razao de solubilidade (scf/STB)
gammag = densidade do gas em p,T
gammaSTO = densidade oleo em p,T 
muo= massa especifica do oleo nas condicoes p,T

Saida:

Bo= fator volume formacao do oleo (bbl/STB) */

fstream fin;
fin.open("dados_fator_vol_for_McC.dat");


while(!fin.eof())
{
  double rs;
  fin >> rs;
  cout<<rs<<endl; 
  
  double gammag;
  fin >> gammag;
  cout<<gammag<<endl;
  
  double gammaSTO;
  fin >> gammaSTO;
  cout<<gammaSTO<<endl;
  
   double muo;
  fin >> muo;
  cout<<muo<<endl;
  

//entrada de dados

/*cout<<"Entre com o valor da razao de solubilidade"<<endl;
cin>>rs;  cin.get();

cout<<"Entre com o valor da densidade do gas"<<endl;
cin>>gammag;  cin.get();

cout<<"Entre com o valor da densidade do oleo"<<endl;
cin>>gammaSTO;  cin.get();

cout<<"Entre com o valor da massa especifica do oleo"<<endl;
cin>>muo;  cin.get();
*/
//calculo do fator volume formacao
double fatorvolumeformacao= ((62.4*gammaSTO)+0.0136*rs*gammag)/muo;

//mostra na tela o resultado do fator volume formacao
cout<<"O valor do fator volume formacao e: "<< fatorvolumeformacao <<endl;
}
}