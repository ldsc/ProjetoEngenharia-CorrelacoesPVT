//trabalho_programacao_pratica
//dupla_alex_aline

#include "CCompressibilidadeMaiorPB_Setal.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void CCompressibilidadeMaiorPB_Setal::CompressibilidadeMaiorPB_Setal()

{
/* Coeficiente de compressibilidade isotermica do oleo(compressibilidade 
do oleo), 
Co_maiorpbSetal calcula a compressibilidade do oleo,utilizando o metodo de 
Spivey, John and Valko, Peter and McCain, William, "Applications of the 
Coefficient of Isothermal Compressibility to Various Reservoir Situations
With New Correlations for Each Situation"(2007)

Entrada:

p = pressao atual (psia)
pb = pressao de bolha, (psia)
rsb= razao de solubilidade no ponto de bolha(scf/STB)
gammagSP= densidade do gas no separador
tr = Temperatura do reservatorio, (F)
API =  densidade oleo, grau API, (API)

SAIDA:

Co= compressibilidade do oleo,(1/psi) */

//Calculo comum a todos os metodos

fstream fin;
fin.open("dados_comp_maior_setal.dat");


while(!fin.eof())
{
  double API;
  fin >> API;
  cout<<API<<endl; 

  double gammagSP;
  fin>> gammagSP;
  cout<<gammagSP<<endl;
  
  double rsb;
  fin >> rsb;
  cout<<rsb<<endl;
  
  double tr;
  fin >> tr;
  cout<<tr<<endl; 
  
  double pb;
  fin >> pb;
  cout<<pb<<endl; 
  
  double p;
  fin >> p;
  cout<<p<<endl; 

/*  
cout<<"Entre com o valor do grau API do oleo."<<endl;
double API;
cin>>API;  cin.get();

cout<<"Entre com o valor da densidade do gas no separador."<<endl;
double gammagSP;
cin>>gammagSP;  cin.get();

cout<<"Entre com o valor da razao de solubilidade."<<endl;
double rsb;
cin>>rsb;  cin.get();

cout<<"Entre com o valor da temperatura no reservatorio."<<endl;
double tr;
cin>>tr;  cin.get();

cout<<"Entre com o valor da pressao de bolha."<<endl;
double pb;
cin>>pb;  cin.get();

cout<<"Entre com o valor da pressao atual."<<endl;
double p;
cin>>p;  cin.get(); */

//teste do valor da pressao

if( p <= pb )
{
cout<<"p <= pb, O programa calcula a compressibilidade do oleo em pressoes maiores que a pressão de bolha"<<endl;
}

//inicializacao das variaveis

double VAR_1 = log (API);
double VAR_2 = log (gammagSP);
double VAR_3= log(pb);
double VAR_4= log(p/pb);
double VAR_5 = log(rsb);
double VAR_6 = log (tr);

double C0_1=3.011;
double C0_2=-0.0835; 
double C0_3=3.51;
double C0_4=0.327;
double C0_5=-1.918;
double C0_6=2.52;
 
double C1_1=-2.6254;
double C1_2=-0.259;
double C1_3=-0.0289;
double C1_4=-0.608;
double C1_5=-0.642;
double C1_6=-2.73;

double C2_1= 0.497;
double C2_2= 0.382;
double C2_3= -0.0584;
double C2_4= 0.0911;
double C2_5= 0.154;
double C2_6=0.429;


//calculo de cofb

double Z[5];

    Z[0]= C0_1+C1_1*VAR_1+C2_1*(VAR_1*VAR_1);

    Z[1]= C0_2+C1_2*VAR_2+C2_2*(VAR_2*VAR_2);
    
    Z[2]= C0_3+C1_3*VAR_3+C2_3*(VAR_3*VAR_3);
    
    Z[3]= C0_4+C1_4*VAR_4+C2_4*(VAR_4*VAR_4);
    
    Z[4]= C0_5+C1_5*VAR_5+C2_5*(VAR_5*VAR_5);
    
    Z[5]= C0_6+C1_6*VAR_6+C2_6*(VAR_6*VAR_6);
    
double z = Z[0] + Z[1] + Z[2] + Z[3] + Z[4] + Z[5];

double cofb = exp(2.434 +0.475*z +0.048*(z*z)-log(pow(10,6)));
    
 
         
           double dzdp = (-0.608 + 0.1822*log(p/pb))/p;
            
           double  dcofbdp = cofb*(0.475 +0.096*z)*dzdp;
            
	   //calculo da compressibilidade do oleo
	   
           double compressibilidadeoleo = cofb + (p-pb)*dcofbdp;
           
cout<<"A compressibilidade do oleo para pressoes maiores que a pressao de bolha pelo metodo de Spivey, John and Valko, Peter and McCain, William e:"<< compressibilidadeoleo <<endl;
  
}
}