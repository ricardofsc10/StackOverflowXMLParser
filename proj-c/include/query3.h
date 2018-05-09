#ifndef __QUERY3__
#define __QUERY3__


/**
@file query3.h
Query3 do projeto.
*/


/**
\brief Função que dado um intervalo de tempo arbitrário, obtem o número total de posts 
(identificando perguntas e respostas separadamente) neste período.

@param com Estrutura com os dados.
@param begin Data do ínicio da comparação.
@param end Data do fim da comparação.

@returns Lista com o total de posts no período correspondente.
*/

LONG_pair total_posts(TAD_community com, Date begin, Date end);

#endif