#ifndef __QUERY5__
#define __QUERY5__

/**
@file query5.h
Query5 do projeto.
*/


/**
\brief Função que dado um ID de utilizador, devolver a informação do seu perfil (short bio)
 e os IDs dos seus 10 últimos posts (perguntas ou respostas), ordenados por cronologia inversa.

@param com Estrutura com os dados.
@param id Parâmetro de comparação.

@returns Utilizador com informação pedida.
*/


USER get_user_info(TAD_community com, long id);

#endif