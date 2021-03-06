#if ! defined( LISTA_ )
#define LISTA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: LIS  Lista duplamente encadeada
*
*  Arquivo gerado:              LISTA.h
*  Letras identificadoras:      LIS
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor        Data          Observa��es
*     5       lp,ja, tb 28/nov/2016   altera��o de fun��es e edi��o do scrpit de teste
*     4       avs       01/fev/2006   criar linguagem script simb�lica
*     3       avs       08/dez/2004	  uniformiza��o dos exemplos
*     2       avs       07/jul/2003	  unifica��o de todos os m�dulos em um s� projeto
*     1       avs       16/abr/2003	  in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Implementa listas gen�ricas duplamente encadeadas.
*     Podem existir n listas em opera��o simultaneamente.
*     As listas possuem uma cabe�a encapsulando o seu estado.
*
*     Cada lista � homog�nea quanto ao tipo dos dados que armazena.
*     Cada elemento da lista referencia o valor que cont�m.
*
*     Os ponteiros para os dados s�o copiados para elementos da lista.
*        N�o � copiado o valor apontado por estes ponteiros.
*
*     O controle da destrui��o do valor de um elemento a ser exclu�do
*        � realizado por uma fun��o fornecida pelo usu�rio.
*
*     Cada lista referencia uma fun��o que determina como devem ser
*        desalocados os dados nela contidos.
*
*     A fun��o de libera��o dos valores contidos nos elementos deve
*        assegurar a libera��o de todos os espa�os refer�nciados pelo
*        valor contido em um elemento.
*        Esta fun��o � chamada antes de se desalocar um elemento
*        de uma lista.
*        Caso n�o seja necess�rio desalocar o valor referenciado pelo
*        elemento, o ponteiro para a fun��o de libera��o poder� ser NULL .
*        Caso o elemento da lista seja a �nica �ncora do valor referenciado,
*        esta fun��o deve promover a destrui��o (free) desse valor e
*        de todos os dados nele ancorados.
*
***************************************************************************/
 
#if defined( LISTA_OWN )
   #define LISTA_EXT
#else
   #define LISTA_EXT extern
#endif

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef struct LIS_tagLista * LIS_tppLista ;


/***********************************************************************
*
*  $TC Tipo de dados: LIS Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es da lista
*
***********************************************************************/

   typedef enum {

         LIS_CondRetOK ,
               /* Concluiu corretamente */

         LIS_CondRetListaVazia = 2 ,
               /* A lista n�o cont�m elementos */

         LIS_CondRetListaNaoExiste,
               /* Lista n�o existe */

         LIS_CondRetFimLista ,
               /* Foi atingido o final da lista */

		 LIS_CondRetInicioLista,
			   /*Foi atingido o in�cio da lista */

         LIS_CondRetFaltouMemoria
               /* Faltou mem�ria ao tentar criar um elemento de lista */

   } LIS_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Criar lista
*
*  $ED Descri��o da fun��o
*     Cria uma cabe�a de lista gen�rica duplamente encadeada.
*     Os poss�veis tipos s�o desconhecidos a priori.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     pLista        - ponteiro de ponteiro para a estrutura do tipo LIS_tpLista*
*					  a ser criada.
*
*     idLista       - string de identifica��o da lista
*
*
*  $FV Valor retornado
*     Se executou corretamente retorna a condi��o de retorno LIS_CondRetOK.
*     
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     LIS_CondRetFaltouMemoria.
*
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

   LIS_tpCondRet LIS_CriarLista(LIS_tppLista* pLista, char* idLista);

/***********************************************************************
*
*  $FC Fun��o: LIS  &Destruir lista
*
*  $ED Descri��o da fun��o
*     Destr�i a lista fornecida.
*     O par�metro ponteiro para a lista n�o � modificado.
*     Se ocorrer algum erro durante a destrui��o, a lista resultar�
*     estruturalmente incorreta.
*
*  $FV Valor retornado
*     LIS_CondRetOK                - destruiu sem problemas
*     LIS_CondRetListaNaoExiste    - lista nao existe
*
***********************************************************************/

   LIS_tpCondRet LIS_DestroiLista( LIS_tppLista pLista ) ;

/***********************************************************************
*
*  $FC Fun��o: LIS  &Obter Id
*
*  $ED Descri��o da fun��o
*     Obtem o Id contido dentro da cabe�a da Lista passada
*
*  $EP Par�metros
*     pLista  - ponteiro para a cabe�a a ser encontrado o Id
*	  idLista - ponteiro para identificacao da Id da lista
*
***********************************************************************/

   LIS_tpCondRet LIS_ObterId(LIS_tppLista *pLista, char *idLista);

/***********************************************************************
*
*  $FC Fun��o: LIS  &Esvaziar lista
*
*  $ED Descri��o da fun��o
*     Elimina todos os elementos, sem contudo eliminar a lista
*
*  $EP Par�metros
*     pLista - ponteiro para a lista a ser esvaziada
*
***********************************************************************/

   void LIS_EsvaziarLista( LIS_tppLista pLista ) ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Inserir No
*
*  $ED Descri��o da fun��o
*     Insere novo elemento ap�s o elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Par�metros
*     Par�metros
*        pLista - ponteiro para a lista onde deve ser inserido o elemento
*        pValor - ponteiro para o valor do novo elemento
*                 Pode ser NULL
*           
*
*  $FV Valor retornado
*     Valor retornado
*        LIS_CondRetOK
*        LIS_CondRetFaltouMemoria
*
***********************************************************************/

   LIS_tpCondRet LIS_InserirNo( LIS_tppLista pLista ,
                                          void * pValor        )
       ;


/***********************************************************************
*
*  $FC Fun��o: LIS  &Excluir no corrente
*
*  $ED Descri��o da fun��o
*     Exclui o elemento do no corrente da lista dada.
*     Se existir o elemento aa esquerda do corrente ser� o novo corrente.
*     Se n�o existir e existir o elemento � direita, este se tornar� corrente.
*     Se este tamb�m n�o existir a lista tornou-se vazia.
*
*  $EP Par�metros
*     pLista    - ponteiro para a lista na qual deve excluir.
*
*  $FV Valor retornado
*     LIS_CondRetOK
*     LIS_CondRetListaVazia
*
***********************************************************************/

   LIS_tpCondRet LIS_ExcluirNoCorrente(LIS_tppLista pLista);


/***********************************************************************
*
*  $FC Fun��o: LIS  &Obter refer�ncia para o caracter contido no elemento
*
*  $ED Descri��o da fun��o
*     Obtem a refer�ncia para o caracter contido no elemento corrente da lista
*
*  $EP Par�metros
*     pLista     - ponteiro para a lista de onde se quer o valor
*     CharObtido - refer�ncia para o char a ser passado pela fun��o
*
*  $FV Valor retornado
*     LIS_CondRetOK             - se o elemento corrente existe
*     LIS_CondRetListaVazia     - se a lista estiver vazia
*
***********************************************************************/

   LIS_tpCondRet LIS_ObterNo(LIS_tppLista pLista, void** pValor);

/***********************************************************************
*
*  $FC Fun��o: LIS  &AvancarElementoCorrente
*
*  $ED Descri��o da fun��o
*     Avan�a o elemento corrente um elemento na lista
*
*  $EP Par�metros
*     pLista  - ponteiro para a lista a ser manipulada
*
*  $FV Valor retornado
*     CondRetOK         - se um elemento tiver sido andado
*     CondRetFimLista   - se encontrou o fim da lista antes de andar um elemento
*     CondRetListaVazia - se a lista est� vazia
*
***********************************************************************/

   LIS_tpCondRet LIS_AvancarElementoCorrente(LIS_tppLista pLista);


/***********************************************************************
*
*  $FC Fun��o: LIS  &Voltar Elemento Corrente
*
*  $ED Descri��o da fun��o
*     Volta o elemento corrente um elemento na lista
*
*  $EP Par�metros
*     pLista  - ponteiro para a lista a ser manipulada
*
*  $FV Valor retornado
*     CondRetOK            - se um elemento tiver sido voltado
*     CondRetInicioLista   - se encontrou o inicio da lista antes de voltar um elemento
*     CondRetListaVazia    - se a lista est� vazia
*
***********************************************************************/

   LIS_tpCondRet LIS_VoltarElementoCorrente(LIS_tppLista pLista);

/***********************************************************************
*
*  $FC Fun��o: LIS  &Alterar no corrente
*
*  $ED Descri��o da fun��o
*     Altera o elemento o caracter contido no elemento corrente
*	  para o fornecido na fun��o
*
*  $EP Par�metros
*     pLista   - ponteiro para a lista a ser manipulada
*     CharDado - caracter fornecido
*
*  $FV Valor retornado
*     CondRetOK               - se o caracter for alterado com sucesso
*     CondRetListaNaoExiste   - se a lista n�o existe
*     CondRetListaVazia       - se a lista est� vazia
*
***********************************************************************/

   LIS_tpCondRet LIS_AlterarElementoCorrente(LIS_tppLista pLista, void* CharDado);

/***********************************************************************
*
*  $FC Fun��o: LIS  &Ir para o elemento inicial
*
*  $ED Descri��o da fun��o
*     Torna corrente o primeiro elemento da lista.
*     Faz nada se a lista est� vazia.
*
*  $EP Par�metros
*     pLista - ponteiro para a lista a manipular
*
***********************************************************************/

   LIS_tpCondRet IrInicioLista (LIS_tppLista pLista );

#undef LISTA_EXT

/********** Fim do m�dulo de defini��o: LIS  Lista duplamente encadeada **********/                 

#else
#endif
