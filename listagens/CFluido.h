//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CFluido_h
#define CFluido_h

class CFluido
{
  
//atributos comuns a todas as classes derivadas da classe base CFluido  
//os atributos sao comuns aos dois fluidos : oleo e gas  
protected:

double compressibilidade; //compressibilidade do oleo ou do gas
double fatorVolFormacao; //fator volume formacao do oleo ou do gas
double viscosidade; //viscosidade do oleo ou do gas


//metodos comuns aos dois fluidos
public:
  
//metodo calcula a compressibilidade do oleo e do gas
double Compressibilidade();

//metodo calcula o fator volume formacao do oleo e do gas
double FatorVolFormacao();

//metodo calcula a viscosidade do oleo e do gas
double Viscosdade();

};

#endif