#ifndef __TCD__
#define __TCD__

/**
@file tag_unique.h
Funções que trabalham a estrutura da comunidade do projeto.
*/

#include <glib.h>
#include "utilizador.h"
#include "posts.h"
#include "tag.h"

typedef struct TCD_community* TAD_community;

/**
\brief Função que cria uma estrutura TAD.

@returns Estrutura TAD inicializada.
*/

TAD_community create_tad();

/**
\brief Função que acede a uma estrutura TAD e retorna uma HashTable com as informações de utilizadores.

@param tad Estrutura da comunidade.

@returns HashTable com utilizadores.
*/

GHashTable* get_utilizador(TAD_community tad);

/**
\brief Função que acede a uma estrutura TAD e retorna uma HashTable com as informações de posts.

@param tad Estrutura da comunidade.

@returns HashTable com posts.
*/


GHashTable* get_posts(TAD_community tad);

/**
\brief Função que acede a uma estrutura TAD e retorna uma GList com as datas dos posts.

@param tad Estrutura da comunidade.

@returns GList com datas.
*/

GList* get_date_posts(TAD_community tad);

/**
\brief Função que acede a uma estrutura TAD e retorna uma HashTable com as informações de tags.

@param tad Estrutura da comunidade.

@returns HashTable com tags.
*/

GHashTable* get_tag(TAD_community tad);
/**
\brief Função que acede uma estrutura tad, recebe uma chave e um UTILIZADOR e coloca nessa chave a nova estrutura UTILIZADOR.

@param tad Estrutura TAD.
@param key Chave para a tabela de Hash.
@param value Estrutura UTILIZADOR.

*/
void set_utilizador(TAD_community tad, long key, UTILIZADOR value);

/**
\brief Função que acede uma estrutura tad, recebe uma chave e POSTS e coloca nessa chave a nova estrutura POSTS.

@param tad Estrutura TAD.
@param key Chave para a tabela de Hash.
@param value Estrutura POSTS.

*/

void set_posts(TAD_community tad, long key, POSTS value);

/**
\brief Função que acede uma estrutura tad e recebe POSTS e coloca na TAD as novas datas dos posts.

@param tad Estrutura TAD.
@param value Estrutura POSTS.

*/

void adiciona_date_posts(TAD_community tad, POSTS value);

/**
\brief Função que compara 2 apontadores e devolve a diferença entre os dois.

@param a Apontador a.
@param b Apontador b.

@returns Inteiro com a diferença entre os 2 apontadores.
*/


gint compara(gconstpointer a, gconstpointer b);

/**
\brief Função que acede a uma estrutura TAD e ordena as datas dos posts por ordem.

@param tam Estrutura TAD.
*/
void ordena(TAD_community tad);

/**
\brief Função que acede a uma estrutura TAD, uma chave e uma estrutura TAG e coloca a nova TAG na estrutura.

@param tam Estrutura TAD.
@param key Chave.
@param value Estrutura TAG.
*/

void set_tag(TAD_community tad, char* key, TAG value);

/**
\brief Função que recebe uma estrutura TAD e liberta a memória alocada por esta estrutura.

@param tam Estrutura TAD.
*/

void free_tad(TAD_community tad);

#endif