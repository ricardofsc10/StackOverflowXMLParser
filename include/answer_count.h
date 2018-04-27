#ifndef __ANSWER_COUNT__
#define __ANSWER_COUNT__

#include <glib.h>

typedef struct answer_count * ANSWER_COUNT;

ANSWER_COUNT create_answer_count();
long get_num_respostas(ANSWER_COUNT t);
long get_id_pergunta(ANSWER_COUNT t);
void set_num_respostas(ANSWER_COUNT t, int incremento);
void set_id_pergunta(ANSWER_COUNT t, long id_l);
void free_answer_count(ANSWER_COUNT t);

#endif