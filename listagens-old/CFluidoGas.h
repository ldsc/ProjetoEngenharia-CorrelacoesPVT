#ifndef CFluidoGas_h
#define CFluidoGas_h

#include "CFluido.h"

class CFluidoGas : public CFluido

{
//atributos pertencentes somente a classe derivada CFluidoGas  
protected:

double propPseudocriticas; //propriedades pseudocriticas (temperatura e pressao)
double fatorCompZ; //fator de compressibilidade Z

//metodos que possuem uma unica forma de resolver
public:

  //metodo calcula a compressibilidade do gas
void Compressibilidade();
  
  //metodo calcula o fator volume formacao do gas
void FatorVolFormacao();
 
 //metodo calcula a viscosidade do gas
void Viscosidade();

 //metodo calcula as propriedades pseudocriticas do gas
void PropPseudocriticas();

 //metodo calcula o fator de compressibilidade Z do gas
void FatorCompZ();

};

#endif