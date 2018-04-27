#include <stdio.h>
#include "list.h"
#include "tcd.h"
#include "funcoes.h"
#include "tag_unique.h"
#include "query11.h"
#include "common.h"

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

    GList* posts_perguntas = get_posts_perguntas(aux->data);
    while(posts_perguntas != NULL){

      // verifica se o post está dentro da data
      if(difDatas(get_data(posts_perguntas->data),begin,end) == 0){

          // tags contem as tagas do post em questão
          GList* tags = get_tags(posts_perguntas->data);

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
              }
              else{

                  g_hash_table_remove(todas_tags, (gpointer) tags->data);
                  // se ja existe substitui pelo num_ocorrencias + 1
                  TAG_UNIQUE new = create_tag_unique();
                  set_key_tag_unique_name(new, tags->data);
                  int ocorrencias = get_ocorrencias(aux_tag);
                  set_ocorrencias(new, (ocorrencias + 1) );
                  g_hash_table_replace(todas_tags, (gpointer) tags->data, (gpointer) new);
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
  
  // extrai o tamanho correto da lista, só queremos devolver no maximo N
  int tamanho;
  if(g_list_length(values) > N) tamanho = N;
  else tamanho = g_list_length(values);

  // coloca na lista os id's
  LONG_list l = create_list(tamanho);
  int j=0;
  
  while(values != NULL && j < tamanho){

    // procura a tag na estrutura das tags
    TAG value_tag = (TAG) g_hash_table_lookup(get_tag(com), (gpointer)  get_key_tag_unique_name(values->data));
    
    if(get_key_tag_name(value_tag) != NULL){
      set_list(l,j,get_id_tag(value_tag));
      j++;
    }
    values = g_list_next(values);
  }

  // pritf da lista
  for(int i=0; i < tamanho; i++){
    if( (void*) get_list(l,i) == NULL) break;
    printf("%dº tag: %ld\n\n", i+1, get_list(l,i));
  }

  return l;
}