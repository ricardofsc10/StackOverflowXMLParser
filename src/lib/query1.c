#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "pair.h"
#include "tcd.h"
#include "utilizador.h"
#include "posts.h"
#include "query1.h"



// query 1

STR_pair info_from_post(TAD_community com, long id) {
  STR_pair par= create_str_pair(NULL,NULL);
  int* id_l = malloc(sizeof(int));
  *id_l = id;

  POSTS value_post = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) id_l);

  if (get_post_type_id(value_post) == 1){  
    set_fst_str(par, (char *) get_title(value_post));

    int owner_user_id = (int) get_owner_user_id(value_post);
    int* key = malloc(sizeof(int));
    *key = owner_user_id;
    UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) key);
    
    set_snd_str(par, (char *) get_nome(value_user));
    }
  else { //é uma resposta
    int parent_id = get_parent_id(value_post);
    int* key = malloc(sizeof(int));
    *key = parent_id; 
    POSTS value_post2 = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) key);

    set_fst_str(par, (char *) get_title(value_post2));

    int owner_user_id = get_owner_user_id(value_post2);
    int* key2 = malloc(sizeof(int));
    *key2 = owner_user_id;
    UTILIZADOR value_user2 = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) key2);
    set_snd_str(par, (char *) get_nome(value_user2));
  }
    printf("Título: %s\n", get_fst_str(par));
    printf("Nome de utilizador: %s\n", get_snd_str(par) );
  return par;
}