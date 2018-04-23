#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "posts.h"
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
