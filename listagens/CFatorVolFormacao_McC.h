//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CFatorVolFormacao_McC_H
#define CFatorVolFormacao_McC_H

#include "CFatorVolFormacao.h"

class CFatorVolFormacao_McC : public CFatorVolFormacao

{
protected:

double muo; //massa especifica do oleo
double rs; //razao de solubilidade

public:
  
/* metodo calcula o fator volume formacao pelo metodo de McCain et al */  

void FatorVolFormacao_McC();

};

#endif