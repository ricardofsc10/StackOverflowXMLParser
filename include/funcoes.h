#ifndef __FUNCOES__
#define __FUNCOES__

#include "date.h"
#include "list.h"
#include <string.h>
#include <stdlib.h>

/**
@brief Função que verifica se uma data se encontra ou não entre um período.

@param x Data usada para comparar
@param begin Data do ínicio da comparação.
@param end Data do fim da comparação.

@returns Inteiro que conclui se a data em questão se encontra no período correspondente.
*/
int difDatas(Date x,Date begin, Date end);

gint compara_strings(gconstpointer a, gconstpointer b);

gint compara_votes(gconstpointer a, gconstpointer b);

gint compara_answer(gconstpointer a, gconstpointer b);

gint compara_posts_u(gconstpointer a, gconstpointer b);

gint compara_reputacao(gconstpointer a, gconstpointer b);

gint compara_ocorrencias(gconstpointer a, gconstpointer b);

/**
@brief Função que filtra as datas, transformando-as em elementos da struct date.

@param data Data que vai ser transformada.

@returns Data compatível com a struct date.
*/
Date stringToDias (char* data);

void strToTag (POSTS value_post, const char* str);

LONG_list remove_trash(LONG_list l, int N);

#endif