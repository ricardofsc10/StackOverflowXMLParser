#include <stdio.h>
#include <string.h>
#include "list.h"
#include "tcd.h"
#include "posts.h"
#include "utilizador.h"

// query 9

gint compara_posts_frequentados(gconstpointer a, gconstpointer b) { // Compara duas strings
  return strcmp( get_data_string( (POSTS) a) , get_data_string( (POSTS) b) ) ;
}

LONG_list both_participated(TAD_community com, long id1, long id2, int N){

  LONG_list l = create_list(N);
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
      POSTS post = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) get_key_id_post(g_date_posts1->data));
      glista1 = g_list_insert(glista1, (gpointer) post, 0);
      g_date_posts1 = g_list_next(g_date_posts1);
  }
  glista1 = g_list_sort(glista1, compara_posts_frequentados);

  // coloca numa nova lista os valores dos posts, do utilizador 2
  g_date_posts2 = get_posts_frequentados(value_user2);
  while(g_date_posts2 != NULL){
      POSTS post = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) get_key_id_post(g_date_posts2->data));
      glista2 = g_list_insert(glista2, (gpointer) post, 0);
      g_date_posts2 = g_list_next(g_date_posts2);
  }
  glista2 = g_list_sort(glista2, compara_posts_frequentados);


  /*
  int id1_bin = procura_binaria_u(com,id1,com->n_utilizadores);
  int id2_bin = procura_binaria_u(com,id2,com->n_utilizadores);

  for(int i = com->utilizador[id1_bin]->contador_posts_frequentados-1 ; i >= 0 ; i--){
      printf("%d: %d\n", i, com->utilizador[id1_bin]->posts_frequentados[i]);
      
      for(int j = com->utilizador[id2_bin]->contador_posts_frequentados; j >= 0; j--){
        
        if(com->utilizador[id1_bin]->posts_frequentados[i] == com->utilizador[id2_bin]->posts_frequentados[j]){
          set_list(l,contador,com->utilizador[id1_bin]->posts_frequentados[i]);
          contador++;
          printf("%d\n", com->utilizador[id1_bin]->posts_frequentados[i] );
          break;
        }
      }
      if(contador == N) break;
  }
  for(int i = com->utilizador[id2_bin]->contador_posts_frequentados-1 ; i >= 0 ; i--){
      printf("%d: %d\n", i, com->utilizador[id2_bin]->posts_frequentados[i]);
  }

  
  for(int i= (com->posts_t - 1) ; i >= 0 && contador < N ; i--){ // percorre os posts a começar pelo fim
    if(com->posts[i]->post_type_id == 1){ // vê se é pergunta
      int x1=0,x2=0;

      // para o caso de ser o id1 a fazer a pergunta
      if(com->posts[i]->owner_user_id == id1){
        x1=1;
        for(int j=i; j<com->posts_t; j++){ // percorre o resto dos posts
          if(com->posts[j]->parent_id == com->posts[i]->id_post){ // verifica se o parent_id é igual ao da pergunta em análise
            if(com->posts[j]->owner_user_id == id2){
              x2=1;
              break; // assim nao avança para o resto dos posts
            }
          }
        }
        // verifica se os dois participam na questão
        if (x1==1 && x2==1){
          set_list(l,contador,com->posts[i]->id_post);
          contador++;
        }
      }
      else {
        // para o caso de ser o id2 a fazer a pergunta
        if(com->posts[i]->owner_user_id == id2){
          x2=1;
          for(int j=i; j<com->posts_t; j++){ // percorre o resto dos posts
            if(com->posts[j]->parent_id == com->posts[i]->id_post){ // verifica se o parent_id é igual ao da pergunta em análise
              if(com->posts[j]->owner_user_id == id1){
                x1=1;
                break; // assim nao avança para o resto dos posts
              }
            }
          }
          // verifica se os dois participam na questão
          if (x1==1 && x2==1){
            set_list(l,contador,com->posts[i]->id_post);
            contador++;
          }
        }
        else{
          //para quando nao e nenhum a fazer a pergunta, só podem interagir nas respostas
          for(int j=i; j<com->posts_t; j++){ // percorre o resto dos posts
            if(com->posts[j]->parent_id == com->posts[i]->id_post){ // verifica se o parent_id é igual ao da pergunta em análise
              if(com->posts[j]->owner_user_id == id2) x2=1;
              if(com->posts[j]->owner_user_id == id1) x1=1;

              // verifica se os dois participam na questão
              if (x1==1 && x2==1){
                set_list(l,contador,com->posts[i]->id_post);
                contador++;
                break;
              }
            }
          }
        }
        }
    }
  }*/
  
  // teste
  for(int i = 0; i < N ; i++){
    printf("%ld\n", get_list(l,i));
  }

  return l;
}