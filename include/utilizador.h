#ifndef __UTILIZADOR__
#define __UTILIZADOR__

#include "date.h"
#include "posts.h"
#include <glib.h>

typedef struct utilizador * UTILIZADOR;

UTILIZADOR create_utilizador();
long get_key_id(UTILIZADOR u);
gchar* get_nome(UTILIZADOR u);
gchar* get_bio_utilizador(UTILIZADOR u);
GList* get_posts_frequentados(UTILIZADOR u);
GList* get_posts_perguntas(UTILIZADOR u);
long get_posts_u(UTILIZADOR u);
long get_reputacao(UTILIZADOR u);
void set_key_id(UTILIZADOR u, int key_id);
void set_nome(UTILIZADOR u, char* str);
void set_bio(UTILIZADOR u, char* str);
void set_posts_frequentados(UTILIZADOR u, long value);
void set_posts_perguntas(UTILIZADOR u, POSTS value);
void set_posts_u(UTILIZADOR u, int posts_u);
void set_reputacao(UTILIZADOR u, int reputacao);
void free_utilizador(UTILIZADOR u);
#endif
