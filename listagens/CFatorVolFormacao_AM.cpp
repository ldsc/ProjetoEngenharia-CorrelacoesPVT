#include "CFatorVolFormacao_AM.h"

#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;

void CFatorVolFormacao_AM::FatorVolFormacao_AM()

{
/* Fator volume formacao - metodo Al-Marhoun

 Programa calcula o fator volume formacao do oleo em pressoes de 
reservatorio menores e iguais a pressao de bolha, utilizando o metodo de 
Al-Marhoun, M., "PVT correlations for Middle East crude oils"(1988)

Entrada:

rs= razao de solubilidade (scf/STB)
gammag = densidade do gas em p,t
gammaSTO = densidade oleo em p,t
t= Temperatura (F) 

Saida:
bo= fator volume formacao do oleo (bbl/STB) */

//entrada de dados


fstream fin;
fin.open("dados_fator_vol_for_AM.dat");


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
  
  double t;
  fin >> t;
  cout<<t<<endl;
  
  double a= 0.742390;
double b=0.323294;
double c=-1.202040;

//conversao da temperatura para rankine
double Trank= t +459.67;

//calculo de f
double f =pow(rs,a)*pow(gammag,b)*pow(gammaSTO,c);

//calculo do fator volume formacao
double fatorvolumeformacao = 0.497069 + 0.000862963*Trank + 0.00182594*f
    + 0.00000318099*pow(f,2);
    
    //mostra na tela o valor do fator volume formacao calculado
    cout<<"O valor do fator volume formacao e :"<<fatorvolumeformacao<<endl;
}
}