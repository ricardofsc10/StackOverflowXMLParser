#ifndef __LOAD__
#define __LOAD__


/**
@file load.h
@author Grupo21
@brief Ficheiro que contém funções que filtram os dados dos ficheiros .xml para a estrutura já inicializada.
*/


/*
--- falta documentacao
*/
Date stringToDias (char* data);


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

Utiliza a função <b>procuraBinaria()</b>, para a descobrir em que posição do
array está o criador do post.

@param doc Documento Posts.xml.
@param cur Raiz do documento.
@param com Estrutura onde vao ser inseridos os dados.

@returns Estrutura com os dados referentes a cada post no seu devido campo.
*/
void getReferencePosts (xmlDocPtr doc, xmlNodePtr cur, TAD_community com);


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
TAD_community load(TAD_community com, char* dump_path);

#endif