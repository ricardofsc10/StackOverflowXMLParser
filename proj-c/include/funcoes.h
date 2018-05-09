#ifndef __FUNCOES__
#define __FUNCOES__


/**
@file funcoes.h
Funcções auxiliares do projeto.
*/

#include "date.h"
#include "list.h"
#include "tcd.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <interface.h>
#include <math.h>

/**
\brief Função que verifica se uma data se encontra ou não entre um período.

@param x Data usada para comparar
@param begin Data do ínicio da comparação.
@param end Data do fim da comparação.

@returns Inteiro que conclui se a data em questão se encontra no período correspondente.
*/
int difDatas(Date x,Date begin, Date end);

/** 
\brief Função que compara duas strings e devolve um inteiro que corresponde à diferença entre elas.

@param a Pointer para a string a.
@param b Pointer para a string b.

@returns Inteiro que corresponde à diferença.
*/

gint compara_strings(gconstpointer a, gconstpointer b);

/** 
\brief Função que compara dois scores e devolve um inteiro que corresponde à diferença entre eles.

@param a Pointer para o score a.
@param b Pointer para o score b.

@returns Inteiro que corresponde à diferença.
*/


gint compara_score(gconstpointer a, gconstpointer b);

/** 
\brief Função que compara duas respostas e devolve um inteiro que corresponde à diferença entre elas.

@param a Pointer para a resposta a.
@param b Pointer para a resposta b.

@returns Inteiro que corresponde à diferença.
*/


gint compara_answer(gconstpointer a, gconstpointer b);

/** 
\brief Função que compara dois posts e devolve um inteiro que corresponde à diferença entre eles.

@param a Pointer para o post a.
@param b Pointer para o post b.

@returns Inteiro que corresponde à diferença.
*/


gint compara_posts_u(gconstpointer a, gconstpointer b);

/** 
\brief Função que compara duas reputações e devolve um inteiro que corresponde à diferença entre elas.

@param a Pointer para a reputação a.
@param b Pointer para a reputação b.

@returns Inteiro que corresponde à diferença.
*/


gint compara_reputacao(gconstpointer a, gconstpointer b);

/** 
\brief Função que compara duas ocorrências e devolve um inteiro que corresponde à diferença entre elas.

@param a Pointer para a ocorrência a.
@param b Pointer para a ocorrência b.

@returns Inteiro que corresponde à diferença.
*/


gint compara_ocorrencias(gconstpointer a, gconstpointer b);

/** 
\brief Função que liberta a memória alocada para um utilizador.

@param key Chave.
@param value ID do utilizador.
@param user_data Dados do utilizador.
*/


void free_table_utilizador(gpointer key, gpointer value, gpointer user_data);

/** 
\brief Função que liberta a memória alocada para um post.

@param key Chave.
@param value ID do utilizador.
@param user_data Dados do utilizador.
*/


void free_table_posts(gpointer key, gpointer value, gpointer user_data);

/** 
\brief Função que liberta a memória alocada para uma tag.

@param key Chave.
@param value ID do utilizador.
@param user_data Dados do utilizador.
*/


void free_table_tag(gpointer key, gpointer value, gpointer user_data);

/** 
\brief Função que liberta a memória alocada para uma tag.

@param key Chave.
@param value ID do utilizador.
@param user_data Dados do utilizador.
*/


void free_table_tu(gpointer key, gpointer value, gpointer user_data);

/**
@brief Função que filtra as datas, transformando-as em elementos da struct date.

@param data Data que vai ser transformada.

@returns Data compatível com a struct date.
*/
Date stringToDias (char* data);

/**
@brief Função que transforma uma string numa tag, e insere numa GList de tags 
correspondente a cada post que seja pergunta.

@param value_post Post ao qual corresponde a tag..
@param str String a transformar
*/

void strToTag (POSTS value_post, const char* str);

/**
@brief Função que retira todos os valores que nao interessam à lista, que são 
todos os valores igual a 0.

@param l Lista a ser transformada
@param N Tamanho da lista.

@returns Uma lista apenas com os valores importantes.
*/

LONG_list remove_trash(LONG_list l, int N);

/**
@brief Função que é utilizada no processo interativo, que permite ao utilizador 
que está a correr o programa decidir qual dos ficheiros a estrutura deve carregar 
para memória.

@returns O caminho relativo para o ficheiro escolhido.
*/

char* escolhe_ficheiros();

/**
@brief Função que é utilizada no processo interativo, que permite ao utilizador 
que está a correr o programa introduzir a data na qual os posts da estrutura serão 
avaliados.

@returns A data definida na estrutura Date.
*/

Date pergunta_data();

/**
@brief Função que é utilizada no processo interativo, que permite ao utilizador 
que está a correr o programa inserir e interagir com o programa, de modo a dizer-lhe 
qual pergunta deseja executar, com os parâmetros que quiser.
*/

void interatividade(TAD_community tda);

#endif