//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CViscosidadeOleoSat_BR_h
#define CViscosidadeOleoSat_BR_h

class CViscosidadeOleoSat_BR

{
  
protected:
  double miob; //viscosidade do oleo morto
  double Rs; //razao de solubilidade
  
public:
  
  /*metodo calcula viscosidade do oleo saturado
   pelo metodo de Beggs e Robinson*/
  void ViscosidadeOleoSat_BR();
  
};

#endif