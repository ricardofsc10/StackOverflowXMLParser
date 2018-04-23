#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "posts.h"
#include "funcoes.h"

// query 4

LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end){
  LONG_list l = create_list(50);
  long posts[50];

  for(int i = 0; i < 50 ; i++){
    posts[i] = 0;
  }

  for (int i=0; i < 50 ; i++){ // inicialização da lista
    set_list(l,i,0); // vai conter os numeros das perguntas
  }

  int contador = 0;
  GList* gl = get_date_posts(com);
  GList* glista = gl;

  while(glista != NULL && contador < 50){
    if (get_post_type_id(glista->data) == 1){ // se é pergunta

      if(difDatas(get_data(glista->data),begin,end) == 0){ // se está dentro das datas
          
          char* ret;
          ret = strstr((const char *) get_tags(glista->data),tag);

          if (ret!=NULL) { // se o titulo contem a palavra
            posts[contador] = get_key_id_post(glista->data);
            contador++;
          }
        }
      }
      glista = g_list_previous(glista);
    }
  
  for(int i = 0; i < 50 ; i++){
    set_list(l,i,posts[i]);
  }

  // para testar
  for(int i = 0; i < 50; i++){
    printf("POST_ID: %ld\n", get_list(l,i) );
  }

  return l;
}