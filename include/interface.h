#include "date.h"
#include "pair.h"
#include "list.h"
#include "user.h"

typedef struct TCD_community * TAD_community;

// funções auxiliares

TAD_community init();

// query 0
TAD_community load(TAD_community com, char* dump_path);  //diretoria onde estarão os ficheiros do dump

// query 1

/**
@brief Função que dado o identificador de um post, retorna o título do post e o nome de utilizador do autor. 
Se o post for uma resposta, a função retorna informações (título e utilizador) da pergunta correspondente.

@param com Estrutura com os dados.
@param id Parâmetro de comparação.

@returns Par com informação do post.
*/

STR_pair info_from_post(TAD_community com, long id);  

// query 2

/**
@brief Função que devolve o top N utilizadores com maior número de posts de sempre. 
São considerados tanto perguntas quanto respostas dadas pelo respectivo utilizador.

@param com Estrutura com os dados.
@param N Tamanho do top.

@returns Lista com o top correspondente.
*/

LONG_list top_most_active(TAD_community com, int N);

// query 3

/**
@brief Função que dado um intervalo de tempo arbitrário, obtem o número total de posts 
(identificando perguntas e respostas separadamente) neste período.

@param com Estrutura com os dados.
@param begin Data do ínicio da comparação.
@param end Data do fim da comparação.

@returns Lista com o total de posts no período correspondente.
*/

LONG_pair total_posts(TAD_community com, Date begin, Date end);

// query 4

LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end);

// query 5

/**
@brief Função que dado um ID de utilizador, devolver a informação do seu perfil (short bio)
 e os IDs dos seus 10 últimos posts (perguntas ou respostas), ordenados por cronologia inversa.

@param com Estrutura com os dados.
@param id Parâmetro de comparação.

@returns Utilizador com informação pedida.
*/

USER get_user_info(TAD_community com, long id);

// query 6

/**
@brief Função que dado um intervalo de tempo arbitrário, devolve os IDs das N respostas com mais votos, 
em ordem decrescente do número de votos.

@param com Estrutura com os dados.
@param N Número de respostas pedidas.
@param begin Data do ínicio da comparação.
@param end Data do fim da comparação.

@returns Lista com os IDs.
*/

LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end);

// query 7

/**
@brief Função que dado um intervalo de tempo arbitrário, devolve as IDs das N perguntas com mais respostas, 
em ordem decrescente do número de respostas.

@param com Estrutura com os dados.
@param N Número de respostas pedidas.
@param begin Data do ínicio da comparação.
@param end Data do fim da comparação.

@returns Lista com os IDs.
*/

LONG_list most_answered_questions(TAD_community com, int N, Date begin, Date end);

// query 8

/**
@brief Função que dado uma palavra devolve uma lista com os IDs de N perguntas cujos títulos a contenham, 
ordenados por cronologia inversa.

@param com Estrutura com os dados.
@param word Parâmetro de comparação.
@param N Número de perguntas pedidas.

@returns Lista com os IDs.
*/

LONG_list contains_word(TAD_community com, char* word, int N);

// query 9

/**
@brief Função que dados os IDs de dois utilizadores, devolve as últimas
N perguntas, em cronologia inversa, em que participaram os dois utilizadores específicos

@param com Estrutura com os dados.
@param id1 Parâmetro de comparação.
@param id2 Parâmetro de comparação.
@param N Número de perguntas pedidas.

@returns Lista com os IDs das perguntas em que ambos participam.
*/

LONG_list both_participated(TAD_community com, long id1, long id2, int N);

// query 10

/**
@brief Função que dado o ID de uma pergunta, obtém a melhor resposta segundo uma média dada por:
(Scr × 0.45) + (Rep × 0.25) + (Vot × 0.2) + (Comt × 0.1) .

@param com Estrutura com os dados.
@param id Parâmetro de comparação.

@returns Id da melhor resposta.
*/

long better_answer(TAD_community com, long id);

// query 11

LONG_list most_used_best_rep(TAD_community com, int N, Date begin, Date end);

// clean

/**
@brief Função que recebe uma estrutura num dado momento e limpa essa estrutura completamente.

@param com Estrutura com os dados.

@returns Estrutura nula, ou seja, a estrutura recebia depois de limpa.
*/

TAD_community clean(TAD_community com);

