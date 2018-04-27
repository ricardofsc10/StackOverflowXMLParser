#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "answer_count.h"
#include "query7.h"

// query 7

LONG_list most_answered_questions(TAD_community com, int N, Date begin, Date end){ // da com mais respostas para a q tem menos

  // necessário colocar numa GList* os posts que se situam dentro da data
  GList* perguntas = NULL;
  GList* glista = get_date_posts(com);
  int i = 0;

  while(glista != NULL){

    if(difDatas(get_data(glista->data),begin,end) == 0){

        // se for pergunta insere o post na glist
        if(get_post_type_id(glista->data) == 1){

            ANSWER_COUNT ac = create_answer_count();
            set_id_pergunta(ac, get_key_id_post(glista->data));
            set_num_respostas(ac, 0);

            perguntas = g_list_prepend(perguntas, (gpointer) ac);
            i++;
        }
        else{
            // se for resposta procura o parent_id nas perguntas e aumenta o answer_count
            long id_parent = get_parent_id(glista->data);
            GList* aux = perguntas;
            while(aux != NULL){
                if(get_id_pergunta(aux->data) == id_parent){
                    set_num_respostas(aux->data, 1);
                    break;
                }
                aux = g_list_next(aux);
            }
        }
    }
    else{
        // como os posts estao ordenados se o dif datas der 1 quer dizer q o post é posterior a 'end'
        if(difDatas(get_data(glista->data),begin,end) == 1)
          break;
    }

    glista = g_list_next(glista);
  }

  perguntas = g_list_sort(perguntas, compara_answer);

  // neste momento temos na GList* perguntas, todas os id's com o número de respostas dentro do tempo dado
  // os posts já estão ordenados por answer_count

  int tamanho;
  if(i > N) tamanho = N;
  else tamanho = i;

  LONG_list l = create_list(tamanho);

  int contador = 0;
  while(perguntas != NULL && contador < N){

      // insere em l
      set_list(l, contador, get_id_pergunta(perguntas->data));

      perguntas = g_list_next(perguntas);
      contador++;
  }

  // para testar
  for(i = 0; i < tamanho; i++){
    printf("%dº POST_ID: %ld\n", i+1, get_list(l,i) );
  }

  return l;
}