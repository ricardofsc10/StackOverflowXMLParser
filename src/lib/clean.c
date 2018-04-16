#include "interface.c"

// clean

TAD_community clean(TAD_community com){
  
  for (int i=0;i<com->n_utilizadores; i++) {

      free(com->utilizador[i]->nome);
      free(&(com->utilizador[i]->id));
      free(com->utilizador[i]->user);
      free(&(com->utilizador[i]->reputacao));
      free(&(com->utilizador[i]->posts_u));
      free(com->utilizador[i]);
      free(com->utilizador);
 }

 free(com->utilizador);

  for(int i=0;i<com->posts_t;i++) {
      free(com->posts[i]->data);

      free(com->posts[i]->title);
      free(com->posts[i]->body);
    
      free(com->posts[i]->tags);
    
      free(com->posts[i]->favorite_count);
  
      free(com->posts[i]);
  }
  free(com->posts);
 
  return com;
}