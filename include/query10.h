/**
@brief Função que dado o ID de uma pergunta, obtém a melhor resposta segundo uma média dada por:
(Scr × 0.45) + (Rep × 0.25) + (Vot × 0.2) + (Comt × 0.1) .

@param com Estrutura com os dados.
@param id Parâmetro de comparação.

@returns Id da melhor resposta.
*/

#ifndef __QUERY10__
#define __QUERY10__

long better_answer(TAD_community com, long id);

#endif