#ifndef __ANSWER_COUNT__
#define __ANSWER_COUNT__

/**
@file answer_count.h
Funções sobre o nº de respostas de uma pergunta do projeto.
*/

#include <glib.h>

typedef struct answer_count * ANSWER_COUNT;

/**
\brief Função que cria uma estrutura ANSWER_COUNT.

@returns Estrutura inicializada de ANSWER_COUNT.
*/


ANSWER_COUNT create_answer_count();

/**
\brief Função que recebe uma estrutura ANSWER_COUNT e retorna o número de respostas.

@param t Estrutura ANSWER_COUNT.

@returns Número de respostas da pergunta acedida.
*/


long get_num_respostas(ANSWER_COUNT t);

/**
\brief Função que recebe uma estrutura ANSWER_COUNT e retorna o ID da pergunta acedida.

@param t Estrutura ANSWER_COUNT.

@returns ID da pergunta acedida.
*/


long get_id_pergunta(ANSWER_COUNT t);

/**
\brief Função que recebe uma estrutura ANSWER_COUNT e um inteiro incremento e altera o número de respostas dessa pergunta.

@param t Estrutura ANSWER_COUNT.
@param incremento

*/


void set_num_respostas(ANSWER_COUNT t, int incremento);


/**
\brief Função que recebe uma estrutura ANSWER_COUNT e um long ID e coloca na estrutura o ID da pergunta.

@param t Estrutura ANSWER_COUNT.
@param id_l ID da pergunta

*/


void set_id_pergunta(ANSWER_COUNT t, long id_l);

/**
\brief Função que recebe uma estrutura ANSWER_COUNT e liberta a memória por esta alocada.

@param t Estrutura ANSWER_COUNT.
*/

void free_answer_count(ANSWER_COUNT t);

#endif