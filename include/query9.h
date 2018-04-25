#ifndef __QUERY9__
#define __QUERY9__

/**
@file query9.h
Query9 do projeto.
/*

/**
\brief Função que dados os IDs de dois utilizadores, devolve as últimas
N perguntas, em cronologia inversa, em que participaram os dois utilizadores específicos

@param com Estrutura com os dados.
@param id1 Parâmetro de comparação.
@param id2 Parâmetro de comparação.
@param N Número de perguntas pedidas.

@returns Lista com os IDs das perguntas em que ambos participam.
*/

LONG_list both_participated(TAD_community com, long id1, long id2, int N);

#endif