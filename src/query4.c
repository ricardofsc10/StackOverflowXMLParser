#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "posts.h"
#include "funcoes.h"

// query 4

LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end){

  int contador = 0;
  GList* gl = get_date_posts(com);
  GList* glista = gl;
  GList* res = NULL;

  while(glista != NULL){
    if (get_post_type_id(glista->data) == 1){ // se é pergunta

      if(difDatas(get_data(glista->data),begin,end) == 0){ // se está dentro das datas
          
          char* ret;
          ret = strstr((const char *) get_tags(glista->data),tag);

          if (ret!=NULL) // se o titulo contem a palavra
              res = g_list_insert(res, (gpointer) get_key_id_post(glista->data),0);
      }
    }
    glista = g_list_next(glista);
  }

  LONG_list l = create_list(g_list_length(res));

  while(res != NULL){ // inicialização da lista
    set_list(l,contador,(long)res->data); // vai conter os numeros das perguntas
    res = g_list_next(res);
    contador++;
  }

  // para testar
  for(int i = 0; i < contador; i++){
    printf("POST_ID: %ld\n", get_list(l,i) );
  }

  return l;
}