#ifndef __FUNÇÕES__
#define __FUNÇÕES__

/**
@file funções.h
@author Grupo21
@brief Ficheiro que contém funções auxiliares a serem usadas nas querys.
*/


/**
@brief Função que implementa a procura binária, aplicada ao 
Id de cada utilizador.

@param com Estrutura com os dados.
@param id Parâmetro de comparação.
@param Tam Tamanho do array.

@returns Índice do array utilizadores da estrutura onde um dado utilizador
se encontra.
*/
int procura_binaria_u (TAD_community com, int id, int Tam);


/**
@brief Função que implementa a procura binária, aplicada ao 
Id de cada post.

@param com Estrutura com os dados.
@param id Parâmetro de comparação.
@param Tam Tamanho do array.

@returns Índice do array posts da estrutura onde um dado post
se encontra.
*/
int procura_binaria_p (TAD_community com, int id, int Tam);

/**
@brief Função que verifica se uma data se encontra ou não entre um período.

@param x Data usada para comparar
@param begin Data do ínicio da comparação.
@param end Data do fim da comparação.

@returns Inteiro que conclui se a data em questão se encontra no período correspondente.
*/
int difDatas(Date x,Date begin, Date end);

#endif