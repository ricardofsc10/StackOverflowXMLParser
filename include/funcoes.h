#ifndef __FUNCOES__
#define __FUNCOES__

#include "date.h"
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

#endif