#include <stdio.h>
#include "interface.c"

// query 10

long better_answer(TAD_community com, long id){
  int melhor_media = 0, melhor_id = 0;
  for(int i=0; i < com->posts_t; i++){
    
    if(com->posts[i]->parent_id == id){
      int media;
      int id_bin = procura_binaria_u (com, com->posts[i]->owner_user_id, com->n_utilizadores);
      
      media = (0.45 * com->posts[i]->score) + (0.25 * com->utilizador[id_bin]->reputacao) + (0.2 * com->posts[i]->dif_votes) + (0.1 * com->posts[i]->comment_count);
    
      if (media>melhor_media){
        melhor_media = media;
        melhor_id = com->posts[i]->id_post;
      }
    }
  }
  // printf("melhor media: %d\n", melhor_media);
  return melhor_id;
}