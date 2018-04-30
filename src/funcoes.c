#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tcd.h"
#include "tag_unique.h"
#include "funcoes.h"

// funções auxiliares mais tarde para serem postas noutro ficheiro

int difDatas(Date x,Date begin, Date end) {
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
    
    if (inicio == 0 && fim == 0) return 0; // está entre
    if (inicio == -1 && fim == 0) return -1; // está antes do intervalo
    if (inicio == 0 && fim == -1) return 1; // está depois do intervalo
    else return 2; // situação anormal
}

gint compara_strings(gconstpointer a, gconstpointer b) { // Compara duas strings
  char* na = get_data_string( (POSTS) a);
  char* nb = get_data_string( (POSTS) b);
  int temp = strcmp( na , nb ) ;
  free(na);
  free(nb);
  return temp;
}

gint compara_score(gconstpointer a, gconstpointer b) { // Compara dois scores
  return (get_score( (POSTS) a) > get_score( (POSTS) b) ) ? -1 : 1 ;
}

gint compara_answer(gconstpointer a, gconstpointer b) { // Compara dois answer_count
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

void free_table_utilizador(gpointer key, gpointer value, gpointer user_data){
    free_utilizador(value);
}

void free_table_posts(gpointer key, gpointer value, gpointer user_data){
    free_posts(value);
}

void free_table_tag(gpointer key, gpointer value, gpointer user_data){
    free(key);
    free_tag(value);
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
  free (cp);
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
  free_list(l);
  return aux;
}

char* escolhe_ficheiros(){

  printf("Em quais ficheiros quer testar?\n(1) ubuntu   (2) android\n");
  
  int escolha;
  scanf("%d", &escolha);

  if(escolha == 1){
    char* path = "../../dumpexemplo/ubuntu/";
    return path;
  }
  else{
    char* path = "../../dumpexemplo/android/";
    return path;
  }
}

Date pergunta_data(){
    int dia, mes, ano;
    printf("Dia: ");
    scanf("%d",&dia);
    printf("Mês: ");
    scanf("%d",&mes);
    printf("Ano: ");
    scanf("%d",&ano);
    Date new = createDate(dia, mes, ano);
    return new;
}

void interatividade(TAD_community tda){
  int menu = 0;
  clock_t start,stop;

  while(menu == 0){ // interatividade
    printf("Que questão deseja resolver? (-1, para sair do programa)\n");
    scanf("%d", &menu);

    if(menu == 1){ /////////////////////////////////// feita
      int id;
      printf("Qual o id do post?\n");
      scanf("%d", &id);
      printf("Resposta:\n");
      start = clock();
      STR_pair par = info_from_post(tda,id);
      stop = clock();
      free_str_pair(par);
      menu = 0;
    } 
    if(menu == 2){ /////////////////////////////////// feita
      int tamanho;
      printf("Qual o número de utilizadores que pretende?\n");
      scanf("%d",&tamanho);
      printf("Resposta:\n");
      start = clock();
      LONG_list l = top_most_active(tda,tamanho);
      stop = clock();
      free_list(l);
      menu = 0;
    }
    if(menu == 3){ ///////////////////////////////// feita
      printf("Data de ínicio:\n");
      Date begin = pergunta_data();
      printf("Data de fim:\n");
      Date end = pergunta_data();
      printf("Resposta:\n");
      start = clock();
      LONG_pair lp = total_posts(tda,begin,end);
      stop = clock();
      free_date(begin);
      free_date(end);
      free_long_pair(lp);
      menu = 0;
    }
    if(menu == 4){ /////////////////////////////////// feita
      printf("Data de ínicio:\n");
      Date begin = pergunta_data();
      printf("Data de fim:\n");
      Date end = pergunta_data();
      char tag[50];
      printf("Que tag quer encontrar?\n");
      scanf("%s", tag);
      printf("Resposta:\n");
      start = clock();
      LONG_list l = questions_with_tag(tda, tag, begin, end);
      stop = clock();
      free_date(begin);
      free_date(end);
      free_list(l);
      menu = 0;
    }
    if(menu == 5){ ///////////////////////////////// feita
      int id;
      printf("Qual o Id do utilizador?\n");
      scanf("%d", &id);
      printf("Resposta:\n");
      start = clock();
      USER u = get_user_info(tda,id);
      stop = clock();
      free_user(u);
      menu = 0;
    }
    if(menu == 6){ ////////////////////////////////// feita
      int tamanho;
      printf("Data de ínicio:\n");
      Date begin = pergunta_data();
      printf("Data de fim:\n");
      Date end = pergunta_data();
      printf("Qual o número de respostas que pretende?\n");
      scanf("%d",&tamanho);
      printf("Resposta:\n");
      start = clock();
      LONG_list l = most_voted_answers(tda, tamanho, begin, end);
      stop = clock();
      free_date(begin);
      free_date(end);
      free_list(l);
      menu = 0;
    }
    if(menu == 7){ ////////////////////////////////// feita
      int tamanho;
      printf("Data de ínicio:\n");
      Date begin = pergunta_data();
      printf("Data de fim:\n");
      Date end = pergunta_data();
      printf("Qual o número de utilizadores que pretende?\n");
      scanf("%d",&tamanho);
      printf("Resposta:\n");
      start = clock();
      LONG_list l = most_answered_questions(tda, tamanho, begin, end);
      stop = clock();
      free_date(begin);
      free_date(end);
      free_list(l);
      menu = 0;
    }
    if(menu == 8){ /////////////////////////////////// feita
      int tamanho;
      char palavra[50];
      printf("Que palavra quer encontrar?\n");
      scanf("%s", palavra);
      printf("Qual o número de perguntas que pretende com a palavra '%s'?\n", palavra);
      scanf("%d",&tamanho);
      printf("Resposta:\n");
      start = clock();
      LONG_list l = contains_word(tda, palavra, tamanho);
      stop = clock();
      free_list(l);
      menu = 0;
    }
    if(menu == 9){ ////////////////////////////////// feita
      int tamanho,user1,user2;
      printf("Qual o tamanho do array das perguntas?\n");
      scanf("%d", &tamanho);
      printf("User1:\n");
      scanf("%d", &user1);
      printf("User2:\n");
      scanf("%d", &user2);
      printf("Resposta:\n");
      start = clock();
      LONG_list l = both_participated(tda, user1, user2, tamanho); // 1465 e 16575 / 449, 15811
      stop = clock();
      free_list(l);
      menu = 0;
    }
    if(menu == 10){ ////////////////////////////////// feita
      int id;
      printf("Qual o Id da pergunta?\n");
      scanf("%d", &id);
      printf("Resposta:\n");
      start = clock();
      better_answer(tda,id);
      stop = clock();
      menu = 0;
    }
    if(menu == 11){ ////////////////////////////////// feita
      int tamanho;
      printf("Data de ínicio:\n");
      Date begin = pergunta_data();
      printf("Data de fim:\n");
      Date end = pergunta_data();
      printf("Qual o número de utilizadores que pretende?\n");
      scanf("%d",&tamanho);
      printf("Resposta:\n");
      start = clock();
      LONG_list l = most_used_best_rep(tda,tamanho,begin,end);
      stop = clock();
      free_date(begin);
      free_date(end);
      free_list(l);
      menu = 0;
    }
    if(menu==-1) break;
    printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
  }
}