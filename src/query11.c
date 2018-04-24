#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "query11.h"

// query 11

LONG_list most_used_best_rep(TAD_community com, int N, Date begin, Date end){
  
  GList* gl = g_hash_table_get_values(get_utilizador(com));
  GList* glista = gl;

  glista = g_list_sort(glista, compara_reputacao);
  
  LONG_list l = create_list(N);
  int i = 0;
  while(glista != NULL && i < N){
    if(difDatas(get_data(glista->data),begin,end) == 0){ //verifica se esta entre o intervalo de tempo
      set_list(l,i,get_tags(glista->data));
      i++;
    }
    glista = g_list_next(glista);
  }

  LONG_list aux = remove_trash(l, N);



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