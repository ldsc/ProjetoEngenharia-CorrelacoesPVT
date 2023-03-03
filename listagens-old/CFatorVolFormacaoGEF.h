//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CFatorVolFormacao_GEF_H
#define CFatorVolFormacao_GEF_H

#include "CFatorVolFormacao.h"

class CFatorVolFormacao_GEF : public CFatorVolFormacao

{
protected:

double rsb; //razao de solubilidade no ponto de bolha
double tr; //temperatura reduzida
double p; //pressao atual
double pb; //pressao de bolha

public:
  
/* metodo calcula o fator volume formacao pelo metodo de 
 GE e Farshad*/  

void FatorVolFormacao_GEF();

};

#endif