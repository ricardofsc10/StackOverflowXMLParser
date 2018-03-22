#include <stdlib.h>
#include <stdio.h>
#include "struct.c"
#include "date.h"
#include "user.h"

// o user e o date sao inicializados segundo os metodos dados no .c pq são tipos abstratos

TAD_community init(){
	TAD_community tad = malloc(sizeof(struct TCD_community));
	tad->utilizador = malloc(sizeof(struct utilizador)*700000); // inicializei com 700000 podia ser com outro qqr
	tad->n_utilizadores = 0;
	
	for(int i = 0 ; i!=700000 ; i++){
		tad->utilizador[i] = malloc(sizeof(struct utilizador));
		tad->utilizador[i]->nome = NULL; ////////
		tad->utilizador[i]->id = NULL;
		long array[10] = {0};
		tad->utilizador[i]->user = create_user(NULL,array);
		tad->utilizador[i]->reputacao = NULL;
		tad->utilizador[i]->n_posts = 0;
		tad->utilizador[i]->posts = malloc(sizeof(struct posts)*50);
		for(int j = 0 ; j != 50 ; j++){
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
		}
	}
	return tad;
}
