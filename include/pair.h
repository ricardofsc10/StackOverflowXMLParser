#ifndef __PAIR_H__
#define __PAIR_H__

/**
@file pair.h
Funções do projeto sobre pares.
*/

typedef struct str_pair* STR_pair;


/**
\brief Função que recebe 2 strings e cria um par de strings.

@param fst Primeira string.
@param snd Segunda string.

@returns Um par de strings.
*/

STR_pair create_str_pair(char* fst, char* snd);

/**
\brief Função que recebe um STR_pair e uma string e coloca na primeira posição a string recebida.

@param pair Par de strings.
@param str String a colocar.

*/

void set_fst_str(STR_pair pair, char* str);

/**
\brief Função que recebe um STR_pair e uma string e coloca na segunda posição a string recebida.

@param pair Par de strings.
@param str String a colocar.

*/

void set_snd_str(STR_pair pair, char* str);

/**
\brief Função que recebe um STR_pair e devolve a primeira string.

@param pair Par de strings.

@returns String da primeira posição.
*/


char* get_fst_str(STR_pair pair);

/**
\brief Função que recebe um STR_pair e devolve a segunda string.

@param pair Par de strings.

@returns String da segunda posição.
*/

char* get_snd_str(STR_pair pair);

/**
\brief Função que recebe um STR_pair e liberta a memória alocada por esta.

@param pair Par de strings.
*/

void free_str_pair(STR_pair pair);

// LONG_pair definitions
typedef struct long_pair* LONG_pair;

/**
\brief Função que recebe 2 long's e cria um par.

@param fst Primeiro long.
@param snd Segunda long.

@returns Um par de long's.
*/


LONG_pair create_long_pair(long fst, long snd);

/**
\brief Função que recebe um LONG_pair e um long e coloca na primeira posição o long recebido.

@param pair Par de long's.
@param l Long a colocar.

*/

void set_fst_long(LONG_pair pair, long l);

/**
\brief Função que recebe um LONG_pair e um long e coloca na segunda posição o long recebido.

@param pair Par de long's.
@param l Long a colocar.

*/

void set_snd_long(LONG_pair pair, long l);

/**
\brief Função que recebe um LONG_pair e devolve a primeira posição.

@param pair Par de long's.

@returns Long da primeira posição.
*/

long get_fst_long(LONG_pair pair);

/**
\brief Função que recebe um LONG_pair e devolve a segunda posição.

@param pair Par de long's.

@returns Long da segunda posição.
*/

long get_snd_long(LONG_pair pair);

/**
\brief Função que recebe um LONG_pair e liberta a memória alocada por este.

@param pair Par de long's.
*/

void free_long_pair(LONG_pair pair);

#endif
