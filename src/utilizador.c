#include <stdlib.h>
#include "utilizador.h"
#include "common.h"
#include <glib.h>
#include <string.h>

struct utilizador{
	gint key_id;
	gchar* nome;
	gchar* bio;
	GList* posts_frequentados; // so contem o id das perguntas em que ele interage
	gint posts_u;
	gint reputacao;
};

UTILIZADOR create_utilizador(){
	UTILIZADOR u = malloc(sizeof(struct utilizador));
	u->key_id = 0;
	u->nome = NULL;
	u->bio = NULL;
	u->posts_frequentados = NULL;
	u->posts_u = 0;
	u->reputacao = 0;
	return u;
}

long get_key_id(UTILIZADOR u){
	return u->key_id;
}

gchar* get_nome(UTILIZADOR u){
	return u ? mystrdup(u->nome) : NULL;
}

gchar* get_bio_utilizador(UTILIZADOR u){
	return u ? mystrdup(u->bio) : NULL;
}

GList* get_posts_frequentados(UTILIZADOR u){
	return u->posts_frequentados;
}

long get_posts_u(UTILIZADOR u){
	return u->posts_u;
}

long get_reputacao(UTILIZADOR u){
	return u->reputacao;
}

void set_key_id(UTILIZADOR u, int key_id){
	u->key_id = key_id;
}

void set_nome(UTILIZADOR u, char* str){
	free(u->nome);
	u->nome = mystrdup(str);
}

void set_bio(UTILIZADOR u, char* str){
	free(u->bio);
	u->bio = mystrdup(str);
}

void set_posts_frequentados(UTILIZADOR u, long value){
	int contem = 0;
	GList* glista = u->posts_frequentados;
	// ciclo para ver se contém o value, pára se o o glista->data for maior, uma vez q está ordenado
	while(glista != NULL){
		if((long)glista->data == value){
			contem = 1;
			break;
		}
		glista = g_list_next(glista);
	}
	// se nao contiver o value, insere-o, e ordena
	if(contem == 0)
		u->posts_frequentados = g_list_insert(u->posts_frequentados, (gpointer) value, 0);
}

void set_posts_u(UTILIZADOR u, int posts_u_l){
	u->posts_u = posts_u_l;
}

void set_reputacao(UTILIZADOR u, int reputacao){
	u->reputacao = reputacao;
}

void free_utilizador(UTILIZADOR u){
	if(u){
    	free(u->nome);
    	free(u->bio);
    	free(u->posts_frequentados);
    	free(u);
	}
}
