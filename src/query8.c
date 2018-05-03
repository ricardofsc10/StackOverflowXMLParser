#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "debug.h"
#include "query8.h"

// query 8

LONG_list contains_word(TAD_community com, char* word, int N){
  
  long posts[N];

  // inicialização do posts a 0
  for(int i = 0; i < N ; i++){
    posts[i] = 0;
  }

  GList* glista = get_date_posts(com);
  glista = g_list_last(glista);
 
  int contador = 0;

  while(glista != NULL && contador < N){
    if (get_post_type_id(glista->data) == 1){ // se é pergunta
      
      char* ret;

      char* cp = get_title(glista->data);

      ret = strstr((const char *) cp,word);

      free(cp);
      
      if (ret!=NULL) { // se o titulo contem a palavra
        posts[contador] = get_key_id_post(glista->data);
        contador++;
      }
    }
    glista = g_list_previous(glista);
  }

  LONG_list l = create_list(contador);

  for(int i = 0; i< contador ; i++){
      set_list(l,i,posts[i]);
  }
  
  // para testar
  for(int i = 0; i < contador; i++){
    PRINT(printf("POST_ID: %ld\n", get_list(l,i) ));
  }

  return l;
}