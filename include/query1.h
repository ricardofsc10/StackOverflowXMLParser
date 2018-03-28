#ifndef __QUERY1__
#define __QUERY1__

/**
@file query1.h
@author Grupo21
@brief Ficheiro que contém as funções da query 1.
*/


/**
@brief Função que dado o identificador de um post, retorna o título do post e o nome de utilizador do autor. 
Se o post for uma resposta, a função retorna informações (título e utilizador) da pergunta correspondente.

@param com Estrutura com os dados.
@param id Parâmetro de comparação.

@returns Par com informação do post.
*/
STR_pair info_from_post(TAD_community com, int id);

#endif