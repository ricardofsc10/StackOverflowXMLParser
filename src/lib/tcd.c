#include <stdlib.h>
#include "common.h"
#include <glib.h>
#include "tcd.h"

struct TCD_community{
  GHashTable* utilizador;
  GHashTable* posts;
};

TAD_community create_tad(){
	TAD_community tad = malloc(sizeof(struct TCD_community));
    tad->utilizador = g_hash_table_new(g_direct_hash, g_direct_equal);
    tad->posts = g_hash_table_new (g_direct_hash, g_direct_equal);
    return tad;
}

GHashTable* get_utilizador(TAD_community tad){
	return tad->utilizador;
}

GHashTable* get_posts(TAD_community tad){
	return tad->posts;
}

UTILIZADOR get_value_utilizador(TAD_community tad, int* key){
	UTILIZADOR u = (UTILIZADOR) g_hash_table_lookup(tad->utilizador, (gpointer) key);
	return u;
}

void set_utilizador(TAD_community tad, long key, UTILIZADOR value){
	g_hash_table_insert(tad->utilizador, (gpointer) key, (gpointer) value);
}

void set_posts(TAD_community tad, gpointer key, gpointer value){
	g_hash_table_insert(tad->posts, key, value);
}

void free_tad(TAD_community tad){
	g_hash_table_destroy(tad->utilizador);
	g_hash_table_destroy(tad->utilizador);
}