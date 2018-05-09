#ifndef __TAG__
#define __TAG__

/**
@file tag.h
Funções que trabalham sobre uma tag.
*/

#include <glib.h>

typedef struct tag * TAG;

/**
\@brief Função que cria a a estrutura associada a cada tag.

@returns Estrutura TAG.
*/

TAG create_tag();

/**
\brief Função que recebe uma estrutura de uma tag e retorna o seu nome.

@param t Estrutura TAG.

@returns Nome da tag em formato gchar*.
*/

gchar* get_key_tag_name(TAG t);

/**
\brief Função que recebe uma estrutura de uma tag e retorna o seu ID.

@param t Estrutura TAG.

@returns ID da tag.
*/

long get_id_tag(TAG t);

/**
\brief Função que recebe uma estrutura de uma tag e uma string com um nome e coloca na estrutura o nome da tag.

@param t Estrutura TAG.
@param str Nome da tag.
*/

void set_key_tag_name(TAG t, char* str);

/**
\brief Função que recebe uma estrutura de uma tag e um long com um ID e coloca na estrutura esse ID.

@param t Estrutura TAG.
@param id_tag ID da tag.
*/

void set_id_tag(TAG t, long id_tag);

/**
\brief Função que liberta a memória alocada por uma estrutura TAG.

@param t Estrutura TAG.
*/

void free_tag(TAG t);
#endif
