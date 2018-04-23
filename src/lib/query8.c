#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "posts.h"
#include "funcoes.h"

// query 8

LONG_list contains_word(TAD_community com, char* word, int N){
  
  LONG_list l = create_list(N);
  long posts[N];
  int temp;

  // inicialização do posts a 0
  for(int i = 0; i<N ; i++){
    posts[i] = 0;
  }

  for (int i=0; i < N ; i++){ // inicialização da lista
    set_list(l,i,0); // tem os id's das perguntas
  }
  
  GList* gl = g_hash_table_get_values(get_posts(com));
  GList* glista;
 
  for(glista = gl; glista!=NULL; glista = g_list_next(glista)){
    if (get_post_type_id(glista->data) == 1){ // se é pergunta
      
      char* ret;
      ret = strstr((const char *) get_title(glista->data),word);
      
      if (ret!=NULL) { // se o titulo contem a palavra
        for(int j=N-2;j>=0;j--){
          temp = posts[j+1];
          posts[j+1] = posts[j];
          posts[j] = temp;
        }
        posts[0] = get_key_id_post(glista->data);
      }
    }
  }

  for(int i = 0; i<N ; i++){
    set_list(l,i,posts[i]);
  }
  
  // para testar
  for(int i = 0; i < N; i++){
    printf("ID's: %ld\n", get_list(l,i) );
  }

  return l; 
}