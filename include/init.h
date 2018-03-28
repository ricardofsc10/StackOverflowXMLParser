#ifndef __INIT__
#define __INIT__

/**
@file init.h
@author Grupo21
@brief Ficheiro que contém funções de inicialização de memória, para a estrutura usada.
*/


/**
@brief Função que faz a primeira inicialização da estrutura.

Inicializa cada parâmetro da estrutura definida em 

@returns Estrutura TAD_community inicializada.
*/
TAD_community init();


/**
@brief Função utilizada para redimensionar a estrutura dos utilizadores quando esta se encontra sem espaço.

Usa o <b>realloc()</b> que está definido na biblioteca <b>stdlib.h</b>, para realocar mais memória 
para que possam ser inseridos mais utilizadores, sem perder a informação 
que ja la estava.

Inicializa os campos da estrutura relativos ao novo espaço alocado.

@param com Estrutura onde será alocada memória.

@returns Estrutura com os mesmos dados, mas com mais espaço.
*/
void redimensiona_utilizadores(TAD_community com);


/**
@brief Função utilizada para redimensionar a estrutura dos posts quando esta se encontra sem espaço.

Usa o <b>realloc()</b> que está definido na biblioteca <b>stdlib.h</b>, para realocar mais memória 
para que possam ser inseridos mais posts, sem perder a informação 
que ja la estava.

Inicializa os campos da estrutura relativos ao novo espaço alocado.

@param com Estrutura onde será alocada memória.

@returns Estrutura com os mesmos dados, mas com mais espaço.
*/
void redimensiona_posts(TAD_community com);

#endif