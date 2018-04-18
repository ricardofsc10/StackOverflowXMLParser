#ifndef __UTILIZADOR__
#define __UTILIZADOR__

#include "date.h"
#include <glib.h>

typedef struct utilizador * UTILIZADOR;

UTILIZADOR create_utilizador();
gint get_key_id(UTILIZADOR u);
gchar* get_nome(UTILIZADOR u);
gchar* get_bio_utilizador(UTILIZADOR u);
gint* get_posts_frequentados(UTILIZADOR u, int tam);
gint get_contador_posts_frequentados(UTILIZADOR u);
gint get_espaco_posts_frequentados(UTILIZADOR u);
gint get_posts_u(UTILIZADOR u);
gint get_reputacao(UTILIZADOR u);
void set_key_id(UTILIZADOR u, int key_id);
void set_nome(UTILIZADOR u, char* str);
void set_bio(UTILIZADOR u, char* str);
void set_posts_frequentados(UTILIZADOR u, int index, int value);
void set_contador_posts_frequentados(UTILIZADOR u, int contador_posts_frequentados);
void set_espaco_posts_frequentados(UTILIZADOR u, int espaco_posts_frequentados);
void set_posts_u(UTILIZADOR u, int posts_u);
void set_reputacao(UTILIZADOR u, int reputacao);
void free_utilizador(UTILIZADOR u);
#endif
