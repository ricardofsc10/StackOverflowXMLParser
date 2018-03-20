#include <stdlib.h>
#include "struct.c"
#include "date.h"
#include "user.h"

// Não se consegue inicializar o user e a date pq sao tipos de dados abstratos

TAD_community init(){
	TAD_community tad = NULL;

	tad->utilizador = malloc(sizeof(struct utilizador)*700000); // inicializei com 700000 podia ser com outro qqr
	tad->n_utilizadores = 0;

	for(int i = 0 ; i!=700000 ; i++){
		tad->utilizador[i]->nome = NULL;
		tad->utilizador[i]->id = NULL;
		// tad->utilizador[i]->user = malloc(sizeof(struct user));
		tad->utilizador[i]->reputacao = NULL;
		tad->utilizador[i]->n_posts = 0;
		// tad->utilizador[i]->posts->data = malloc(sizeof(struct date));
		
		tad->utilizador[i]->posts = malloc(sizeof(struct posts)*10);
		for(int i = 0 ; i != 10 ; i++){
			tad->utilizador[i]->posts[i]->id_post = NULL;
			tad->utilizador[i]->posts[i]->score = NULL;
			tad->utilizador[i]->posts[i]->title = NULL;
			tad->utilizador[i]->posts[i]->post = NULL;
			tad->utilizador[i]->posts[i]->tipo = 0;
			
			tad->utilizador[i]->posts[i]->tags = malloc(sizeof(10));
				for(int i = 0 ; i != 10 ; i++){
					tad->utilizador[i]->posts[i]->tags[i] = NULL;
				}
		}
	}
	return tad;
}
