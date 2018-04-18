#ifndef __TCD__
#define __TCD__

#include <glib.h>
#include "utilizador.h"
#include "posts.h"

typedef struct TCD_community* TAD_community;

TAD_community create_tad();
GHashTable* get_utilizador(TAD_community tad);
GHashTable* get_posts(TAD_community tad);
GList* get_date_posts(TAD_community tad);
void set_utilizador(TAD_community tad, long key, UTILIZADOR value);
void set_posts(TAD_community tad, long key, POSTS value);
void set_date_posts(TAD_community tad, gpointer data, gint position);
void free_tad(TAD_community tad);

#endif
