#include <stdlib.h>
#include "common.h"
#include <glib.h>


struct TCD_community{
  GHashTable* utilizador;
  GHashTable* posts;
};

TAD_community create_tad(){
	TAD_community tad = malloc(sizeof(struct TCD_community));
    tad->utilizador = g_hash_table_new (g_int_hash, g_int_equal);
    tad->posts = g_hash_table_new (g_int_hash, g_int_equal);
    return tad;
}

GHashTable* get_utilizador(TAD_community tad){
	return tad->utilizador;
}

GHashTable* get_posts(TAD_community tad){
	return tad->posts;
}

void set_utilizador(TAD_community tad, gpointer key, gpointer value){
	g_hash_table_insert(tad->utilizador, key, value);
}

void set_posts(TAD_community tad, gpointer key, gpointer value){
	g_hash_table_insert(tad->posts, key, value);
}

void free_tad(TAD_community tad){
	g_hash_table_destroy(tad->utilizador);
	g_hash_table_destroy(tad->utilizador);
}