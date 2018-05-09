#ifndef __LONG_LIST__
#define __LONG_LIST__

/**
@file list.h
Funções sobre List do projeto.
*/

typedef struct llist * LONG_list;

/**
\brief Função que recebe um inteiro e cria uma Long List com esse tamanho.

@param size Tamanho da lista.

@returns Long List com o tamanho desejado.
*/

LONG_list create_list(int size);

/**
\brief Função que recebe uma long list e um índice e retorna o número correspondente.

@param l Long list à qual vamos aceder.
@param index Índice da posição.

@returns Número que está nesse índice.
*/

long get_list(LONG_list l, int index);

/**
\brief Função que recebe uma long list, um índice e um valor e coloca nesse índice o valor.

@param l Long list à qual vamos aceder.
@param index Índice da posição.
@param value Valor.

*/

void set_list(LONG_list l, int index, long value);

/**
\brief Função que recebe uma long list e liberta a memória por esta ocupada .

@param l Long list à qual vamos aceder.

*/


void free_list(LONG_list l);
#endif
