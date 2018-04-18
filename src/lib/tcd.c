#include <stdlib.h>
#include "common.h"
#include <glib.h>
#include "tcd.h"

struct TCD_community{
  GHashTable* utilizador;
  GHashTable* posts;
  GList* date_posts;
};

TAD_community create_tad(){
	TAD_community tad = malloc(sizeof(struct TCD_community));
    tad->utilizador = g_hash_table_new(g_direct_hash, g_direct_equal);
    tad->posts = g_hash_table_new(g_direct_hash, g_direct_equal);
    tad->date_posts = NULL;
    return tad;
}

GHashTable* get_utilizador(TAD_community tad){
	return tad->utilizador;
}

GHashTable* get_posts(TAD_community tad){
	return tad->posts;
}

GList* get_date_posts(TAD_community tad){
	return tad->date_posts;
}

void set_utilizador(TAD_community tad, long key, UTILIZADOR value){
	g_hash_table_insert(tad->utilizador, (gpointer) key, (gpointer) value);
}

void set_posts(TAD_community tad, long key, POSTS value){
	g_hash_table_insert(tad->posts, (gpointer) key, (gpointer) value);
}

void set_date_posts(TAD_community tad, gpointer data, gint position){
	GList* gl __unused = g_list_insert(tad->date_posts, data, position);
	// a função insert do g_list retorna o novo apontador para a cabeça portanto nao sei se seria bom o retornar
	// dá warning
	// so meti unused para nao dar warning
}

void free_tad(TAD_community tad){
	g_hash_table_destroy(tad->utilizador);
	g_hash_table_destroy(tad->posts);
	g_list_free(tad->date_posts);
}