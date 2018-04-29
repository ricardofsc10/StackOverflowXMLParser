#ifndef __TAG_UNIQUE__
#define __TAG_UNIQUE__

/**
@file tag_unique.h
Funções que trabalham uma tag do projeto e as suas ocorrências.
*/

#include <glib.h>

typedef struct tag_unique * TAG_UNIQUE;

/**
\brief Função que cria e inicializa uma estrutura TAG_UNIQUE.


@returns Uma estrutura TAG_UNIQUE.
*/

TAG_UNIQUE create_tag_unique();

/**
\brief Função que recebe uma estrutura TAG_UNIQUE e retorna o número de ocorrências dessa tag.

@param t Estrutura TAG_UNIQUE.

@returns Nº de ocorrências da tag.
*/

long get_ocorrencias(TAG_UNIQUE t);

/**
\brief Função que recebe uma estrutura TAG_UNIQUE e retorna o nome da tag.

@param t Estrutura TAG_UNIQUE.

@returns Nome da tag.
*/


gchar* get_key_tag_unique_name(TAG_UNIQUE t);

/**
\brief Função que recebe uma estrutura TAG_UNIQUE e um inteiro e coloca as ocorrências da tag.

@param t Estrutura TAG_UNIQUE.
@param incremento Inteiro com as ocorrências
*/


void set_ocorrencias(TAG_UNIQUE t, int incremento);


/**
\brief Função que recebe uma estrutura TAG_UNIQUE e uma string e coloca na estrutura a string.

@param t Estrutura TAG_UNIQUE.
@param str Nome da tag.
*/

void set_key_tag_unique_name(TAG_UNIQUE t, char* str);

/**
\brief Função que liberta a memória alocada por uma estrutura TAG_UNIQUE.

@param t Estrutura TAG_UNIQUE
*/
void free_tag_unique(TAG_UNIQUE t);
#endif