#include <stdio.h>
#include <glib.h>
#include "list.h"
#include "tcd.h"
#include "utilizador.h"
#include "posts.h"
#include "query2.h"

// query 2
/*
LONG_list top_most_active(TAD_community com, int N){
  LONG_list l = create_list(N);
  LONG_list lid = create_list(N);

  for(int i=0; i<N; i++){
    set_list(l,i,0);
    set_list(lid,i,0);
  }
  GList* gl = g_hash_table_get_values(get_utilizador(com));
  GList* glista;
  for(glista = gl; glista!=NULL; glista= glista->next){
    for(int j=0; j<N;j++){
      int k = get_list(l,j);
      if(get_posts_u(get_utilizador(com))>k){
        if(j==N-1) {
          set_list(l,j,get_posts_u(get_utilizador(com))); 
          set_list(lid,j,get_key_id(get_utilizador(com)));
          break;
        }
        else{
          set_list(l,j,get_list(l,j+1));
          set_list(lid,j,get_list(lid,j+1));
        }
      }
      else{
        set_list(l,j-1,get_posts_u(get_utilizador(com)));
        set_list(lid,j, get_key_id(get_utilizador(com)));
        break;
      }
    }
  }
  
  // deixei aqui para se testar se for preciso
  for(int i=0; i<N; i++){
    printf("número total de posts: %ld\n", get_list(l,i));
    printf("id utilizador: %ld\n\n", get_list(lid,i));
  }

  free_list(l);

  return lid;
}*/