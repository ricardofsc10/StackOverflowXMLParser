#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "query7.h"

// query 7

LONG_list most_answered_questions(TAD_community com, int N, Date begin, Date end){ // da com mais respostas para a q tem menos

  LONG_list res = create_list(N);

  for (int i=0; i < N ; i++){ // inicialização da lista
    set_list(res,i,0); // lista q vai ser devolvida
  }

  GList* gl = get_date_posts(com);
  GList* glista = gl;
  GList* glanswers = NULL;

  while(glista != NULL){
    if(get_post_type_id(glista->data) == 1){ // se é pergunta
      
      if(difDatas(get_data(glista->data),begin,end) == 0){ // se está dentro das datas
        // insere no inicio as respostas
        glanswers = g_list_insert(glanswers, (gpointer) glista->data, 0);

      }
    }
    glista = glista->next;
  }

  // ordena a lista por ordem crescente
  glanswers = g_list_sort(glanswers, compara_answer);

  int i = 0;
  while(glanswers != NULL && i < N){
      set_list(res,i,get_key_id_post(glanswers->data));
      glanswers = g_list_next(glanswers);
      i++;
  }

  
  // para testar
  for(int i = 0; i < N; i++){
    printf("POST_ID: %ld\n", get_list(res,i) );
  }

  return res;
}