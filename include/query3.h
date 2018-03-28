#ifndef __QUERY3__
#define __QUERY3__

/**
@file query3.h
@author Grupo21
@brief Ficheiro que contém as funções da query 3.
*/


/**
@brief Função que dado um intervalo de tempo arbitrário, obtem o número total de posts 
(identificando perguntas e respostas separadamente) neste período.

@param com Estrutura com os dados.
@param begin Data do ínicio da comparação.
@param end Data do fim da comparação.

@returns Lista com o total de posts no período correspondente.
*/
LONG_pair total_posts(TAD_community com, Date begin, Date end);

#endif