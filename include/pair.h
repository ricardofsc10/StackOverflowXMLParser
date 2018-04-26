#ifndef __PAIR_H__
#define __PAIR_H__

/**
@file pair.h
Funções do projeto sobre pares.
*/

typedef struct str_pair* STR_pair;


/**
\brief Função que recebe um inteiro e cria uma Long List com esse tamanho.

@param size Tamanho da lista.

@returns Long List com o tamanho desejado.
*/

STR_pair create_str_pair(char* fst, char* snd);



void set_fst_str(STR_pair pair, char* str);
void set_snd_str(STR_pair pair, char* str);
char* get_fst_str(STR_pair pair);
char* get_snd_str(STR_pair pair);
void free_str_pair(STR_pair pair);

// LONG_pair definitions
typedef struct long_pair* LONG_pair;

LONG_pair create_long_pair(long fst, long snd);
void set_fst_long(LONG_pair pair, long l);
void set_snd_long(LONG_pair pair, long l);
long get_fst_long(LONG_pair pair);
long get_snd_long(LONG_pair pair);
void free_long_pair(LONG_pair pair);

#endif
