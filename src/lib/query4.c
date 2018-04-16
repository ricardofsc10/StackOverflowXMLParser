#include <stdio.h>
#include "list.h"
#include "interface.c"

// query 4

LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end){
  LONG_list l = create_list(50);
  LONG_list res = create_list(50);
  int k=0;


  for (int i=0; i < 50 ; i++){ // inicialização da lista
    set_list(l,i,0); // vai conter os numeros das perguntas
    set_list(res,i,0); // lista q vai ser devolvida
  }

  for(int i=0; i < com->posts_t ; i++){
    if (com->posts[i]->post_type_id == 1){ // se é pergunta

      if(difDatas(com->posts[i]->data,begin,end) == 0){ // se está dentro das datas
          
          char* ret;
          ret = strstr((const char *) com->posts[i]->tags,tag);
          if (ret!=NULL) { // se o titulo contem a palavra
            set_list(l,k,com->posts[i]->id_post);
            k++;
          }
        }
      }
    }

  // no fim do 'for' a lista l tem os id's dos posts por ordem crescente, necessário inverter a ordem
  int j = 50-1;
  for (int i = 0 ; i < 50 ; i++){
    set_list(res, i, get_list(l, j)); 
    j--;
  }

  /*
  // para testar
  j = 50-1;
  for(int i = 0; i < 50; i++){
    printf("POST_ID: %ld\n", get_list(res,i) );
    j--;
  }
  */

  free_list(l);

  return res;
}