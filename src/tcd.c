#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "common.h"
#include "tcd.h"
#include "funcoes.h"

struct TCD_community{
  GHashTable* utilizador;
  GHashTable* posts;
  GList* date_posts;
  GHashTable* tag;
};

TAD_community create_tad(){
	TAD_community tad = malloc(sizeof(struct TCD_community));
    tad->utilizador = g_hash_table_new(g_direct_hash, g_direct_equal);
    tad->posts = g_hash_table_new(g_direct_hash, g_direct_equal);
    tad->date_posts = NULL;
    tad->tag = g_hash_table_new(g_direct_hash, g_direct_equal);
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

GHashTable* get_tag(TAD_community tad){
	return tad->tag;
}

void set_utilizador(TAD_community tad, long key, UTILIZADOR value){
	g_hash_table_insert(tad->utilizador, (gpointer) key, (gpointer) value);
}

void set_posts(TAD_community tad, long key, POSTS value){
	g_hash_table_insert(tad->posts, (gpointer) key, (gpointer) value);
}

void adiciona_date_posts(TAD_community tad, POSTS value){
	tad->date_posts = g_list_insert(tad->date_posts, (gpointer) value, 0);
}

void ordena(TAD_community tad){
	tad->date_posts = g_list_sort(tad->date_posts, compara_strings);
}

void set_tag(TAD_community tad, long key, TAG value){
	g_hash_table_insert(tad->tag, (gpointer) key, (gpointer) value);
}

void free_tad(TAD_community tad){
	g_hash_table_destroy(tad->utilizador);
	g_hash_table_destroy(tad->posts);
	g_list_free(tad->date_posts);
	g_hash_table_destroy(tad->tag);	
}