/*

#include <stdio.h>
#include "user.h"
#include "interface.c"

// query 5

USER get_user_info(TAD_community com, long id){


  int id_bin = 0; //procura_binaria_u(com, id, com->n_utilizadores);
  char* nbio = get_bio(com->utilizador[id_bin]->user);

  long posts[10] = {0};
  long temp;
  int i,j;

  for(i=0;i<com->posts_t;i++){
    if (com->posts[i]->owner_user_id == id){
      for(j=8;j>=0;j--){
        temp = posts[j+1];
        posts[j+1] = posts[j];
        posts[j] = temp;
      }
      posts[0] = com->posts[i]->id_post;
    }
  }

  USER new_user = create_user(nbio,posts);
  
  printf("%s\n", nbio);
  for(i=0;i<10;i++) printf("%ld\n", posts[i]);
    
  return new_user;
}
*/