#include <stdio.h>
#include <string.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "query4.h"

// query 4

LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end){

  GList* gl = get_date_posts(com);
  GList* glista = gl;
  GList* res = NULL;

  while(glista != NULL){

    // testa se é pergunta
    if (get_post_type_id(glista->data) == 1){

      // testa se está dentro das datas
      if(difDatas(get_data(glista->data),begin,end) == 0){
          
          // coloca numa glist auxilizar as tags do post
          GList* tag_aux = get_tags(glista->data);
          while(tag_aux != NULL){

            // testa se a tag dada e igual à da lista
            if(strcmp(tag,tag_aux->data) == 0){

                // coloca-se na glist res o post e sai-se do ciclo
                res = g_list_prepend(res, (gpointer) glista->data);
                break;
            }

            tag_aux = g_list_next(tag_aux);
          }
      }
    }
    glista = g_list_next(glista);
  }
  // neste momento 'res' está ordenada do mais recente para o mais antigo

  // cria-se uma lista do tamanho da glist
  LONG_list l = create_list(g_list_length(res));

  int contador = 0;

  while(res != NULL){ // inicialização da lista
    set_list(l,contador,get_key_id_post(res->data)); // vai conter os numeros das perguntas
    res = g_list_next(res);
    contador++;
  }

  // para testar
  for(int i = 0; i < contador; i++){
    printf("POST_ID: %ld\n", get_list(l,i) );
  }

  return l;
}