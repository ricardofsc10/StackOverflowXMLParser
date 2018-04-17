#ifndef __TCD__
#define __TCD__

#include <glib.h>

typedef struct TCD_community* TAD_community;

TAD_community create_tad();
GHashTable* get_utilizador(TAD_community tad);
GHashTable* get_posts(TAD_community tad);
void set_utilizador(TAD_community tad, gpointer key, gpointer value);
void set_posts(TAD_community tad, gpointer key, gpointer value);
void free_tad(TAD_community tad);

#endif
