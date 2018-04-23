#include <stdio.h>
#include "user.h"
#include "tcd.h"
#include "posts.h"

// query 5

USER get_user_info(TAD_community com, long id){

  long posts[10] = {0};
  USER new_user = create_user(NULL,posts);
  UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) id);
  
  if(value_user == NULL){
    printf("Não existe utilizador com o id %ld\n", id );
    return new_user;
  }
  
  char* nbio = get_bio_utilizador(value_user);
  int contador = 0;
  GList* glista = get_date_posts(com);
  glista = g_list_last(glista);

  while(glista != NULL && contador < 10){
    if(get_owner_user_id(glista->data) == id){
      posts[contador] = get_key_id_post(glista->data);
      contador++;
    }
    glista = g_list_previous(glista);
  }

  USER new_user2 = create_user(nbio,posts);
  
  printf("%s\n", nbio);
  for(int i=0;i<10;i++) printf("%ld\n", posts[i]);
    
  return new_user2;
}
