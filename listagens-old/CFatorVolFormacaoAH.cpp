#include "CFatorVolFormacao_AH.h"

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void CFatorVolFormacao_AH::FatorVolFormacao_AH()

{
/*Fator volume formação - metodo McCain Jr

 Programa calcula o fator volume formacao do oleo em presoes de 
reservatorio maiores que a pressao de bolha, utilizando o metodo
apresentado por McCain, W.D. and Spivey, J.P. and Lenn, C.P., Petroleum
Reservoir Fluid Property Correlations (2010)

Entrada:

rsb= razao de solubilidade no ponto de bolha (scf/STB)
gammag = densidade do gas em p,T
gammaSTO = densidade do oleo em p,T 
tr= Temperatura de reservatorio(F) 
p= pressao atual(psia)
pb= pressao de bolha(psia)

Saida:

Bo= fator volume formação do oleo (bbl/STB) */

//entrada de dados

fstream fin;
fin.open("dados_fator_vol_for_AH.dat");


while(!fin.eof())
{
  double rsb;
  fin >> rsb;
  cout<<rsb<<endl;
  
  double gammag;
  fin >> gammag;
  cout<<gammag<<endl;
  
  double gammaSTO;
  fin >> gammaSTO;
  cout<<gammaSTO<<endl;
  
  double tr;
  fin >> tr;
  cout<<tr<<endl;
  
  double p;
  fin >> p;
  cout<<p<<endl;
  
  double pb;
  fin >> pb;
  cout<<pb<<endl;

/* cout<<"Entre com o valor da razao de solubilidade no ponto de bolha"<<endl;
cin>>rsb;  cin.get();

cout<<"Entre com o valor da densidade do gas"<<endl;
cin>>gammag;  cin.get();

cout<<"Entre com o valor da densidade do oleo"<<endl;
cin>>gammaSTO;  cin.get();

cout<<"Entre com o valor da temperatura do reservatorio"<<endl;
cin>>tr;  cin.get();

cout<<"Entre com o valor da pressao atual"<<endl;
cin>>p;  cin.get();

cout<<"Entre com o valor da pressao de bolha"<<endl;
cin>>pb;  cin.get(); */

//calculo do grau API do oleo
double API=((141.5)/(gammaSTO))-131.5;

//calculo da densidade do gas no separador
double gammagSP= gammag/1.066;

//calculo do fator volume formacao
double fatorvolumeformacao= exp(p-pb);

//mostra na tela o valor do fator volume formacao calculado
cout<<"O valor do fator volume formacao e:"<<fatorvolumeformacao<<endl;
}
}
