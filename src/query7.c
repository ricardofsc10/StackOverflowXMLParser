#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "query7.h"

// query 7

LONG_list most_answered_questions(TAD_community com, int N, Date begin, Date end){ // da com mais respostas para a q tem menos

  GList* glista = get_date_posts(com);
  GList* glanswers = NULL;
  int i = 0;

  while(glista != NULL){
    if(get_post_type_id(glista->data) == 1){ // se é resposta
      
      if(difDatas(get_data(glista->data),begin,end) == 0){ // se está dentro das datas
        // insere no inicio as respostas
        glanswers = g_list_prepend(glanswers, (gpointer) glista->data);
        i++;
      }
    }
    glista = glista->next;
  }

  // ordena a lista por ordem crescente de answer_count
  glanswers = g_list_sort(glanswers, compara_answer);

  int tamanho;
  if(i > N) tamanho = N;
  else tamanho = i;

  LONG_list res = create_list(tamanho);

  i = 0;
  while(glanswers != NULL && i < tamanho){
      set_list(res,i,get_key_id_post(glanswers->data));
      glanswers = g_list_next(glanswers);
      i++;
  }
  
  // para testar
  for(i = 0; i < tamanho; i++){
    printf("POST_ID: %ld\n", get_list(res,i) );
  }

  return res;
}