#ifndef __QUERY11__
#define __QUERY11__

/**
@file query11.h
Query11 do projeto.
*/

/**
\brief Função que dado um inteiro N e um intervalo de tempo arbitrário devolve uma lista com
as N tags mais usadas pelos N utilizadores com melhor reputação.


@param com Estrutura com os dados.
@param N Número de tags e utilizadores.
@param begin Data inicial.
@param end Data finak.

@returns PLista com as N tags mais usadas.
*/

LONG_list most_used_best_rep(TAD_community com, int N, Date begin, Date end);

#endif