#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "posts.h"
#include "funcoes.h"
#include "query8.h"

// query 8

LONG_list contains_word(TAD_community com, char* word, int N){
  
  LONG_list l = create_list(N);
  long posts[N];

  // inicialização do posts a 0
  for(int i = 0; i < N ; i++){
    posts[i] = 0;
  }

  for (int i = 0; i < N ; i++){ // inicialização da lista
    set_list(l,i,0); // tem os id's das perguntas
  }
  
  int contador = 0;
  GList* glista = get_date_posts(com);
  glista = g_list_last(glista);
 
  while(glista != NULL && contador < N){
    if (get_post_type_id(glista->data) == 1){ // se é pergunta
      
      char* ret;
      ret = strstr((const char *) get_title(glista->data),word);
      
      if (ret!=NULL) { // se o titulo contem a palavra
        posts[contador] = get_key_id_post(glista->data);
        contador++;
      }
    }
    glista = g_list_previous(glista);
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