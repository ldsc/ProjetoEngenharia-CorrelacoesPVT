#include "CFluidoGas.h"
#include <cmath>

#include <iostream>
#include <fstream>

using namespace std;

void CFluidoGas::Compressibilidade()
{
/* Funcao Cg, calcula a compressibilidade dos gases naturais, utilizando o
 o metodo de Mattar, L. and Brar, G. and Aziz, K., Compressibility of
 natural gases vol. 14, no. 4 (Society of Petroleum Engineers, 1975), que
calcula a compressibilidade reduzida do gas e depois a converte na
compressibilidade do gas multiplicando pela pressao pseudocritica.*/
  
//inicializacao de variaveis  
double a1  = +0.32650;
double a2  = -1.07000;
double a3  = -0.53390;
double a4  = +0.01569;
double a5  = -0.05165;
double a6  = +0.54750;
double a7  = -0.73610;
double a8  = +0.18440;
double a9  = +0.10560;
double a10 = +0.61340;
double a11 = +0.72100;

fstream fin;
fin.open("dados_fluido_gas_compressibilidade.dat");


while(!fin.eof())
{
  double ppr;
  fin >> ppr;
  cout<<ppr<<endl; 
  
  double Tpr;
  fin >> Tpr;
  cout<<Tpr<<endl;
  
  double Z;
  fin >> Z;
  cout<<Z<<endl;
  
   double ppc;
  fin >> ppc;
  cout<<ppc<<endl;
  
  

//entrada de dados
/*cout<<"Entre com o valor da pressao pseudoreduzida do gas ."<<endl;
cin>>ppr; cin.get();

cout<<"Entre com o valor da temperatura pseudoreduzida do gas ."<<endl;
cin>>Tpr; cin.get();

cout<<"Entre com o valor do fator de compressibilidade Z."<<endl;
cin>>Z; cin.get();
*/
//calculo da massa especifica  do gas pseudo-reduzida
 double ropr = 0.27*( ppr/( Z* Tpr));
 
  
//calculo da derivada (dz/dro)Tpr utilizando o  metodo Dranchuk e Abu-Kassem

   double dzdro_Tro = a1 + a2/Tpr + a3/(Tpr*Tpr*Tpr)+ a4/(Tpr*Tpr*Tpr*Tpr)+ a5/(Tpr*Tpr*Tpr*Tpr*Tpr*Tpr)+
    2*ropr*(a6 + a7/Tpr +a8/(Tpr*Tpr)) -
    5*(ropr*ropr*ropr*ropr)*a9*(a7/Tpr + a8/(Tpr*Tpr)) +
    (2*a10*ropr/(Tpr*Tpr*Tpr))*(1+a11*(ropr*ropr)- (a11*a11)*(ropr*ropr*ropr*ropr))*
    exp(-a11*(ropr*ropr));

    //calculo da variavel F_Cgr
 double F_Cgr = 1/ppr - (0.27/((Z*Z)*Tpr))*(dzdro_Tro/(1+(ropr/Z)+ dzdro_Tro));

 //entrada de dado
/* cout<<"Entre com o valor da pressao pseudocritica."<<endl;
 cin>>ppc; cin.get();
*/ 
 //calculo da compressibiidade
 double Compressibilidadegas = F_Cgr/ppc;
     
 //mostra na tela o resultado da compressibilidade
cout<<"O valor da compressibilidade do gas e:"<<Compressibilidadegas<<endl;

}
}

void CFluidoGas::FatorVolFormacao()
{
// Bg calcula o fator volume formacao do gas(Bg), utilizando a equacao que 
//define esta propriedade. Esta funcao estima Bg em funcao da temperatura, 
//pressao e fator de compressibilidade do gas.

  
 //inicializacao de variavel 
double const c=0.02827;

fstream fin;
fin.open("dados_fluido_gas_fator_vol_form.dat");


while(!fin.eof())
{
  double Z;
  fin >> Z;
  cout<<Z<<endl; 
  
  double T;
  fin >> T;
  cout<<T<<endl;
  
  double P;
  fin >> P;
  cout<<P<<endl;
  

//entrada de dados
/*cout<<"Entre com o valor do fator de compressibilidade Z."<<endl;
cin>>Z; cin.get();

cout<<"Entre com o valor da temperatura em rankine."<<endl;
cin>>T; cin.get();

cout<<"Entre com o valor da pressao em psia."<<endl;
cin>>P; cin.get();
*/
//calculo do fator de compressibilidade
double Fator_Volume_Formacao_gas = c*Z*T/P;

//mostra na tela o resultado do fator volume formacao
cout<<"O valor do fator volume formacao do gas e:"<<Fator_Volume_Formacao_gas;
  
}
}

void CFluidoGas::Viscosidade()

{
//muLGE calcula a viscosidade do gas utilizando o metodo de Lee, A. and
//Gonzalez, M. and Eakin, B., The viscosity of natural gases vol. 18, no.
//8(1966).

fstream fin;
fin.open("dados_fluido_gas_viscosidade.dat");


while(!fin.eof())
{
  double T;
  fin >> T;
  cout<<T<<endl; 
  
  double gammag;
  fin >> gammag;
  cout<<gammag<<endl;
  
  double p;
  fin >> p;
  cout<<p<<endl;
  
  double Z;
  fin >> Z;
  cout<<Z<<endl;
  

 //entrada de dados 
/*cout<<"Entre com o valor da temperatura em rankine."<<endl;
cin>>T; cin.get();
*/
//conversao da temperatura para rankine
double Trank = T + 459.67;

//cálculo dp peso molecular aparente

/*cout<<"Entre com o valor da densidade do gas"<<endl;
cin>>gammag; cin.get();
*/
//calculo da variavel pmga
double pmga = gammag*28.96;  

//entrada de dados
/*cout<<"Entre com o valor da pressao em psia."<<endl;
cin>>p; cin.get();

cout<<"Entre com o valor do fator de compressibilidade Z."<<endl;
cin>>Z; cin.get();
*/
//calculo da variavel rhog
double rhog= (p*pmga/(10.73*Z*(Trank)));

//parametros do metodo
double X=3.448 + 986.4/Trank + 0.010009*pmga;

double Y=2.447 -0.2224*X;

double K=(9.379 + 0.01607*pmga)*(pow(Trank,1.5))/(209.2 + 19.26*pmga + Trank);

//calculo da viscosidade do gas
double viscosidade_gas= (0.0001)* K * exp((pow(X*(rhog/62.428),Y)));

//mostra na tela o resultado da viscosidade
cout<<"O valor da viscosidade e:"<< viscosidade_gas <<endl;
  
}
}

