#ifndef __INTERFACE__
#define __INTERFACE__

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "date.h"
#include "pair.h"
#include "list.h"
#include "user.h"

typedef struct TCD_community * TAD_community;

typedef struct utilizador* UTILIZADOR;

typedef struct posts* POSTS;

// funções auxiliares

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

int elem(char* palavra, char* texto);

/**
@brief Função que faz a primeira inicialização da estrutura.

Inicializa cada parâmetro da estrutura definida em 

@returns Estrutura TAD_community inicializada.
*/

TAD_community init();

/**
@brief Função utilizada para redimensionar a estrutura dos utilizadores quando esta se encontra sem espaço.

Usa o <b>realloc()</b> que está definido na biblioteca <b>stdlib.h</b>, para realocar mais memória 
para que possam ser inseridos mais utilizadores, sem perder a informação 
que ja la estava.

Inicializa os campos da estrutura relativos ao novo espaço alocado.

@param com Estrutura onde será alocada memória.

@returns Estrutura com os mesmos dados, mas com mais espaço.
*/
void redimensiona_utilizadores(TAD_community com);


/**
@brief Função utilizada para redimensionar a estrutura dos posts quando esta se encontra sem espaço.

Usa o <b>realloc()</b> que está definido na biblioteca <b>stdlib.h</b>, para realocar mais memória 
para que possam ser inseridos mais posts, sem perder a informação 
que ja la estava.

Inicializa os campos da estrutura relativos ao novo espaço alocado.

@param com Estrutura onde será alocada memória.

@returns Estrutura com os mesmos dados, mas com mais espaço.
*/
void redimensiona_posts(TAD_community com);

// query 0

/**
@brief Função que filtra as datas, transformando-as em elementos da struct date.

@param data Data que vai ser transformada.

@returns Data compatível com a struct date.
*/

Date stringToDias (char* data);

/**
@brief Função que filtra os dados que são necessários do documento Users.xml 
e coloca nos campos da estrutura.

@param doc Documento Users.xml.
@param cur Raiz do documento.
@param com Estrutura onde vao ser inseridos os dados.

@returns Estrutura com os dados referentes a cada utilizador.
*/


void getReferenceUser (xmlDocPtr doc, xmlNodePtr cur, TAD_community com);

/**
@brief Função que filtra os dados que são necessários do documento Posts.xml 
e coloca nos campos da estrutura.

Utiliza a função <b>procuraBinaria()</b>, para a descobrir em que posição do
array está o criador do post.

@param doc Documento Posts.xml.
@param cur Raiz do documento.
@param com Estrutura onde vao ser inseridos os dados.

@returns Estrutura com os dados referentes a cada post no seu devido campo.
*/

void getReferencePosts (xmlDocPtr doc, xmlNodePtr cur, TAD_community com);

/**
@brief Função que filtra os dados que são necessários do documento Votes.xml 
e coloca nos campos da estrutura.

Utiliza a função <b>procuraBinaria()</b>, para a descobrir em que posição do
array está o criador do post.

@param doc Documento Votes.xml.
@param cur Raiz do documento.
@param com Estrutura onde vao ser inseridos os dados.

@returns Estrutura com os votos referentes a cada post.
*/

void getReferenceVotes (xmlDocPtr doc, xmlNodePtr cur, TAD_community com);

/**
@brief Função que realiza todo o processo de parsing dos documentos.

Utiliza as funções <b>strcpy()</b> e <b>strcat()</b> definidas na biblioteca
<b>stdlib.h</b> para colocar no caminho recebido como parâmetro o nome do
documento necessário.

Realiza vários testes para o caso de ocorrências de erros no carregamento de 
de algum documento ou erros na atribuição da raiz do documento às variáveis 
<b>cur_</b>

@param com Estrutura inicializada.
@param dump_path Contém o caminho para a pasta que contém os documentos .xml.

@returns Estrutura totamente carregada com os dados filtrados de cada ficheiro.
*/

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

TAD_community clean(TAD_community com);

#endif
