/*
#include <stdio.h>
#include "pair.h"
#include "interface.c"

// query 3

LONG_pair total_posts(TAD_community com, Date begin, Date end){
// devolve o numero total de perguntas e o numero total de respostas
  
  LONG_pair par = create_long_pair(0,0);

  for (int i=0; i<com->posts_t; i++) {
    if (difDatas(com->posts[i]->data,begin,end)==0) {
      if(com->posts[i]->post_type_id==1) set_fst_long(par,get_fst_long(par)+1); // se for pergunta
      else set_snd_long(par,get_snd_long(par)+1); // se for resposta
    }
  }

  printf("perguntas: %ld\n", get_fst_long(par));
  printf("respostas: %ld\n", get_snd_long(par));
  return par;
}
*/