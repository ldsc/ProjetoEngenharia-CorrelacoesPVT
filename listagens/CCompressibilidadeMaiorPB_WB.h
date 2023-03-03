//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CCompressibilidadeMaiorPB_WB_h
#define CCompressibilidadeMaiorPB_WB_h

#include "CCompressibilidade.h"

class CCompressibilidadeMaiorPB_WB : public CCompressibilidade

{
//atibuto pertencente somente a classe derivada CCompressibilidadeMaiorPB_WB   
  
protected:

double rhoob; //massa especifica oleo na pressao de bolha

public:

/*metodo calcula a compressibilidade do oleo para pressoes acima
da pressao de bolha pelo metodo de Whitson e Brule. */ 
  
void CompressibilidadeMaiorPB_WB();

};

#endif