//trabalho_programacao_pratica
//dupla_alex_aline

#ifndef CFluidoOleoGas_h
#define CFluidoOleoGas_h

class CFluidoOleoGas
{
  
//atributos comuns a todas as classes derivadas da classe base CFluidoOleoGas  
protected:

double pressaoBolha; //pressao de bolha
double razaoSolubilidade; //razao de solubilidade
double densidadeGasSup; //densidade do gas na superficie
double massaEspecifica; //massa especifica do oleo

//metodos comuns a todas as classes derivadas
public:
 
  //metodo calcula a compressibilidade do oleo
void Compressibilidade();
  
  //metodo calcula o fator volume formacao do oleo
void FatorVolFormacao();

  //metodo calcula a viscosidade do oleo
void Viscosidade();
  
  //metodo calcula a pressao de bolha do oleo
void PressaoBolha();

 // metodo calcula a razao de solubilidade do oleo
void RazaoSolubilidade();

  //metodo calcula a densidade do gas na superficie
void DensidadeGasSup();

  //metodo calcula a massa especifica do oleo
void MassaEspecifica();

};

#endif