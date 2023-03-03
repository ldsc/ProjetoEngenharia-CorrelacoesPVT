#ifndef CMassaEspecifica_ST_H
#define CMassaEspecifica_ST_H

#include "CMassaEspecifica.h"

class CMassaEspecifica_ST : public CMassaEspecifica

{
//atributos pertencentes somente a classe derivada CMassaEspecifica_ST  
protected:

double rs; //razao gas-oleo
double tr; //temperatura reduzida

public:

//metodo calcula a massa especifica do oleo pelo metodo de Standing  
void MassaEspecifica_ST();

};

#endif