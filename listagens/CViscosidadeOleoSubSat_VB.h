//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CViscosidadeOleoSubSat_VB_h
#define CViscosidadeOleoSubSat_VB_h

#include "CViscosidadeOleoSubSat.h"

class CViscosidadeOleoSubSat_VB : public CViscosidadeOleoSubSat

{
 //a classe possui apenas atributos da classe base CViscosidadeOleoSubSat 
  
public:
  
  /* metodo calcula viscosidade do oleo subsaturado
   pelo metodo de Vazquez e Beggs */
  void ViscosidadeOleoSubSat_VB();
  
};

#endif