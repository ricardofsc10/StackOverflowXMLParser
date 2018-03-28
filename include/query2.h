#ifndef __QUERY2__
#define __QUERY2__

/**
@file query2.h
@author Grupo21
@brief Ficheiro que contém as funções da query 2.
*/


/**
@brief Função que devolve o top N utilizadores com maior número de posts de sempre. 
São considerados tanto perguntas quanto respostas dadas pelo respectivo utilizador.

@param com Estrutura com os dados.
@param N Tamanho do top.

@returns Lista com o top correspondente.
*/
LONG_list top_most_active(TAD_community com, int N);

#endif