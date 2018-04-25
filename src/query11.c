#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "tag_unique.h"
#include "query11.h"

// query 11

LONG_list most_used_best_rep(TAD_community com, int N, Date begin, Date end){

  GList* gl = g_hash_table_get_values(get_utilizador(com));
  GList* glista = gl;

  glista = g_list_sort(glista, compara_reputacao); // ordenada por reputação
  
  GList* aux = NULL;

  int i = 0;
  while(glista != NULL && i < N){
    aux = g_list_append(aux, (gpointer) glista->data);
    i++;
    glista = g_list_next(glista);
  }
  // em aux contem os N utilizadores com melhor prestação (UTILIZADOR), do de maior para o de menor

  GHashTable* todas_tags = g_hash_table_new(g_str_hash, g_str_equal);

  // percorre os utilizadores em aux e todas as suas perguntas
  while(aux != NULL){
    //printf("                   utilizador: %ld\n",get_key_id(aux->data));

    GList* posts_perguntas = get_posts_perguntas(aux->data);
    while(posts_perguntas != NULL){

      // verifica se o post está dentro da data
      if(difDatas(get_data(posts_perguntas->data),begin,end) == 0){
          //printf("    pergunta: %ld\n", get_key_id_post(posts_perguntas->data));

          // tags contem as tagas do post em questão
          GList* tags = get_tags(posts_perguntas->data);

          /*// teste
          GList* new_tag = tags;
          while(new_tag != NULL){
              printf("%s\n", new_tag->data );
              new_tag = g_list_next(new_tag);
          }*/

          while(tags != NULL){

              // coloca em aux_tag o valor encontrado
              TAG_UNIQUE aux_tag = (TAG_UNIQUE) g_hash_table_lookup(todas_tags, (gpointer) tags->data);

              // testa se a tag ja existe na hash de todas as tags
              if( (void*) aux_tag == NULL){

                  // se nao existe a chave entao insere na tabela com uma ocorrencia
                  TAG_UNIQUE new = create_tag_unique();
                  set_key_tag_unique_name(new, tags->data);
                  set_ocorrencias(new, 1);
                  g_hash_table_insert(todas_tags, (gpointer) tags->data, (gpointer) new);

                  //printf("nao existo: %s\n", tags->data );
              }
              else{

                  g_hash_table_remove(todas_tags, (gpointer) tags->data);
                  // se ja existe substitui pelo num_ocorrencias + 1
                  TAG_UNIQUE new = create_tag_unique();
                  set_key_tag_unique_name(new, tags->data);
                  int ocorrencias = get_ocorrencias(aux_tag);
                  set_ocorrencias(new, (ocorrencias + 1) );
                  g_hash_table_replace(todas_tags, (gpointer) tags->data, (gpointer) new);

                  //printf("existo: %s\n", tags->data );
              }
              tags = g_list_next(tags);
          }
      }
      posts_perguntas = g_list_next(posts_perguntas);
    }
    aux = g_list_next(aux);
  }
  // neste momento a GHashTable* todas_tags, contem todas as tags usadas bem como o numero de ocorrencias

  // em values estao todos os valores da tabela de hash tags
  GList* values = g_hash_table_get_values(todas_tags);

  // ordena pelas ocorrencias
  values = g_list_sort(values, compara_ocorrencias);

  /*
  while(values != NULL){
    printf("%ld\n", get_ocorrencias(values->data));
    printf("%s\n", get_key_tag_unique_name(values->data));
    values = g_list_next(values);
  }
  */
  
  
  
  LONG_list l = create_list(g_list_length(values));
  int j=0;
  while(values != NULL && j < N){
    printf("tag_unique: %s\n", get_key_tag_unique_name(values->data));
    TAG value_tag = (TAG) g_hash_table_lookup(get_tag(com), (gpointer) get_key_tag_unique_name(values->data));
    
    printf("tag: %s\n", get_key_tag_name(value_tag));
    if(get_key_tag_name(value_tag) != NULL){
      printf("%ld\n", get_id_tag(value_tag));
      set_list(l,j,get_id_tag(value_tag));
      j++;
    }
    values = g_list_next(values);
  }


  /*
  POSTS post = (POSTS)g_hash_table_lookup(get_posts(com), (gpointer) 187278);
  GList* ultimo = get_tags(post);
  GList* aux_ultimo = ultimo;
  while(aux_ultimo != NULL){
    printf("%s\n", aux_ultimo->data );
    aux_ultimo = g_list_next(aux_ultimo);
  }*/

  /*
  // deixei aqui para se testar se for preciso
  for(int i=0; i<N; i++){
    if( (void*) get_list(l,i) == NULL) break;
    printf("%dº: id utilizador: %ld\n\n", i+1, get_list(l,i));
  }
  */

  return l;
}