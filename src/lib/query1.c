#include <stdio.h>
#include "pair.h"
#include "tcd.h"
#include "utilizador.h"
#include "posts.h"
#include "query1.h"



// query 1

STR_pair info_from_post(TAD_community com, long id) {
  STR_pair par= create_str_pair(NULL,NULL);
  int* id_l = (int*) id;

  POSTS value_post = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) id_l);

  if (get_post_type_id(value_post) == 1){  
    set_fst_str(par, (char *) get_title(value_post));
    UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) get_owner_user_id(value_post));
    set_snd_str(par, (char *) get_nome(value_post));
    }
  else { //é uma resposta
    POSTS value_post2 = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) get_parent_id(value_post2));
    set_fst_str(par, (char *) get_title(value_post2));
    UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) get_owner_user_id(value_post2));
    set_snd_str(par, (char *) get_nome(value_post2));
  }
    printf("Título: %s\n", get_fst_str(par));
    printf("Nome de utilizador: %s\n", get_snd_str(par) );
  return par;
}