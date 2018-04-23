/**
@brief Função que dado um intervalo de tempo arbitrário, devolve os IDs das N respostas com mais votos, 
em ordem decrescente do número de votos.

@param com Estrutura com os dados.
@param N Número de respostas pedidas.
@param begin Data do ínicio da comparação.
@param end Data do fim da comparação.

@returns Lista com os IDs.
*/


#ifndef __QUERY6__
#define __QUERY6__

LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end);

#endif