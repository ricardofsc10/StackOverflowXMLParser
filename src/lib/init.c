#include <stdlib.h>
#include <stdio.h>
#include "struct.c"
#include "date.h"
#include "user.h"

// o user e o date sao inicializados segundo os metodos dados no .c pq são tipos abstratos

TAD_community init(){
	TAD_community tad = malloc(sizeof(struct TCD_community));
	tad->utilizador = malloc(sizeof(struct utilizador)*50000); // inicializei com 700000 podia ser com outro qqr
	tad->n_utilizadores = 0;
	tad->espaco_estrutura = 50000;
	
	for(int i = 0 ; i!=50000 ; i++){
		tad->utilizador[i] = malloc(sizeof(struct utilizador));
		tad->utilizador[i]->nome = NULL; ////////
		tad->utilizador[i]->id = 0;
		long array[10] = {0};
		tad->utilizador[i]->user = create_user(NULL,array);
		tad->utilizador[i]->reputacao = NULL;
		tad->utilizador[i]->n_posts = 0;
		tad->utilizador[i]->posts = malloc(sizeof(struct posts)*10);
		for(int j = 0 ; j != 10 ; j++){
			tad->utilizador[i]->posts[j] = malloc(sizeof(struct posts));
			tad->utilizador[i]->posts[j]->data = createDate(0,0,0);
			tad->utilizador[i]->posts[j]->id_post = NULL;
			tad->utilizador[i]->posts[j]->score = NULL;
			tad->utilizador[i]->posts[j]->title = NULL;
			tad->utilizador[i]->posts[j]->body = NULL;
			tad->utilizador[i]->posts[j]->tipo = 0;
			
			tad->utilizador[i]->posts[j]->tags = malloc(sizeof(10));
				for(int k = 0 ; k != 10 ; k++){
					tad->utilizador[i]->posts[j]->tags[k] = malloc(sizeof(1));
					tad->utilizador[i]->posts[j]->tags[k] = NULL;
				}
			tad->utilizador[i]->posts[j]->answer_count = 0;
		}
	}
	return tad;
}
void redimensiona_utilizadores(TAD_community com){

	//redimensiona e coloca em 'com' tudo o que ja estava, e mais espaço
	com->utilizador = realloc(com->utilizador, sizeof(struct utilizador) * (com->espaco_estrutura + 50000));

	// faz igual à init
	for(int i = com->espaco_estrutura ; i < (com->espaco_estrutura + 50000) ; i++){
		com->utilizador[i] = malloc(sizeof(struct utilizador));
		com->utilizador[i]->nome = NULL; ////////
		com->utilizador[i]->id = 0;
		long array[10] = {0};
		com->utilizador[i]->user = create_user(NULL,array);
		com->utilizador[i]->reputacao = NULL;
		com->utilizador[i]->n_posts = 0;
		com->utilizador[i]->posts = malloc(sizeof(struct posts)*10);
		for(int j = 0 ; j != 10 ; j++){
			com->utilizador[i]->posts[j] = malloc(sizeof(struct posts));
			com->utilizador[i]->posts[j]->data = createDate(0,0,0);
			com->utilizador[i]->posts[j]->id_post = NULL;
			com->utilizador[i]->posts[j]->score = NULL;
			com->utilizador[i]->posts[j]->title = NULL;
			com->utilizador[i]->posts[j]->body = NULL;
			com->utilizador[i]->posts[j]->tipo = 0;
			
			com->utilizador[i]->posts[j]->tags = malloc(sizeof(10));
				for(int k = 0 ; k != 10 ; k++){
					com->utilizador[i]->posts[j]->tags[k] = malloc(sizeof(1));
					com->utilizador[i]->posts[j]->tags[k] = NULL;
				}
			com->utilizador[i]->posts[j]->answer_count = 0;
		}
	}
	com->espaco_estrutura += 50000; // so faz este passo no fim por causa do primeiro for
	
	//return com;
}