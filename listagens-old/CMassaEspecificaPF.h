//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CMassaEspecifica_PF_H
#define CMassaEspecifica_PF_H

#include "CMassaEspecifica.h"

class CMassaEspecifica_PF : public CMassaEspecifica

{
//atributos pertencentes somente a classe derivada CMassaEspecifica_PF  
protected:

double rsb; //razao gas-oleo no ponto de bolha
double tr; //temperatura reduzida


public:

 /* metodo calcula a massa especifica do oleo pelo metodo de McCain Jr e Hill*/ 
void MassaEspecifica_PF();

};

#endif