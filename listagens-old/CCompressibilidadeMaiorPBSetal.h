//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CCompressibilidadeMaiorPB_Setal_h
#define CCompressibilidadeMaiorPB_Setal_h

#include "CCompressibilidade.h"

class CCompressibilidadeMaiorPB_Setal : public CCompressibilidade

{
protected:

//atributos pertencentes somente a classe derivada CCompressibilidadeMaiorPB_Setal 
  
double rsb; //razao de solubilidade
double gammagSP; //densidade do gas no separador
double tr; //temperatura reduzida
double API; //grau API

public:

/*metodo que calcula a compressibilidade para pressoes maiores que a pressao de
bolha pelo metodo de Spivey et al. */ 
  
void CompressibilidadeMaiorPB_Setal();

};

#endif