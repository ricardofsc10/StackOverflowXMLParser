#include <stdlib.h>
#include "struct.c"
#include "date.h"
#include "user.h"


TAD_community init(){
	UTILIZADOR* u =(UTILIZADOR)malloc(sizeof (struct utilizador));
	u->nome = NULL;
	u->id = NULL;
	u->user = malloc(sizeof(struct user));
	u->reputacao = NULL;
	u->n_posts-> = 0;
	u->posts = malloc(sizeof(struct posts));
	u->posts->data = malloc(sizeof(struct date));
	u->posts->id_post = NULL;
	u->posts->score = NULL;
	u->posts->title = NULL;
	u->posts->post = NULL;
	u->posts->tipo = 0;
	u->posts->tags = malloc(sizeof(10));
}
