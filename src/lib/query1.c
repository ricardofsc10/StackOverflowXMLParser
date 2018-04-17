#include <stdio.h>
#include "interface.c"
#include "query1.h"

// query 1

STR_pair info_from_post(TAD_community com, long id) {
  STR_pair par= create_str_pair(NULL,NULL);
  int* id_l = id;

  POSTS value_post = (POSTS) g_hash_table_lookup(com->posts, (gpointer) id_l);

  if (value_post->post_type_id == 1){  
    set_fst_str(par, (char *) value_post->title);
    UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(com->utilizador, (gpointer) value_post->owner_user_id);
    set_snd_str(par, (char *) value_user->nome);
    }
  else { //é uma resposta
    POSTS value_post2 = g_hash_table_lookup(com->posts, (gpointer) value_post->parent_id);
    set_fst_str(par, (char *) value_post2->title);
    UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(com->utilizador, (gpointer) value_post2->owner_user_id);
    set_snd_str(par, (char *) value_user->nome);
  }
    printf("Título: %s\n", get_fst_str(par) );
    printf("Nome de utilizador: %s\n", get_snd_str(par) );
  return par;
}