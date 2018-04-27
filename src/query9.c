#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"

// query 9

LONG_list both_participated(TAD_community com, long id1, long id2, int N){

  // vai buscar os valores de cada utilizador
  UTILIZADOR value_user1 = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) id1);
  UTILIZADOR value_user2 = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) id2);

  // testa se ambos os valores foram encontrados
  if(value_user1 == NULL || value_user2 == NULL){
      LONG_list l = create_list(0);
      if (value_user1 == NULL && value_user2 == NULL){
          printf("Nenhum dos User's introduzidos existe, tente outros.\n");
          return l;
      }
      if(value_user1 == NULL && value_user2 != NULL){
          printf("O User1 nao existe.\n");
          return l;
      }
      if(value_user1 != NULL && value_user2 == NULL){
          printf("O User2 nao existe.\n");
          return l;
      }
  }

  GList* glista1 = NULL;
  GList* glista2 = NULL;
  GList* g_date_posts1 = NULL;
  GList* g_date_posts2 = NULL;

  // coloca numa nova lista os valores dos posts, do utilizador 1
  g_date_posts1 = get_posts_frequentados(value_user1);

  while(g_date_posts1 != NULL){
      POSTS value_post = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) ((long)g_date_posts1->data));
      if(value_post != NULL) // existem provavelmente parent_id que são NULL
          glista1 = g_list_prepend(glista1, (gpointer) value_post);
      g_date_posts1 = g_list_next(g_date_posts1);
  }
  glista1 = g_list_sort(glista1, compara_strings);

  // coloca numa nova lista os valores dos posts, do utilizador 2
  g_date_posts2 = get_posts_frequentados(value_user2);
  while(g_date_posts2 != NULL){
      POSTS value_post = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) ((long)g_date_posts2->data));
      if(value_post != NULL) // existem provavelmente parent_id que são NULL
          glista2 = g_list_prepend(glista2, (gpointer) value_post);
      g_date_posts2 = g_list_next(g_date_posts2);
  }
  glista2 = g_list_sort(glista2, compara_strings);

  // neste momento as glists estao ordenadas do mais antigo ao mais recente

  LONG_list l = create_list(N);
  for (int i=0; i < N ; i++){ // inicialização da lista
    set_list(l,i,0);
  }

  int contador = 0;

  // devemos começar pelo último
  glista1 = g_list_last(glista1);

  while(glista1 != NULL && contador < N){

      // g_list_find procura na glista2 o valor glista1->data
      GList* res = g_list_find(glista2, glista1->data);
      if(res != NULL){
          set_list(l,contador,get_key_id_post(glista1->data));
          contador++;
      }
      glista1 = g_list_previous(glista1);
  }
  
  LONG_list aux = remove_trash(l, contador);

  // para testar
  for(int i = 0; i < contador; i++){
    if( (void*) get_list(aux,i) == NULL) break;
    printf("POST_ID: %ld\n", get_list(aux,i) );
  }

  // free das estruturas auxiliares
  free_list(l);

  return aux;
}