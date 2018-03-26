/**
@file init.c
@author Grupo21
@brief Ficheiro que contém funções de inicialização de memória, para a estrutura usada.
*/

#include <stdlib.h>
#include <stdio.h>
#include "struct.c"
#include "date.h"
#include "user.h"

/**
@brief Função que faz a primeira inicialização da estrutura.

Inicializa cada parâmetro da estrutura definida em 

@returns Estrutura TAD_community inicializada.
*/

TAD_community init(){

	TAD_community tad = malloc(sizeof(struct TCD_community));
	tad->utilizador = malloc(sizeof(struct utilizador)*50000);
	tad->n_utilizadores = 0;
	tad->espaco_users = 50000;
	tad->posts = malloc(sizeof (struct posts)*75000);
	tad->posts_t = 0;
	tad->espaco_posts=75000;
	
	for(int i = 0 ; i!=50000 ; i++){
		tad->utilizador[i] = malloc(sizeof(struct utilizador));
		tad->utilizador[i]->nome = NULL; ////////
		tad->utilizador[i]->id = 0;
		long array[10] = {0};
		tad->utilizador[i]->user = create_user(NULL,array);
		tad->utilizador[i]->reputacao = NULL;
		tad->utilizador[i]->posts_u = 0;		
	}
	for (int j = 0; j != 75000; j++) {
		tad->posts[j] = malloc(sizeof(struct posts));
		tad->posts[j]->data= createDate(0,0,0);
		tad->posts[j]->id_post = 0;
		tad->posts[j]->score = NULL;
		tad->posts[j]->owner_user_id=NULL;
		tad->posts[j]->title = NULL;
		tad->posts[j]->body = NULL;
		tad->posts[j]->post_type_id = NULL;
		tad->posts[j]->parent_id=0;
		tad->posts[j]->tags = malloc(sizeof(10));
		tad->posts[j]->answer_count = NULL;
		tad->posts[j]->comment_count = NULL;
		tad->posts[j]->favorite_count = NULL;
	}
	return tad;
}

/**
@brief Função utilizada para redimensionar a estrutura quando esta se encontra sem espaço.

Usa o <b>realloc()</b> que está definido na biblioteca <b>stdlib.h</b>, para realocar mais memória 
para que possam ser inseridos mais utilizadores, sem perder a informação 
que ja la estava.

Inicializa os campos da estrutura relativos ao novo espaço alocado.

@param com Estrutura onde será alocada memória.

@returns Estrutura com os mesmos dados, mas com mais espaço.
*/

void redimensiona_utilizadores(TAD_community com){

	//redimensiona e coloca em 'com' tudo o que ja estava, com mais espaço
	com->utilizador = realloc(com->utilizador, sizeof(struct utilizador) * (com->espaco_users + 50000));

	// faz igual à init
	for(int i = com->espaco_users ; i < (com->espaco_users + 50000) ; i++){
		com->utilizador[i] = malloc(sizeof(struct utilizador));
		com->utilizador[i]->nome = NULL; ////////
		com->utilizador[i]->id = 0;
		long array[10] = {0};
		com->utilizador[i]->user = create_user(NULL,array);
		com->utilizador[i]->reputacao = NULL;
		com->utilizador[i]->posts_u= 0;		
	}
	com->espaco_users += 50000; // so faz este passo no fim por causa do primeiro for
}

void redimensiona_posts(TAD_community com) {
	com->posts = realloc(com->posts, sizeof(struct posts) * (com->espaco_posts + 75000));

	for (int j = com->espaco_posts; j <(com->espaco_posts + 75000); j++) {
		com->posts[j] = malloc(sizeof(struct posts));
		com->posts[j]->data= createDate(0,0,0);
		com->posts[j]->id_post = 0;
		com->posts[j]->score = NULL;
		com->posts[j]->owner_user_id=NULL;
		com->posts[j]->title = NULL;
		com->posts[j]->body = NULL;
		com->posts[j]->post_type_id = NULL;
		com->posts[j]->parent_id=0;
		com->posts[j]->tags = malloc(sizeof(10));
		com->posts[j]->answer_count = NULL;
		com->posts[j]->comment_count = NULL;
		com->posts[j]->favorite_count = NULL;
	}
	com->espaco_posts+=75000;

}