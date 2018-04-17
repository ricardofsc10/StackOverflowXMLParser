#ifndef __LOAD__
#define __LOAD__

/**
@brief Função que filtra as datas, transformando-as em elementos da struct date.

@param data Data que vai ser transformada.

@returns Data compatível com a struct date.
*/

Date stringToDias (char* data);

void strToTag (POSTS value_post, char* str);

/**
@brief Função que diz se um id esta contido numa lista de id's.

@param l Lista onde se vai encontrar ou não o elemento.
@param id Parâmetro de comparação
@param N Tamanho da lista l.

@returns Data compatível com a struct date.
*/

int myelem (int* l, int id, int N);

/**
@brief Função que filtra os dados que são necessários do documento Users.xml 
e coloca nos campos da estrutura.

@param doc Documento Users.xml.
@param cur Raiz do documento.
@param com Estrutura onde vao ser inseridos os dados.

@returns Estrutura com os dados referentes a cada utilizador.
*/


void getReferenceUser (xmlDocPtr doc, xmlNodePtr cur, TAD_community com);

/**
@brief Função que filtra os dados que são necessários do documento Posts.xml 
e coloca nos campos da estrutura.

Utiliza a função <b>Hash()</b>, para a descobrir em que posição do
array está o criador do post.

@param doc Documento Posts.xml.
@param cur Raiz do documento.
@param com Estrutura onde vao ser inseridos os dados.

@returns Estrutura com os dados referentes a cada post no seu devido campo.
*/

void getReferencePosts (xmlDocPtr doc, xmlNodePtr cur, TAD_community com);

/**
@brief Função que filtra os dados que são necessários do documento Votes.xml 
e coloca nos campos da estrutura.

Utiliza a função <b>Hash()</b>, para a descobrir em que posição do
array está o criador do post.

@param doc Documento Votes.xml.
@param cur Raiz do documento.
@param com Estrutura onde vao ser inseridos os dados.

@returns Estrutura com os votos referentes a cada post.
*/

void getReferenceVotes (xmlDocPtr doc, xmlNodePtr cur, TAD_community com);

/**
@brief Função que filtra os dados que são necessários do documento Tags.xml 
e coloca nos campos da estrutura.

@param doc Documento Tags.xml.
@param cur Raiz do documento.
@param com Estrutura onde vao ser inseridos os dados.

@returns Estrutura com as tags referentes a cada post.
*/

void getReferenceTags (xmlDocPtr doc, xmlNodePtr cur, TAD_community com);

/**
@brief Função que realiza todo o processo de parsing dos documentos.

Utiliza as funções <b>strcpy()</b> e <b>strcat()</b> definidas na biblioteca
<b>stdlib.h</b> para colocar no caminho recebido como parâmetro o nome do
documento necessário.

Realiza vários testes para o caso de ocorrências de erros no carregamento de 
de algum documento ou erros na atribuição da raiz do documento às variáveis 
<b>cur_</b>

@param com Estrutura inicializada.
@param dump_path Contém o caminho para a pasta que contém os documentos .xml.

@returns Estrutura totamente carregada com os dados filtrados de cada ficheiro.
*/

TAD_community load(TAD_community com, char* dump_path);  //diretoria onde estarão os ficheiros do dump

#endif