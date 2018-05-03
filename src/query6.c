#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "debug.h"
#include "query6.h"

// query 6

LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end){ // da com mais respostas para a q tem menos

  GList* glista = get_date_posts(com);
  GList* glvotes = NULL;
  int i = 0;

  while(glista != NULL){
    if(get_post_type_id(glista->data) == 2){ // se é resposta
      
      if(difDatas(get_data(glista->data),begin,end) == 0){ // se está dentro das datas
        // insere no inicio as respostas
        glvotes = g_list_prepend(glvotes, (gpointer) glista->data);
        i++;
      }
    }
    glista = glista->next;
  }

  // ordena a lista por ordem crescente de score
  glvotes = g_list_sort(glvotes, compara_score);
  GList* glaux = glvotes;

  int tamanho;
  if(i > N) tamanho = N;
  else tamanho = i;

  LONG_list res = create_list(tamanho);

  i = 0;
  while(glvotes != NULL && i < tamanho){
      set_list(res,i,get_key_id_post(glvotes->data));
      glvotes = g_list_next(glvotes);
      i++;
  }
  
  // free das estruturas auxiliares
  g_list_free(glaux);

  // para testar
  for(i = 0; i < tamanho; i++){
    PRINT(printf("POST_ID: %ld\n", get_list(res,i) ));
  }

  return res;
}