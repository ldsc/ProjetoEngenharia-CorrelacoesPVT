//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CCompressibilidadeMenorPB_h
#define CCompressibilidadeMenorPB_h

#include "CCompressibilidade.h"

class CCompressibilidadeMenorPB:public CCompressibilidade

{
protected:

//atributos pertencentes somente a classe derivada CCompressibilidadeMenorPB  
  
double rsb; //razao de solubilidade
double t; //temperatura atual
double API; //grau API

public:
  
/*metodo calcula a compressibilidade do oleo para pressoes abaixo da pressao
de bolha pelo metodo de McCain Jr et al.*/   

void CompressibilidadeMenorPB();

};

#endif