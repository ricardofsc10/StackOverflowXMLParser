#include <stdio.h>
#include "tcd.h"
#include "query10.h"

// query 10

long better_answer(TAD_community com, long id){
  
  POSTS p = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) id);
  
  // testa possiveis casos de erro
  if(p == NULL){
      printf("Não existe nenhum post com o id = %ld.\n",id );
      return 0;
  }
  if(get_post_type_id(p) == 2){
      printf("O Id passado corresponde a uma resposta.\n");
      return 0;
  }

  int melhor_media = 0, melhor_id = 0;
  int media;

  GList* gl = g_hash_table_get_values(get_posts(com));
  GList* glista;
  

  for(glista = gl; glista!=NULL; glista = g_list_next(glista)){

    if(get_parent_id(glista->data) == id){
      
      UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) get_owner_user_id(glista->data));

      media = (0.65 * get_score(glista->data)) + (0.25 * get_reputacao(value_user)) + (0.1 * get_comment_count(glista->data));
    
      if (media>melhor_media){
        melhor_media = media;
        melhor_id = get_key_id_post(glista->data);
      } 
    }
  }

  printf("ID melhor resposta (valor de retorno): %d\n", melhor_id);
  printf("média: %d\n", melhor_media);

  return melhor_id;
}