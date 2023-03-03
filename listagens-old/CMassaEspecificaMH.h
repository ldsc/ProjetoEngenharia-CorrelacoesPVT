#include "CMassaEspecifica.h"

#ifndef CMassaEspecifica_MH_H
#define CMassaEspecifica_MH_H

class CMassaEspecifica_MH : public CMassaEspecifica

{
//atributos pertencentes somente a classe derivada CMassaEspecifica_MH  
protected:

double rsb; //razao gas-oleo na pressao de bolha
double gammagSP; //densidade do gas no separador
double t; //temperatura atual
double co; //compressibilidade do oleo em pressoes maiores que a pressao de bolha

public:

/* metodo calcula a massa especifica do oleo pelo metodo de McCain Jr e Hill*/

void MassaEspecifica_MH();

};

#endif