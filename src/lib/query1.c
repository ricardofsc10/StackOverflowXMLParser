#include <stdio.h>
#include "user.h"
#include "interface.c"

// query 1

STR_pair info_from_post(TAD_community com, long id) {
  STR_pair par= create_str_pair(NULL,NULL);
  int user_id;
  int l;

    l = 0;//procura_binaria_p(com, id, com->posts_t); // indice do array posts onde esta o post com o id dado

  if (com->posts[l]->post_type_id == 1){  
    set_fst_str(par, (char *) com->posts[l]->title);
    user_id = 0;//procura_binaria_u(com, com->posts[l]->owner_user_id, com->n_utilizadores);
    set_snd_str(par, (char *) com->utilizador[user_id]->nome);
    }
  else { //é uma resposta
    int x = 0;//procura_binaria_p(com, com->posts[l]->parent_id, com->posts_t);
    set_fst_str(par, (char *) com->posts[x]->title);
    user_id= 0;//procura_binaria_u(com, com->posts[x]->owner_user_id, com->n_utilizadores);
    set_snd_str(par, (char *) com->utilizador[user_id]->nome);
  }
    printf("Título: %s\n", get_fst_str(par) );
    printf("Nome de utilizador: %s\n", get_snd_str(par) );
  return par;
}