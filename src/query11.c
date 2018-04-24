#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "query11.h"

// query 11

LONG_list most_used_best_rep(TAD_community com, int N, Date begin, Date end){
  
  GList* gl = g_hash_table_get_values(get_utilizador(com));
  GList* glista = gl;

  glista = g_list_sort(glista, compara_reputacao); // ordenada por reputação
  
  LONG_list l = create_list(N);
  GList* aux = NULL;

  int i = 0;
  while(glista != NULL && i < N){
    aux = g_list_insert(aux, glista->data, 0);
    i++;
    glista = g_list_next(glista);
  }
  // em aux contem os N utilizadores com melhor prestação

  while(aux != NULL){
    GList* posts_perguntas = get_posts_perguntas(aux->data);
    while(posts_perguntas != NULL){
      if(difDatas(get_data(posts_perguntas->data),begin,end) == 0){
          // falta pegar nas tags uma a uma
      }
    }
    aux = g_list_next(aux);
  }

  // neste momento temos cada tag e o número de vezes que foi usada
  



  // deixei aqui para se testar se for preciso
  for(int i=0; i<N; i++){
    if( (void*) get_list(aux,i) == NULL) break;
    printf("%dº: id utilizador: %ld\n\n", i+1, get_list(aux,i));
  }



// inserir ordenadamente
// percorrer o resto dos users inserindo ordenadamente
  

// percorrer os posts todos verificar se pertence a um "top user"
// verificar se está entre as datas e fazer um levantamento das tags

  return aux;
}