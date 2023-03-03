//trabalho_programacao_pratica
//dupla_alex_aline

#include "CRazaoSolubilidade.h"

#ifndef CRazaoSolubilidade_VB_H
#define CRazaoSolubilidade_VB_H

class CRazaoSolubilidade_VB : public CRazaoSolubilidade
{
//atributos pertencentes somente a classe derivada CRazaoSolubilidade_VB  
  
protected:

double psp; //pressao no separador
double tsp; //temperatura no separador

public:

//metodo calcula razao de solubilidade pelo metodo de Vazquez e Beggs  
void razaoSolubilidade_VB();

};

#endif