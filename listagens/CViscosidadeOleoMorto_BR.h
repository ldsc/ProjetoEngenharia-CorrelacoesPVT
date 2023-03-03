//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CViscosidadeOleoMorto_BR_h
#define CViscosidadeOleoMorto_BR_h

#include "CViscosidadeOleoMorto.h"

class CViscosidadeOleoMorto_BR : public CViscosidadeOleoMorto

{
  //a classe possui apenas atributos da classe base CViscosidadeOleoMorto

public:
 
  /*metodo calcula viscosidade do oleo morto pelo metodo de Beggs 
  e Robinson */
  void ViscosidadeOleoMorto_BR();
  
};

#endif