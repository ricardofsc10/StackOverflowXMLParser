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


/**
@brief Função que verifica se uma data se encontra ou não entre um período.

@param x Data usada para comparar
@param begin Data do ínicio da comparação.
@param end Data do fim da comparação.

@returns Inteiro que conclui se a data em questão se encontra no período correspondente.
*/
int difDatas(Date x,Date begin, Date end);

#endif