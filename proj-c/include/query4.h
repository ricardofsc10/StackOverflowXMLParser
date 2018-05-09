#ifndef __QUERY4__
#define __QUERY4__

/**
@file query4.h
Query4 do projeto.
*/

/**
\brief Função que dado um intervalo de tempo arbitrário, devolve todas as perguntas que contêm
uma determinada tag.

@param com Estrutura com os dados.
@param tag Tag a procurar.
@param begin Início do intervalo de tempo.
@param end Fim do intervalo de tempo.

@returns Retorna uma lista com os IDs das perguntas ordenadas em cronologia inversa.
*/

LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end);

#endif