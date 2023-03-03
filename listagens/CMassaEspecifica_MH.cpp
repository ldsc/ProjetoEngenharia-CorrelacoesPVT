#include "CMassaEspecifica_MH.h"

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CMassaEspecifica_MH::MassaEspecifica_MH()

{
/*Massa especifica Oleo- McCain e Hill

Programa calcula a massa especifica do oleo, utilizando o metodo proposto
por McCain, Jr, W. and Hill, N., "Correlations for liquid densities and
evolved gas specific gravities for black oils during pressure depletion,
para se estimar a a massa especifica do oleo na pressao de bolha e em
pressoes menores que a pressao de bolha. Para estimar a massa especifica
do oleo em pressoes maiores que a pressao de bolha, este metodo utiliza o
metodo de McCai e Hill junto com a equacao de definicao da
compressibilidade do oleo.

Entrada:

rsb = razao gas-oleo na pressao de bolha, scf/STB
gammagSP = densidade do gas no separador
gammag= media ponderada da densidade dos gases em superficie
gammaSTO= densidade oleo no tanque
t= temperatura em F
p=pressao que se deseja estimar a massa especifica do oleo(psia)
pb = pressao de bolha(psia)
co= compressibiliadade do oleo em pressoes maiores que a pressao de
bolha, (1/psi)

modo de usar:

1 p=pb,entre com:
muoleom(Rsb,gammagSP, gammag, gammaSTO, T, pb, pb)

2 p<pb, entre com:
muoleom(Rsb,gammagSP, gammag, gammaSTO, T, p, pb)

3 p>pb, entre com:
muoleom(Rsb,gammagSP, gammag, gammaSTO, T, p, pb, co)

SAIDA:

massa especifica do oleo( lb/cu ft) */

fstream fin;
fin.open("dados_mass_especifica_MH.dat");


while(!fin.eof())
{
  double rsb;
  fin >> rsb;
  cout<<rsb<<endl; 
  
  double gammagSP;
  fin >> gammagSP;
  cout<<gammagSP<<endl; 
  
  double gammag;
  fin >> gammag;
  cout<<gammag<<endl; 
  
  double gammagSTO;
  fin >> gammagSTO;
  cout<<gammagSTO<<endl; 
  
  double t;
  fin >> t;
  cout<<t<<endl; 
  
  double p;
  fin >> p;
  cout<<p<<endl; 
  
  double pb;
  fin >> pb;
  cout<<pb<<endl; 
  
  double co;
  fin >> co;
  cout<<co<<endl; 


//entrada de dados

/*cout<<"Entre com o valor da razao gas-oleo na pressao de bolha."<<endl;
cin>>rsb;  cin.get();

cout<<"Entre com o valor da densidade do gas no separador."<<endl;
cin>>gammagSP;  cin.get();

cout<<"Entre com o valor da media ponderada da densidade dos gases em superficie."<<endl;
cin>>gammag;  cin.get();

cout<<"Entre com o valor da densidade do oleo no tanque."<<endl;
cin>>gammaSTO;  cin.get();

cout<<"Entre com o valor da temperatura."<<endl;
cin>>t;  cin.get();

cout<<"Entre com o valor da pressao em que se deseja estimar a massa especifica do oleo."<<endl;
cin>>p;  cin.get();

cout<<"Entre com o valor da pressao de bolha."<<endl;
cin>>pb;  cin.get();

cout<<"Entre com o valor da compressibilidade do oleo em pressoes maiores que a pressao de bolha."<<endl;
cin>>co;  cin.get();
*/
//declaracao de variavel
double massaespecifica;

//correlacao  para pressoes igual a pressao de bolha
if (p == pb)
{
//inicializacao das variaveis  
double w0= -49.8930;
double w1= 85.0149;
double w2= -3.70373;
double w3= 0.0479818;
double w4= 2.98914;
double w5= -0.0356888;
    
//consideracoes a fazer
double rsb1=rsb;
double gammaSTO1= gammaSTO;
double gammag2=gammag;
double gammagSP1=gammagSP;
double ropo = (( rsb1*gammag2 + 4600*gammaSTO1)/(73.71+rsb1*gammag2) 
    /(w0+w1*gammag2+w2*gammagSP1+w3*gammagSP1 + w4
    + w5));
 

//calculo da massa especifica
double deltarop = (0.167 + 16.181*pow(10,(-0.0425*ropo)))*(pb/1000)-0.01
    *(0.299+263*pow(10,(-0.0603*ropo)))*pow((pb/1000),2);


double robs = ropo + deltarop;


double deltarot = (0.00302 + 1.505* pow(robs,(-0.951)))*pow((t-60),0.938)
    -(0.0216 - 0.0233*pow(10,(-0.0161*robs)))*pow((t-60),0.475);

double massaespecifica = robs - deltarot;
}

//correlacao para pressao de reservatorio menor que a pressao de bolha

if( p<pb)
  
{ 
//consideracoes a fazer  
double rsb1=rsb;
double gammaSTO1= gammaSTO;
double gammag2=gammag;
double gammagSP1=gammagSP;

//inicializacao de variaveis
double w0= -49.8930;
double w1= 85.0149;
double w2= -3.70373;
double w3= 0.0479818;
double w4= 2.98914;
double w5= -0.0356888;

//calculo da massa especifica
double ropo = (( rsb1*gammag2 + 4600*gammaSTO1)/(73.71+rsb1*gammag2
    /(w0+w1*gammag2+w2*gammagSP1+w3*gammagSP1 + w4
    + w5))); 

double deltarop = (0.167 + 16.181*pow(10,(-0.0425*ropo)))*(p/1000)-0.01
    *(0.299+263*pow(10,(-0.0603*ropo)))*pow((p/1000),2);


double robs = ropo + deltarop;


double deltarot = (0.00302 + 1.505* pow(robs,(-0.951)))*pow((t-60),0.938)
    -(0.0216 - 0.0233*pow(10,(-0.0161*robs)))*pow((t-60),0.475);

  double  massaespecifica = robs - deltarot; 
}

 
//correlação para pressão de reservatório maior que a pressão de bollha 
if( p>pb )
{ 
//consideracoes a fazer
double rsb1=rsb;
double gammaSTO1= gammaSTO;
double gammag2=gammag;
double gammagSP1=gammagSP;

//inicializacao de variaveis
double w0= -49.8930;
double w1= 85.0149;
double w2= -3.70373;
double w3= 0.0479818;
double w4= 2.98914;
double w5= -0.0356888;

//calculo da massa especifica
double ropo = (( rsb1*gammag2 + 4600*gammaSTO1)/(73.71+rsb1*gammag2 
    /(w0+w1*gammag2+w2*gammagSP1+w3*gammagSP1 + w4
    + w5)));


double deltarop = (0.167 + 16.181*pow(10,(-0.0425*ropo)))*(p/1000)-0.01
    *(0.299+263*pow(10,(-0.0603*ropo)))*pow((p/1000),2);


double robs = ropo + deltarop;


double deltarot = (0.00302 + 1.505* pow(robs,(-0.951)))*pow((t-60),0.938)
    -(0.0216 - 0.0233*pow(10,(-0.0161*robs)))*pow((t-60),0.475);

    double massaespecificapb = robs - deltarot; 
    
    
   double massaespecifica = massaespecificapb*exp(co*(p-pb));
}

//mostra na tela o resultado da massa especifica
cout<<"O valor da massa especifica e:"<<massaespecifica<<endl;
}
}