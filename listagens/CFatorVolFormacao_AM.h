//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CFatorVolFormacao_AM_H
#define CFatorVolFormacao_AM_H

#include "CFatorVolFormacao.h"

class CFatorVolFormacao_AM : public CFatorVolFormacao

{
//a classe so possui atributos da classe base CFatorVolFormacao  
  
protected:

double rs; //razao de solubilidade
double t; //temperatura atual

public:

/* metodo calcula fator volume formacao do oleo pelo metodo
de Al-Marhoun */  
  
void FatorVolFormacao_AM();

};

#endif
