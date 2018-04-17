/*

#include <stdio.h>
#include "list.h"
#include "interface.c"

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
  
  for(int i=0; i < com->posts_t ; i++){
    if (com->posts[i]->post_type_id == 1){ // se é pergunta
      char* ret;
      ret = strstr((const char *) com->posts[i]->title,word);
      if (ret!=NULL) { // se o titulo contem a palavra
        for(int j=N-2;j>=0;j--){
          temp = posts[j+1];
          posts[j+1] = posts[j];
          posts[j] = temp;
        }
        posts[0] = com->posts[i]->id_post;
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
*/