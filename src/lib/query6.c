#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "posts.h"
#include "funcoes.h"

// query 6

gint compara2(gconstpointer a, gconstpointer b) { // Compara duas strings
  return ((long) a > (long)b) ? -1 : 1 ;
}

LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end){ // da com mais respostas para a q tem menos
  LONG_list l = create_list(N);
  LONG_list lid = create_list(N);
  LONG_list res = create_list(N);


  for (int i=0; i < N ; i++){ // inicialização da lista
    set_list(l,i,0); // vai conter os numeros de respostas
    set_list(lid,i,0); // vai conter o id dos posts
    set_list(res,i,0); // lista q vai ser devolvida
  }

  GList* gl = get_date_posts(com);
  GList* glista = gl;
  GList* glvotes = NULL;

  while(glista != NULL){
    if(get_post_type_id(glista->data) == 2){ // se é resposta
      if(difDatas(get_data(glista->data),begin,end) == 0){ // se está dentro das datas
        
        glvotes = g_list_insert(glvotes, (gpointer)get_dif_votes(glista->data), 0);


/*
        for(int j = 0; j < N ; j++){
          int k = get_list(l,j);
          if(get_dif_votes(glista->data) > k){
            if(j == N-1) { // se está na última posição
              set_list(l,j,get_dif_votes(glista->data)); 
              set_list(lid,j,get_key_id_post(glista->data));
              break;
            }
            else{
              set_list(l,j,get_list(l,j+1));
              set_list(lid,j,get_list(lid,j+1));
            }
          }
          else{
            set_list(l,j-1, get_dif_votes(glista->data));
            set_list(lid,j-1,get_key_id_post(glista->data));
            break;
          }
        }*/
      }
    }
    glista = glista->next;
  }

  glvotes = g_list_sort(glvotes, compara2);

  while(glvotes != NULL){
    printf("%ld\n", (long) glvotes->data );
    glvotes = glvotes->next;
  }
  /*
  // no fim do 'for' a lista lid tem os id's dos posts por ordem crescente, necessário inverter a ordem
  int j = N-1;
  for (int i = 0 ; i < N ; i++){
    set_list(res, i, get_list(lid, j)); 
    j--;
  }


  // para testar
  j = N-1;
  for(int i = 0; i < N; i++){
    printf("POST_ID: %ld\n", get_list(res,i) );
    printf("Dif votos: %ld\n", get_list(l,j) );
    j--;
  }*/

  free_list(l);
  free_list(lid);

  return res;
}