#ifndef CPropPseudocriticas_ST_h
#define CPropPseudocriticas_ST_h

#include "CPropPseudocriticas.h"

class CPropPseudocriticas_ST: public CPropPseudocriticas
{
 //atributos pertencentes somente a classe derivada CPropPseudocriticas_ST 
protected:

double tpc; //temperatura pseudocritica
double ppc; //pressao pseudocritica


public:

//metodo calcula propriedades pseudocriticas pelo metodo de Standing  
void PropPseudocriticas_ST();

};

#endif