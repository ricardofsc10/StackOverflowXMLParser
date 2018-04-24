#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "query2.h"

// query 2

LONG_list top_most_active(TAD_community com, int N){

  GList* gl = g_hash_table_get_values(get_utilizador(com));
  GList* glista = gl;

  glista = g_list_sort(glista, compara_posts_u);

  LONG_list l = create_list(N);
  int i = 0;
  while(glista != NULL && i < N){
    set_list(l,i,get_key_id_post(glista->data));
    i++;
    glista = g_list_next(glista);
  }

  LONG_list aux = remove_trash(l, N);

  // deixei aqui para se testar se for preciso
  for(int i=0; i<N; i++){
    printf("%dº: id utilizador: %ld\n\n", i+1, get_list(aux,i));
  }

  return aux;
}