#ifndef __UTILIZADOR__
#define __UTILIZADOR__

/**
@file utilizador.h
Utilizador do projeto.
*/

#include "date.h"
#include "posts.h"
#include <glib.h>

typedef struct utilizador * UTILIZADOR;

/**
\brief Função que cria uma estrutura UTILIZADOR.

@returns Estrutura inicializada de UTILIZADOR.
*/

UTILIZADOR create_utilizador();

/**
\brief Função que recebe uma estrutura UTILIZADOR e retorna o ID do utilizador.

@param p Estrutura UTILIZADOR.

@returns ID do utilizador da estrutura recebida.
*/

long get_key_id(UTILIZADOR u);

/**
\brief Função que recebe uma estrutura UTILIZADOR e retorna o nome do utilizador.

@param p Estrutura UTILIZADOR.

@returns Nome do utilizador.
*/

gchar* get_nome(UTILIZADOR u);

/**
\brief Função que recebe uma estrutura UTILIZADOR e retorna a biografia do utilzador.

@param p Estrutura UTILIZADOR.

@returns Biografia do utilzador .
*/

gchar* get_bio_utilizador(UTILIZADOR u);

/**
\brief Função que recebe uma estrutura UTILIZADOR e retorna uma lista com os ID's dos posts frequentados pelo utilizador.

@param p Estrutura UTILIZADOR.

@returns lista com os ID's dos posts frequentados pelo utilizador.
*/

GList* get_posts_frequentados(UTILIZADOR u);

/**
\brief Função que recebe uma estrutura UTILIZADOR e retorna uma lista com os IDs das perguntas que ele fez.

@param p Estrutura UTILIZADOR.

@returns IDs das perguntas da estrutura recebida.
*/

GList* get_posts_perguntas(UTILIZADOR u);

/**
\brief Função que recebe uma estrutura UTILIZADOR e retorna o nº de posts feitos pelo utilizador.

@param p Estrutura UTILIZADOR.

@returns Nº de posts feitos pelo utilizador.
*/

long get_posts_u(UTILIZADOR u);

/**
\brief Função que recebe uma estrutura UTILIZADOR e retorna a reputação do utilizador.

@param p Estrutura UTILIZADOR.

@returns reputação do utilizador.
*/

long get_reputacao(UTILIZADOR u);

/**
\brief Função que acede a uma estrutura UTILIZADOR e coloca o ID do utilizador.

@param u Utilizador.
@param key_id ID do utilizador.
*/

void set_key_id(UTILIZADOR u, int key_id);

/**
\brief Função que acede a uma estrutura UTILIZADOR e coloca o nome do utilizador.

@param u Utilizador.
@param str Nome do utilizador.
*/


void set_nome(UTILIZADOR u, char* str);

/**
\brief Função que acede a uma estrutura UTILIZADOR e coloca a bio do utilizador.

@param u Utilizador.
@param str Bio do utilizador.
*/


void set_bio(UTILIZADOR u, char* str);

/**
\brief Função que acede a uma estrutura UTILIZADOR e coloca o nº de posts frequentados do utilizador.

@param u Utilizador.
@param value Nº de posts frequentados.
*/


void set_posts_frequentados(UTILIZADOR u, long value);

/**
\brief Função que acede a uma estrutura UTILIZADOR e coloca as perguntas feitas pelo utilizador.

@param u Utilizador.
@param value Perguntas do utilizador.
*/


void set_posts_perguntas(UTILIZADOR u, POSTS value);

/**
\brief Função que acede a uma estrutura UTILIZADOR e coloca o nº de posts totais do utilizador.

@param u Utilizador.
@param posts_u ID do utilizador.
*/


void set_posts_u(UTILIZADOR u, int posts_u);

/**
\brief Função que acede a uma estrutura UTILIZADOR e coloca a reputação do utilizador.

@param u Utilizador.
@param reputacao Reputação do utilizador.
*/


void set_reputacao(UTILIZADOR u, int reputacao);

/**
\brief Função que recebe uma estrutura UTILIZADOR e liberta a memória alocada por esta.

@param u Utilizador.
*/


void free_utilizador(UTILIZADOR u);
#endif
