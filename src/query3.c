#include <stdio.h>
#include "pair.h"
#include "tcd.h"
#include "funcoes.h"
#include "query3.h"

// query 3

LONG_pair total_posts(TAD_community com, Date begin, Date end){
// devolve o numero total de perguntas e o numero total de respostas
  
  LONG_pair par = create_long_pair(0,0);
  GList* glista = get_date_posts(com);

  while (glista != NULL) {
    if (difDatas(get_data(glista->data),begin,end) == 0) {
      if(get_post_type_id(glista->data) == 1) set_fst_long(par,get_fst_long(par)+1); // se for pergunta
      else set_snd_long(par,get_snd_long(par)+1); // se for resposta
    }
    glista = g_list_next(glista);
  }

  printf("perguntas: %ld\n", get_fst_long(par));
  printf("respostas: %ld\n", get_snd_long(par));
  return par;
}