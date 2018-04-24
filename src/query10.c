#include <stdio.h>
#include "tcd.h"
#include "query10.h"

// query 10

long better_answer(TAD_community com, long id){
  

  int melhor_media = 0, melhor_id = 0;
  int media;

  GList* gl = g_hash_table_get_values(get_posts(com));
  GList* glista;
  

  for(glista = gl; glista!=NULL; glista = g_list_next(glista)){

    if(get_parent_id(glista->data) == id){
      
      UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) get_owner_user_id(glista->data));

      media = (0.45 * get_score(glista->data)) + (0.25 * get_reputacao(value_user)) + (0.2 * get_dif_votes(glista->data)) + (0.1 * get_comment_count(glista->data));
    
      if (media>melhor_media){
        melhor_media = media;
        melhor_id =get_key_id_post(glista->data);
      } 
    }
  }
  printf("ID melhor resposta: %d\n", melhor_id);
  printf("média: %d\n", melhor_media);
  return melhor_id;
}