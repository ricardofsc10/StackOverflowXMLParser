#ifndef __POSTS__
#define __POSTS__

/**
@file posts.h
Posts do projeto.
*/

#include "date.h"
#include "common.h"
#include <glib.h>

typedef struct posts* POSTS;


/**
@brief Função que cria uma estrutura POSTS.

@returns Estrutura inicializada de POSTS.
*/

POSTS create_posts();

/**
@brief Função que recebe uma estrutura POSTS e retorna a key_id_post.

@param p Estrutura POSTS.

@returns key_id_post da estrutura recebida.
*/

long get_key_id_post(POSTS p);

/**
@brief Função que recebe uma estrutura POSTS e retorna a Data em formato Date.

@param p Estrutura POSTS.

@returns Data da estrutura recebida.
*/

Date get_data(POSTS p);

/**
@brief Função que recebe uma estrutura POSTS e retorna a data em formato gchar*.

@param p Estrutura POSTS.

@returns Data da estrutura recebida.
*/

gchar* get_data_string(POSTS p);

/**
@brief Função que recebe uma estrutura POSTS e retorna o score do post.

@param p Estrutura POSTS.

@returns Score do post.
*/

long get_score(POSTS p);

/**
@brief Função que recebe uma estrutura POSTS e retorna o ID do utilizador que fez o post.

@param p Estrutura POSTS.

@returns ID do utilizador.
*/

long get_owner_user_id(POSTS p);

/**
@brief Função que recebe uma estrutura POSTS e retorna o título do post.

@param p Estrutura POSTS.

@returns Título do post.
*/

gchar* get_title(POSTS p);

/**
@brief Função que recebe uma estrutura POSTS e retorna o corpo da pergunta.

@param p Estrutura POSTS.

@returns Corpo da pergunta.
*/

gchar* get_body(POSTS p);

/**
@brief Função que recebe uma estrutura POSTS e retorna o tipo de post.

@param p Estrutura POSTS.

@returns Tipo do post recebido.
*/

int get_post_type_id(POSTS p);

/**
@brief Função que recebe uma estrutura POSTS e retorna o ID do pai, ou seja da pergunta à qual corresponde.

@param p Estrutura POSTS.

@returns ID da pergunta a que se refere.
*/

long get_parent_id(POSTS p);

/**
@brief Função que recebe uma estrutura POSTS e retorna uma lista com as Tags da pergunta.

@param p Estrutura POSTS.

@returns Lista das tags.
*/

GList* get_tags(POSTS p);
<<<<<<< Updated upstream
=======

/**
@brief Função que recebe uma estrutura POSTS e retorna o número de respostas à pergunta.

@param p Estrutura POSTS.

@returns Número de respostas da pergunta.
*/

long get_answer_count(POSTS p);

/**
@brief Função que recebe uma estrutura POSTS e retorna o número de comentários.

@param p Estrutura POSTS.

@returns Nº de comentários da resposta.
*/

>>>>>>> Stashed changes
long get_comment_count(POSTS p);

/**
@brief Função que recebe uma estrutura POSTS e coloca uma key_id_post.

@param p Estrutura POSTS.
*/

void set_key_id_post(POSTS p, int key_id_post);

/**
@brief Função que recebe uma estrutura POSTS e coloca uma data em formato Date.

@param p Estrutura POSTS.
*/

void set_data(POSTS p, Date data);

/**
@brief Função que recebe uma estrutura POSTS e coloca uma data em formato String.

@param p Estrutura POSTS.
*/

void set_data_string(POSTS p, char* str);

/**
@brief Função que recebe uma estrutura POSTS e coloca um score.

@param p Estrutura POSTS.
*/

void set_score(POSTS p, int score);

/**
@brief Função que recebe uma estrutura POSTS e coloca um ID de utilizador.

@param p Estrutura POSTS.
*/

void set_owner_user_id(POSTS p, int owner_user_id);

/**
@brief Função que recebe uma estrutura POSTS e coloca um título.

@param p Estrutura POSTS.
*/

void set_title(POSTS p, char* str);

/**
@brief Função que recebe uma estrutura POSTS e coloca um corpo de texto.

@param p Estrutura POSTS.
*/

void set_body(POSTS p, char* str);

/**
@brief Função que recebe uma estrutura POSTS e coloca o post_type_id.

@param p Estrutura POSTS.
*/

void set_post_type_id(POSTS p, int post_type_id);

/**
@brief Função que recebe uma estrutura POSTS e coloca o ID do pai do post.

@param p Estrutura POSTS.
*/

void set_parent_id(POSTS p, int parent_id);

/**
@brief Função que recebe uma estrutura POSTS e coloca as tags da pergunta.

@param p Estrutura POSTS.
*/

void set_tags(POSTS p, char* str);
<<<<<<< Updated upstream
=======

/**
@brief Função que recebe uma estrutura POSTS e coloca o número de respostas.

@param p Estrutura POSTS.
*/

void set_answer_count(POSTS p, int answer_count);

/**
@brief Função que recebe uma estrutura POSTS e coloca o número de comentários.

@param p Estrutura POSTS.
*/

>>>>>>> Stashed changes
void set_comment_count(POSTS p, int comment_count);

/**
@brief Função que liberta a memória alocada por uma estrutura POSTS.

@param p Estrutura POSTS.
*/

void free_posts(POSTS p);
#endif
