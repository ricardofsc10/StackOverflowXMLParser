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
	tad->espaco_estrutura = 50000;
	
	for(int i = 0 ; i!=50000 ; i++){
		tad->utilizador[i] = malloc(sizeof(struct utilizador));
		tad->utilizador[i]->nome = NULL; ////////
		tad->utilizador[i]->id = NULL;
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
			tad->utilizador[i]->posts[j]->post_type_id = NULL;
			
			tad->utilizador[i]->posts[j]->tags = malloc(sizeof(10));
				for(int k = 0 ; k != 10 ; k++){
					tad->utilizador[i]->posts[j]->tags[k] = malloc(sizeof(1));
					tad->utilizador[i]->posts[j]->tags[k] = NULL;
				}
			tad->utilizador[i]->posts[j]->answer_count = NULL;
			tad->utilizador[i]->posts[j]->comment_count = NULL;
			tad->utilizador[i]->posts[j]->favorite_count = NULL;
		}
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
			com->utilizador[i]->posts[j]->post_type_id = NULL;
			
			com->utilizador[i]->posts[j]->tags = malloc(sizeof(10));
				for(int k = 0 ; k != 10 ; k++){
					com->utilizador[i]->posts[j]->tags[k] = malloc(sizeof(1));
					com->utilizador[i]->posts[j]->tags[k] = NULL;
				}
			com->utilizador[i]->posts[j]->answer_count = NULL;
			com->utilizador[i]->posts[j]->comment_count = NULL;
			com->utilizador[i]->posts[j]->favorite_count = NULL;
		}
	}
	com->espaco_estrutura += 50000; // so faz este passo no fim por causa do primeiro for
}