#include <stdio.h>
#include <string.h>
#include "list.h"
#include "tcd.h"
#include "posts.h"
#include "utilizador.h"
#include "funcoes.h"

// query 9

LONG_list both_participated(TAD_community com, long id1, long id2, int N){

  LONG_list l = create_list(N);
  int contador = 0;
  GList* glista1 = NULL;
  GList* glista2 = NULL;
  GList* g_date_posts1 = NULL;
  GList* g_date_posts2 = NULL;

  for (int i=0; i < N ; i++){ // inicialização da lista
    set_list(l,i,0);
  }

  // vai buscar os valores de cada utilizador
  UTILIZADOR value_user1 = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) id1);
  UTILIZADOR value_user2 = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) id2);

  // coloca numa nova lista os valores dos posts, do utilizador 1
  g_date_posts1 = get_posts_frequentados(value_user1);

  while(g_date_posts1 != NULL){
      POSTS value_post = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) ((long)g_date_posts1->data));
      if(value_post != NULL) // existem provavelmente parent_id que são NULL
          glista1 = g_list_insert(glista1, (gpointer) value_post, 0);
      g_date_posts1 = g_list_next(g_date_posts1);
  }
  glista1 = g_list_sort(glista1, compara_strings);
  printf("cheguei\n");

  // coloca numa nova lista os valores dos posts, do utilizador 2
  g_date_posts2 = get_posts_frequentados(value_user2);
  while(g_date_posts2 != NULL){
      POSTS value_post = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) ((long)g_date_posts2->data));
      if(value_post != NULL) // existem provavelmente parent_id que são NULL
          glista2 = g_list_insert(glista2, (gpointer) value_post, 0);
      g_date_posts2 = g_list_next(g_date_posts2);
  }
  glista2 = g_list_sort(glista2, compara_strings);

  // neste momento as glists estao ordenadas do mais antigo ao mais recente
  // devemos começar pelo último
  
  glista1 = g_list_last(glista1);
  while(glista1 != NULL && contador < N){
      GList* res = g_list_find(glista2, glista1->data);
      if(res != NULL){
          set_list(l,contador,get_key_id_post(glista1->data));
          contador++;
      }
      glista1 = g_list_previous(glista1);
  }
  
  // teste
  for(int i = 0; i < N ; i++){
    printf("%ld\n", get_list(l,i));
  }

  return l;
}