#include <stdio.h>
#include "pair.h"
#include "tcd.h"
#include "query1.h"

// query 1

STR_pair info_from_post(TAD_community com, long id) {
  STR_pair par= create_str_pair(NULL,NULL);

  gboolean g = g_hash_table_contains(get_posts(com), (gpointer) id);

  if(g == TRUE){ // se o post está na tabela referente aos posts
    
    POSTS value_post = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) id);

    if (get_post_type_id(value_post) == 1){  
      set_fst_str(par, (char *) get_title(value_post));

      long owner_user_id = get_owner_user_id(value_post);
      UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) owner_user_id);
      
      set_snd_str(par, (char *) get_nome(value_user));
      }
    else { //é uma resposta
      long parent_id = get_parent_id(value_post);
      POSTS value_post2 = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) parent_id);

      set_fst_str(par, (char *) get_title(value_post2));

      long owner_user_id = get_owner_user_id(value_post2);
      UTILIZADOR value_user2 = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) owner_user_id);
      set_snd_str(par, (char *) get_nome(value_user2));
    }
  }

  printf("Título: %s\n", get_fst_str(par));
  printf("Nome de utilizador: %s\n", get_snd_str(par) );
  
  return par;
}