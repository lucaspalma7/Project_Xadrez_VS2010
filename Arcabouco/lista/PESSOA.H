#if ! defined( PESSOA_ )
#define PESSOA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: PES  Estrutura de uma Pessoa
*
*  Arquivo gerado:              PESSOA.h
*  Letras identificadoras:      PES
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\PESSOA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: Tauan Binato , Julia Aleixo , Lucas Palma
*
*  $ED Descri��o do m�dulo
*     Implementa uma estrutura de pessoa com nome e iniciais
*
*
***************************************************************************/
 
#if defined( PESSOA_OWN )
   #define PESSOA_EXT
#else
   #define PESSOA_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Estrutura de pessoa */

typedef struct infonome Infonome;

/***********************************************************************
*
*  $TC Tipo de dados: PES Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es
*
***********************************************************************/

   typedef enum {

         PES_CondRetOK ,
               /* Concluiu corretamente */

         PES_CondRetEstruturaVazia ,
               /* A lista n�o cont�m elementos */

         PES_CondRetFimEstrutura ,
               /* Foi atingido o fim de lista */

         PES_CondRetNaoAchou ,
               /* N�o encontrou o valor procurado */

         PES_CondRetFaltouMemoria,
               /* Faltou mem�ria ao tentar criar um elemento de lista */

		 PES_CondRetStringDiferente
			   /* Faltou mem�ria ao tentar criar um elemento de lista */

   } PES_tpCondRet ;

     /***********************************************************************
*
*  $FC Fun��o: &Criar Estrutura
*
*  $ED Descri��o da fun��o
*     Aloca dinamicamente uma nova estrutura inicializando suas entidades com null.
*
*  $EP Par�metros
*     pessoa    - ponteiro duplo para uma estrutura.
*                 
*
*  $FV Valor retornado
*     PES_CondRetOK   - criou corretamente
*	  PES_CondRet_FaltouMemoria  - Houve problema na aloca��o de memoria.
*      
***********************************************************************/

   PES_tpCondRet PES_Criar_Estrutura(Infonome **pessoa);

   /***********************************************************************
*
*  $FC Fun��o: &Preencher estrutura
*
*  $ED Descri��o da fun��o
*     Vai na estrutura de valor e preenche com os parametros de string.
*
*  $EP Par�metros
*     nome      - nome completo da pessoa
*     iniciais  - iniciais da mesma pessoa
*                 
*
*  $FV Valor retornado
*     PES_CondRetOK   - Preencheu corretamente
*	  PES_CondRet_FaltouMemoria  - Houve problema na aloca��o de memoria.
*      
***********************************************************************/

   PES_tpCondRet PES_preencher_estrutura(Infonome **pessoa,char *nome, char *iniciais);

   /***********************************************************************
*
*  $FC Fun��o: &Obter Valor Iniciais
*
*  $ED Descri��o da fun��o
*     Vai na estrutura retornando por referencia uma inicial.
*
*  $EP Par�metros
*     strIni      - ponteiro para string iniciais
*     pValor      - ponteiro para estrutura Infonome
*                 
*  $FV Valor retornado
*     PES_CondRetOK   - Obteve corretamente
*	  PES_CondRetEstruturaVazia  - Houve problema na aloca��o de memoria.
*      
***********************************************************************/
   PES_tpCondRet PES_ObterValorIniciais( char **strIni , Infonome *pValor );

/***********************************************************************
*
*  $FC Fun��o: &Obter Valor Nome
*
*  $ED Descri��o da fun��o
*     Vai na estrutura retornando por referencia um nome.
*
*  $EP Par�metros
*     strIni      - ponteiro para string nome
*     pValor      - ponteiro para estrutura Infonome
*                 
*  $FV Valor retornado
*     PES_CondRetOK   - Obteve corretamente
*	  PES_CondRetEstruturaVazia  - Houve problema na aloca��o de memoria.
*      
***********************************************************************/
   PES_tpCondRet PES_ObterValorNome( char **strNome , Infonome *pValor );

#undef PESSOA_EXT

/********** Fim do m�dulo de defini��o: LIS  Lista duplamente encadeada **********/

#else
#endif