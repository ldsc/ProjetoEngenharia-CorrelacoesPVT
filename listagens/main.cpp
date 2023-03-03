#include "CFluido.h"
#include "CFatorCompZ.h"
#include "CFatorCompZ_BeB.h"
#include "CFatorCompZ_DeK.h"
#include "CFatorCompZ_HeY.h"
#include "CFatorCompZ_Lond.h"
#include "CFluidoGas.h"
#include "CPropPseudocriticas.h"
#include "CPropPseudocriticas_CKB.h"
#include "CPropPseudocriticas_Piper.h"
#include "CPropPseudocriticas_ST.h"
#include "CPropPseudocriticas_WA.h"
#include "CCompressibilidade.h"
#include "CCompressibilidadeMaiorPB_Setal.h"
#include "CCompressibilidadeMaiorPB_WB.h"
#include "CCompressibilidadeMenorPB.h"
#include "CFatorVolFormacao.h"
#include "CFatorVolFormacao_AH.h"
#include "CFatorVolFormacao_AM.h"
#include "CFatorVolFormacao_GEF.h"
#include "CFatorVolFormacao_McC.h"
#include "CFluidoOleoGas.h"
#include "CMassaEspecifica.h"
#include "CMassaEspecifica_MH.h"
#include "CMassaEspecifica_PF.h"
#include "CMassaEspecifica_ST.h"
#include "CPressaoBolha.h"
#include "CPressaoBolha_SM.h"
#include "CPressaoBolha_VA.h"
#include "CRazaoSolubilidade.h"
#include "CRazaoSolubilidade_PF.h"
#include "CRazaoSolubilidade_VB.h"
#include "CViscosidadeOleoMorto.h"
#include "CViscosidadeOleoMorto_BR.h"
#include "CViscosidadeOleoMorto_G.h"
#include "CViscosidadeOleoSat_AKM.h"
#include "CViscosidadeOleoSat_BR.h"
#include "CViscosidadeOleoSubSat.h"
#include "CViscosidadeOleoSubSat_PF.h"
#include "CViscosidadeOleoSubSat_VB.h"


#include <iostream>

using namespace std;

int main()

{
  int resp;
  
  do//permite ao usuario realizar um novo calculo
  {
cout<< "Este programa realiza o calculo de propriedades referentes ao gas ou ao oleo contidos em um reservatório.\n";

cout<< "Escolha o tipo de fluido.Digite [1] - gas e [2] - oleo.\n";

int tipofluido;

cin>> tipofluido;  cin.get();

switch( tipofluido )

{
  case 1:  // o fluido e um gas 
    
   cout<< "Escolha a propriedade que deseja calcular.Digite:\n"
       << "[1] - Viscosidade;\n" 
       << "[2] - Compressibilidade;\n"
       << "[3] - Fator volume formacao;\n"
       << "[4] - Propriedades pseudocriticas;\n" 
       << "[5] - Fator de compressibilidade Z." << endl;
   
   int propriedadegas;
   
   cin>>propriedadegas;   cin.get();
   
   switch(propriedadegas)
     
   {
     case 1: //se a propriedade e a viscosidade
       
       CFluidoGas viscosidade;
       
       viscosidade.Viscosidade();
       
       break;
       
     case 2: //se a propriedade e a compressibilidade
       
       CFluidoGas compressibilidade;
       
       compressibilidade.Compressibilidade();
       
       break;
       
     case 3: //se a propriedade e o fator volume formacao
       
       CFluidoGas fatorvolformacao;
       
       fatorvolformacao.FatorVolFormacao();
       
       break;
       
     case 4: //se a escolha for pelas propriedades pseudocriticas
       
       cout << "Escolha o metodo pelo qual deseja calcular as propriedades pseudocriticas.\n"
            << "Digite [1] - metodo de Carr, N. and Kobayashi, R. and Burrows, D.\n"
	    << "Digite [2] - metodo - Piper, L.D AND McCain, Jr. and Corredor,J.H.\n"
	    << "Digite [3] - metodo de Standing, M.B.\n"
	    << "Digite [4] - metodo de  Wichert, E. AND Aziz, K." << endl;
	    
	    int metodopropseudocriticas;
	    
	    cin>> metodopropseudocriticas;   cin.get();
	    
	    switch (metodopropseudocriticas)
	      
	    {
	      
	      case 1: //metodo de Carr, N. and Kobayashi, R. and Burrows,D.
		
		CPropPseudocriticas_CKB metodoCKB;
		
		metodoCKB.PropPseudocriticas_CKB();
		
		break;
		
	      case 2: //metodo de Piper et al
		
		CPropPseudocriticas_Piper metodoPiper;
		
		metodoPiper.PropPseudocriticas_Piper();
		
		break;
		
	      case 3: //metodo de Standing
		
		CPropPseudocriticas_ST metodoST;
		
		metodoST.PropPseudocriticas_ST();
		
		break;
		
	      case 4: //metodo de Wichert e Aziz
		
		CPropPseudocriticas_WA metodoWA;
		
		metodoWA.PropPseudocriticas_WA();
		
		break;
		
	    }
	    
	    break;
	    
	case 5: //se a propriedade e o fator de compressibilidade Z
	  
	  cout << "Escolha o metodo pelo qual deseja calcular o Fator de Compressibilidade Z.\n"
            << "Digite [1] - metodo apresentado po Brill e Beggs.\n"
	    << "Digite [2] - metodo apresentado por  Dranchuk and Abou-Kassem.\n"
	    << "Digite [3] - metodo apresentado por  Hall-Yarborough.\n"
	    << "Digite [4] - metodo apresentado por Londono et al." << endl;
	    
	    int metodofatcompZ;
	    
	    cin>> metodofatcompZ;   cin.get();
	    
	    switch (metodofatcompZ)
	      
	    {
	      
	      case 1: //metodo de Brill e Beggs
		
		CFatorCompZ_BeB metodofatcompZ_BeB;
		
		metodofatcompZ_BeB.FatorCompZ_BeB();
		
		break;
		
	      case 2: //metodo de Dranchuk e Kassem
		
		CFatorCompZ_DeK metodofatcompZ_DeK;
		
		metodofatcompZ_DeK.FatorCompZ_DeK();
		
		break;
		
	      case 3: //metodo de Hall e Yarbough
		
		CFatorCompZ_HeY metodofatcompZ_HeY;
		
		metodofatcompZ_HeY.FatorCompZ_HeY();
		
		break;
		
	      case 4: //metodo de Londono et al
		
		CFatorCompZ_Lond metodofatcompZ_Lond;
		
		metodofatcompZ_Lond.FatorCompZ_Lond();
		
		break;
		
	    }
	    
	    break;
	    
   }
   
   break;
   
    case 2: //o fluido e o oleo
	
        cout<< "Escolha a propriedade que deseja calcular.Digite:\n" 
            << "[1] - Densidade do gas na superficie;\n"
	    << "[2] - Massa especifica;\n" 
            << "[3] - Fator volume formacao;\n"
	    << "[4] - Pressao de bolha;\n" 
	    << "[5] - Viscosidade do Oleo Morto;\n"
            << "[6] - Viscosidade do Oleo Sub-Saturado;\n" 
	    << "[7] - Viscosidade do Oleo Saturado;\n" 
	    << "[8] - Razao de Solubilidade;\n"  
            << "[9] - Compressibilidade;" << endl;	   
   
   int propriedadeOleoGas;
   
   cin>>propriedadeOleoGas;   cin.get();
   
   switch (propriedadeOleoGas)
   {  
     case 1: //a propriedade e a densidade do gas na superficie
       
       CFluidoOleoGas densidadeGasSup;
       
       densidadeGasSup.DensidadeGasSup();
       
       break;
       
     case 2: //a propriedade e a massa especifica
       
        cout << "Escolha o metodo pelo qual deseja calcular a massa especifica do Oleo.\n"
            << "Digite [1] - metodo proposto por McCain, Jr, W. and Hill, N.\n"
	    << "Digite [2] - metodo proposto por GE, Petrosky. & Farshad, F.\n"
	    << "Digite [3] - metodo proposto por Standing, M.B." << endl;
	   
	    int metodomassaespecifica;
	    
	    cin>> metodomassaespecifica;   cin.get();
	    
	    switch (metodomassaespecifica)
	    {
	      
	      case 1: //metodo de McCain Jr e Hill
		
		CMassaEspecifica_MH metodomassaespecificaMH;
		
		metodomassaespecificaMH.MassaEspecifica_MH();
		
		break;
		
	      case 2: //metodo de McCain Jr e Hill
		
		CMassaEspecifica_PF metodomassaespecificaPF;
		
		metodomassaespecificaPF.MassaEspecifica_PF();
		
		break;
		
	      case 3: //metodo de Standing et all
		
		CMassaEspecifica_ST metodomassaespecificaST;
		
		metodomassaespecificaST.MassaEspecifica_ST();
		
		break;
		
	    }
	    
	    break;
	      
	    
	 case 3: //se a propriedade e o fator volume formacao
	   
	   cout << "Escolha o metodo pelo qual deseja calcular o Fator Volume Formacao do Oleo.\n"
            << "Digite [1] - metodo apresentado por McCain, W.D. and Spivey, J.P. and Lenn, C.P.\n"
	    << "Digite [2] - metodo de Al-Marhoun, M.\n"
	    << "Digite [3] - metodo proposto por Petrosky, GE and Farshad, FF\n"
	    << "Digite [4] - metodo apresentado por Ahmed, T." << endl;
	    
	    int metodofatvolform;
	    
	    cin>> metodofatvolform;   cin.get();
	    
	    switch (metodofatvolform)
	    {
	      
	      case 1: //metodo de McCain, W.D. and Spivey, J.P. and Lenn, C.P.
		
		CFatorVolFormacao_AH metodofatvolformAH;
		
		metodofatvolformAH.FatorVolFormacao_AH();
		
		break;
		
	      case 2: //metodo de Al-Marhoun, M.
		
				
		CFatorVolFormacao_AM metodofatvolformAM;
		
		metodofatvolformAM.FatorVolFormacao_AM();
		
		break;
		
	      case 3: //metodo de Petrosky, GE and Farshad
		
		CFatorVolFormacao_GEF metodofatvolformGEF;
		
		metodofatvolformGEF.FatorVolFormacao_GEF();
		
		break;
		
	      case 4: //metodo de Ahmed, T
		
		CFatorVolFormacao_McC metodofatvolformMcC;
		
		metodofatvolformMcC.FatorVolFormacao_McC();
		
		break;
		
	    }
	    
	    break;
	    
	case 4: //se a propriedade e a pressao de bolha
		
	  cout << "Escolha o metodo pelo qual deseja calcular a Pressao de Bolha do Oleo.\n"
            << "Digite [1] - metodo apresentado por Standing, M.B.\n"
	    << "Digite [2] - metodo de Valko." << endl;
	    
	    int metodopb;
	    
	    cin>> metodopb;   cin.get();
	    
	    switch (metodopb)
	    {
	      
	      case 1: //metodo de Standing, M.B.
		
		CPressaoBolha_SM metodopbSM;
		
		metodopbSM.PressaoBolha_SM();
		
		break;
		
	      case 2: //metodo de Valko
		
		CPressaoBolha_VA metodopbVA;
		
		metodopbVA.PressaoBolha_VA();
		
		break;
		
	    }
	    
	    break;
	    
	case 5: //se a propriedade e a viscosidade do oleo morto
	  
	  cout << "Escolha o metodo pelo qual deseja calcular a Viscosidade do Oleo Morto.\n"
               << "Digite [1] - metodo de Beggs, HD and Robinson, JR.\n"
	       << "Digite [2] - metodo de Glaso, O." << endl;
	       
	       int metodoviscosidadedoOleoMorto;
	       
	       cin>> metodoviscosidadedoOleoMorto;   cin.get();
	       
	       switch (metodoviscosidadedoOleoMorto)
	       {
		 
		 case 1: //metodo de Beggs, HD and Robinson, JR.
		   
		   CViscosidadeOleoMorto_BR metodoviscosidadedoOleoMortoBR;
		   
		   metodoviscosidadedoOleoMortoBR.ViscosidadeOleoMorto_BR();
		   
		   break;
		   
		 case 2: //metodo de Glaso, O.
		   
		   CViscosidadeOleoMorto_G metodoviscosidadedoOleoMortoG;
		   
		   metodoviscosidadedoOleoMortoG.ViscosidadeOleoMorto_G();
		   
		   break;
		   
	       }
	       
	       break;
	       
	case 6: //se a propriedade e a viscosidade do oleo subsaturado
	  
	 cout << "Escolha o metodo pelo qual deseja calcular a Viscosidade do Oleo Sub-Saturado.\n"
               << "Digite [1] - metodo apresentado por Petrosky, G.E and Farshad, F.F.\n"
	       << "Digite [2] - metodo de Vazquez, M. and Beggs, H.D." << endl;
	       
	       int metodoviscosidadedoOleoSubSat;
	       
	       cin>> metodoviscosidadedoOleoSubSat;   cin.get();
	       
	       switch (metodoviscosidadedoOleoSubSat)
	       {
		 
		 case 1: //metodo apresentado por Petrosky, G.E and Farshad, F.F.
		   
		   CViscosidadeOleoSubSat_PF metodoviscosidadedoOleoSubSatPF;
		   
		   metodoviscosidadedoOleoSubSatPF.ViscosidadeOleoSubSat_PF();
		   
		   break;
		   
		 case 2: //metodo de Vazquez, M. and Beggs, H.D.
		   
		   CViscosidadeOleoSubSat_VB metodoviscosidadedoOleoSubSatVB;
		   
		   metodoviscosidadedoOleoSubSatVB.ViscosidadeOleoSubSat_VB();
		   
		   break;
		   
	       }
	       
	       break;
	       
	case 7: //se a propriedade e a viscosidade do oleo saturado
	  
	  cout << "Escolha o metodo pelo qual deseja calcular a Viscosidade do Oleo Saturado.\n"
               << "Digite [1] - metodo de Beggs, HD and Robinson, JR.\n"
	       << "Digite [2] - metodo  de Abu-Khamsin, A. and Al-Marhoun,M." << endl;
		
	    int metodoviscosidadedoOleoSat;
	    
	    cin>> metodoviscosidadedoOleoSat;   cin.get();
	    
	    switch (metodoviscosidadedoOleoSat)
	    {
	      
	      case 1: //metodo de Beggs, HD and Robinson, JR.
		
		CViscosidadeOleoSat_BR metodoviscosidadedoOleoSatBR;
		
		metodoviscosidadedoOleoSatBR.ViscosidadeOleoSat_BR();
		
		break;
		
	      case 2: //metodo  de Abu-Khamsin, A. and Al-Marhoun,M.
		
		CViscosidadeOleoSat_AKM metodoviscosidadedoOleoSatAKM;
		
		metodoviscosidadedoOleoSatAKM.ViscosidadeOleoSat_AKM();
		
		break;
		
	    }
	    
	    break;
	    
	case 8: //se a propriedade e a razao de solubilidade
		
	  cout << "Escolha o metodo pelo qual deseja calcular a Razao de Solubilidade do Oleo.\n"
               << "Digite [1] - metodo de Petrosky, G. E., and F. Farshad\n"
	       << "Digite [2] - metodo  de Vazquez, M. and Beggs, H.D." << endl;
	       
	       int metodorazaosolubilidade;
	       
	       cin>> metodorazaosolubilidade;   cin.get();
	       
	       switch (metodorazaosolubilidade)
	       {
		 
		 case 1: //metodo de Petrosky, G. E., and F. Farshad
		   
		   CRazaoSolubilidade_PF metodorazaosolubilidadePF;
		   
		   metodorazaosolubilidadePF.RazaoSolubilidade_PF();
		   
		   break;
		   
		 case 2: //metodo  de Vazquez, M. and Beggs, H.D.
		   
		   CRazaoSolubilidade_VB metodorazaosolubilidadeVB;
		   
		   metodorazaosolubilidadeVB.razaoSolubilidade_VB();
		   
		   break;
		   
	       }
	       
	       break;
	       
	case 9: //se a propriedade e a compressibilidade do oleo
	  
	  cout << "Escolha o metodo pelo qual deseja calcular a Compressibilidade do Oleo.\n"
               << "Digite [1] - metodo de Spivey, John and Valko, Peter and McCain, William - Para pressoes maiores que a pressao de bolha.\n"
	       << "Digite [2] - metodo  de Whitson, C.H. and Brulé, M.R. - Para pressoes maiores que a pressao de bolha.\n"
	       << "Digite [3] - metodo de McCainJr, W. and Rollins, J. and Lanzi, Alejandro, J. - Para pressoes menores que a pressao de bolha." << endl;
	      
	  int metodocompressibilidade;
	  
	  cin>> metodocompressibilidade;   cin.get();
	  
	  switch (metodocompressibilidade)
	  {
	    
	    case 1: //metodo de Spivey, John and Valko, Peter and McCain, William
	      
	      CCompressibilidadeMaiorPB_Setal metodocompressibilidademaiorPB_Setal;
	      
	      metodocompressibilidademaiorPB_Setal.CompressibilidadeMaiorPB_Setal();
	      
	      break;
	      
	    case 2: //metodo  de Whitson, C.H. and Brulé, M.R.
	      
	      CCompressibilidadeMaiorPB_WB metodocompressibilidademaiorPB_WB;
	      
	      metodocompressibilidademaiorPB_WB.CompressibilidadeMaiorPB_WB();
	      
	      break;
	      
	    case 3: //metodo de McCainJr, W. and Rollins, J. and Lanzi, Alejandro, J. 
	      
	      CCompressibilidadeMenorPB metodocompressibilidademenorPB;
	      
	      metodocompressibilidademenorPB.CompressibilidadeMenorPB();
	      
	      break;
	      
	  }
	  
	  break;
   }

   break;
   
     
  }
     //permite ao usuario escolher entre um novo calculo e o termino do programa
     cout<<"Deseja realizar um novo calculo? Se sim digite [1] e se nao digite [2].";
     cin>>resp;
     
	      
  }while(resp==1);
  
    
  return 0;
}

