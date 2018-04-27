#include <stdlib.h>
#include "answer_count.h"
#include "common.h"
#include <glib.h>
#include <string.h>

struct answer_count{
	long id_pergunta;
	long num_respostas;
};

ANSWER_COUNT create_answer_count(){
	ANSWER_COUNT t = malloc(sizeof(struct answer_count));
	t->id_pergunta = 0;
	t->num_respostas = 0;
	return t;
}

long get_num_respostas(ANSWER_COUNT t){
	return t->num_respostas;
}

long get_id_pergunta(ANSWER_COUNT t){
	return t->id_pergunta;
}

void set_num_respostas(ANSWER_COUNT t, int incremento){
	t->num_respostas = t->num_respostas + incremento;
}

void set_id_pergunta(ANSWER_COUNT t, long id_l){
	t->id_pergunta = id_l;
}

void free_answer_count(ANSWER_COUNT t){
	if(t){
    	free(t);
	}
}