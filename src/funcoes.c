#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tcd.h"
#include "tag_unique.h"
#include "funcoes.h"

// funções auxiliares mais tarde para serem postas noutro ficheiro

int difDatas(Date x,Date begin, Date end) { // 0 ou -1 se está entre as datas ou n
    int inicio = 0,fim;
    if(get_year(x) < get_year(begin)) inicio=-1;
    else {
        if (get_year(x) == get_year(begin)) {
            if (get_month(x) < get_month(begin)) inicio=-1;
            else {
                if (get_month(x) == get_month(begin)) {
                    if (get_day(x) < get_day(begin)) inicio= -1;
                    else inicio= 0;
                }
                else inicio = 0;
            }
        }
        else inicio = 0;
    }

    if(get_year(x) > get_year(end)) fim=-1;
    else {
        if (get_year(x) == get_year(end)) {
            if (get_month(x) > get_month(end)) fim =-1;
            else {
                if (get_month(x) == get_month(end)) {
                    if (get_day(x) > get_day(end)) fim = -1;
                    else fim = 0;
                }
                else fim = 0;
            }
        }
        else fim = 0;
    }
    
    if (inicio== 0 && fim ==0) return 0;
    else return -1;
}

gint compara_strings(gconstpointer a, gconstpointer b) { // Compara duas strings
  return strcmp( get_data_string( (POSTS) a) , get_data_string( (POSTS) b) ) ;
}

gint compara_votes(gconstpointer a, gconstpointer b) { // Compara duas strings
  return (get_dif_votes( (POSTS) a) > get_dif_votes( (POSTS) b) ) ? -1 : 1 ;
}

gint compara_answer(gconstpointer a, gconstpointer b) { // Compara duas strings
  return (get_answer_count( (POSTS) a) > get_answer_count( (POSTS) b) ) ? -1 : 1 ;
}

gint compara_posts_u(gconstpointer a, gconstpointer b){
    return (get_posts_u( (UTILIZADOR) a) > get_posts_u( (UTILIZADOR) b) ) ? -1 : 1 ;
}

gint compara_reputacao(gconstpointer a, gconstpointer b){
    return (get_reputacao( (UTILIZADOR) a) > get_reputacao( (UTILIZADOR) b) ) ? -1 : 1 ;
}

gint compara_ocorrencias(gconstpointer a, gconstpointer b){
    return (get_ocorrencias( (TAG_UNIQUE) a) > get_ocorrencias( (TAG_UNIQUE) b) ) ? -1 : 1 ;
}

Date stringToDias (char* data) { // "2011-11-11"
    char ano[5];
    char mes[3];
    char dia[3];
    int i,j;
    for (i=0,j=0;i<4;i++,j++)
        ano[j]=data[i];
        ano[j]='\0';
    for(i=5,j=0; i<7;i++,j++)
        mes[j]=data[i];
        mes[j]='\0';
    for(i=8,j=0; i<10;i++,j++)
        dia[j]=data[i];
        dia[j]='\0';
    Date ndata = createDate (atoi(dia),atoi(mes),atoi(ano));
    return ndata;
}

void strToTag (POSTS value_post, const char* str){
  char *token, *cp;
  const char delim[] = "<>"; //caracteres em que a string é dividida
  cp = mystrdup (str);

  token = strtok (cp ,delim);
  while (token != NULL){
      set_tags(value_post, token);
      token = strtok (NULL, delim);
  }
}


LONG_list remove_trash(LONG_list l, int N){
  int i;
  for(i = 0; i < N; i++){
      if (get_list(l,i) == 0) break;
  }

  LONG_list aux = create_list(i);
  for(int j = 0 ; j < i ; j++){
      set_list(aux, j, get_list(l, j));
  }
  return aux;
}
