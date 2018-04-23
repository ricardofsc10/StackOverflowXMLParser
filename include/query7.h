/**
@brief Função que dado um intervalo de tempo arbitrário, devolve as IDs das N perguntas com mais respostas, 
em ordem decrescente do número de respostas.

@param com Estrutura com os dados.
@param N Número de respostas pedidas.
@param begin Data do ínicio da comparação.
@param end Data do fim da comparação.

@returns Lista com os IDs.
*/


#ifndef __QUERY7__
#define __QUERY7__

LONG_list most_answered_questions(TAD_community com, int N, Date begin, Date end);

#endif