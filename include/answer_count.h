#ifndef __ANSWER_COUNT__
#define __ANSWER_COUNT__

/**
@file answer_count.h
Funções sobre o nº de respostas de uma pergunta do projeto.
Contém uma pequena estrutura auxiliar denominada de answer_count.
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
@brief Função que recebe uma estrutura ANSWER_COUNT e retorna a o número de resposta associado.

@param t Estrutura ANSWER_COUNT.

@returns Um long associado ao número de respostas.
*/

long get_num_respostas(ANSWER_COUNT t);

/**
@brief Função que recebe uma estrutura ANSWER_COUNT e retorna a o Id da pergunta associado.

@param t Estrutura ANSWER_COUNT.

@returns Um long associado ao número de respostas.
*/

long get_id_pergunta(ANSWER_COUNT t);

/**
@brief Função que recebe uma estrutura ANSWER_COUNT e altera o número de respostas associado.

@param t Estrutura ANSWER_COUNT.
@param incremento Valor a adicionar ao corrente número de respostas.

@returns Um long associado ao número de respostas.
*/

void set_num_respostas(ANSWER_COUNT t, int incremento);

/**
@brief Função que recebe uma estrutura ANSWER_COUNT e altera o Id associado.

@param t Estrutura ANSWER_COUNT.
@param id_l Valor de Id a ser alterado na estrutura.

@returns Um long associado ao número de respostas.
*/

void set_id_pergunta(ANSWER_COUNT t, long id_l);

/**
@brief Função que liberta a memória alocada por uma estrutura ANSWER_COUNT.

@param t Estrutura ANSWER_COUNT.
*/

void free_answer_count(ANSWER_COUNT t);

#endif