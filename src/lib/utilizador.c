#include <stdlib.h>
#include "utilizador.h"
#include "common.h"
#include <glib.h>
#include <string.h>

struct utilizador{
	gint key_id;
	gchar* nome;
	gchar* bio;
	gint* posts_frequentados; // so contem o id das perguntas em que ele interage
	gint contador_posts_frequentados;
	gint espaco_posts_frequentados;
	gint posts_u;
	gint reputacao;
};

UTILIZADOR create_utilizador(){
	UTILIZADOR u = malloc(sizeof(struct utilizador));
	u->key_id = 0;
	u->nome = NULL;
	u->bio = NULL;
	u->posts_frequentados = malloc(sizeof(int)*10);
	for(int i=0; i<10; i++) u->posts_frequentados[i] = 0;
	u->contador_posts_frequentados = 0;
	u->espaco_posts_frequentados = 0;
	u->posts_u = 0;
	u->reputacao = 0;
	return u;
}

gint get_key_id(UTILIZADOR u){
	return u->key_id;
}

gchar* get_nome(UTILIZADOR u){
	return u ? mystrdup(u->nome) : NULL;
}

gchar* get_bio_utilizador(UTILIZADOR u){
	return u ? mystrdup(u->bio) : NULL;
}

gint* get_posts_frequentados(UTILIZADOR u, int tam){
	long* u1 = malloc(sizeof(int)*tam);
	memcpy(u1, u->posts_frequentados, sizeof(int)*tam);
	return (gint*) u1;
}

gint get_contador_posts_frequentados(UTILIZADOR u){
	return u->contador_posts_frequentados;
}

gint get_espaco_posts_frequentados(UTILIZADOR u){
	return u->espaco_posts_frequentados;
}

gint get_posts_u(UTILIZADOR u){
	return u->posts_u;
}

gint get_reputacao(UTILIZADOR u){
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

void set_posts_frequentados(UTILIZADOR u, int index, int value){
	u->posts_frequentados[index] = value;
}

void set_contador_posts_frequentados(UTILIZADOR u, int contador_posts_frequentados){
	u->contador_posts_frequentados = contador_posts_frequentados;
}

void set_espaco_posts_frequentados(UTILIZADOR u, int espaco_posts_frequentados){
	u->espaco_posts_frequentados = espaco_posts_frequentados;
}

void set_posts_u(UTILIZADOR u, int posts_u){
	u->posts_u = posts_u;
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
