//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CPropPseudocriticas_Piper_h
#define CPropPseudocriticas_Piper_h

#include "CPropPseudocriticas.h"

class CPropPseudocriticas_Piper : public CPropPseudocriticas 

{
  
//atributos pertencentes somente a classe derivada CPropPseudocriticas_Piper  
protected:

double tpcc; //temperatura pseudocritica
double ppcc; //pressao pseudocritica
double yN2; //porcentagem molar de N2
double yH2S; //porcentagem molar de H2S
double yCO2; //porcentagem molar de CO2
double PcN2; //pressao critica de N2
double PcH2S; //pressao critica de H2S
double PcCO2; //pressao critica de CO2
double TcN2; //temperatura critica de N2
double TcH2S; //temperatura critica de H2S
double TcCO2; //temperatura critica de CO2

public:

  //metodo calcula as propriedades pseudocriticas pelo metodo de Piper et al
void PropPseudocriticas_Piper();

};

#endif