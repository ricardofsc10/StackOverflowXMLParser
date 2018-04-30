#include <stdio.h>
#include <stdlib.h>
#include "pair.h"
#include "tcd.h"
#include "query1.h"

// query 1

STR_pair info_from_post(TAD_community com, long id) {
  STR_pair par= create_str_pair(NULL,NULL);

  gboolean g = g_hash_table_contains(get_posts(com), (gpointer) id);

  if(g == TRUE){ // se o post está na tabela referente aos posts

    char *n_title, *n_name, *n_title2, *n_name2;
    
    POSTS value_post = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) id);

    if (get_post_type_id(value_post) == 1){ 

      n_title = get_title(value_post);
      set_fst_str(par, n_title);

      long owner_user_id = get_owner_user_id(value_post);
      UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) owner_user_id);
      
      n_name = get_nome(value_user);
      set_snd_str(par, n_name);
      }
    else { //é uma resposta
      long parent_id = get_parent_id(value_post);
      POSTS value_post2 = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) parent_id);

      n_title = get_title(value_post2);
      set_fst_str(par, n_title);

      long owner_user_id = get_owner_user_id(value_post2);
      UTILIZADOR value_user2 = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) owner_user_id);

      n_name = get_nome(value_user2);
      set_snd_str(par, n_name);
    }

    n_title2 = get_fst_str(par);
    printf("Título: %s\n",n_title2 );
    n_name2 = get_snd_str(par);
    printf("Nome de utilizador: %s\n", n_name2);
  
    free(n_title);
    free(n_title2);
    free(n_name);
    free(n_name2);

    return par;
  }
  else{
    printf("Não existe um post com o Id passado\n");
    return par;
  }
}