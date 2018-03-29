#include <interface.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
  TAD_community tda = NULL;
  int menu = 0;
  
  tda = init();
  printf("[init.c] Estrutura já foi inicializada...\n");

  char* path1 __unused = "../../dumpexemplo/ubuntu/"; // usa-se o __unused para evitar warnings, se trocar de caminho por __unused no outro
  char* path2 = "../../dumpexemplo/android/";
  printf("[load.c] Ínicio do load...\n");

  clock_t start = clock();
  tda = load(tda, path2);
  clock_t stop = clock();
  
  printf("[load.c] Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) ); // faz-se esta conta pq tempo vem em mili

  while(menu == 0){ // interatividade
    printf("Que questão deseja resolver? (-1, para sair do programa)\n");
    scanf("%d", &menu);

    if(menu == 1){ /////////////////////////////////// erros
      STR_pair par = create_str_pair(NULL,NULL);
      printf("Resposta:\n");
      start = clock();
      par = info_from_post(tda,141044);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      free_str_pair(par);
      menu = 0;
    }
    if(menu == 2){ /////////////////////////////////// feita
      int tamanho;
      printf("Qual o número de utilizadores que pretende?\n");
      scanf("%d",&tamanho);
      printf("Resposta:\n");
      LONG_list l = create_list(tamanho);
      start = clock();
      l = top_most_active(tda,tamanho);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      free_list(l);
      menu = 0;
    }
    if(menu == 3){ ///////////////////////////////// feita
      LONG_pair lp = create_long_pair(0,0);
      Date begin = createDate(03,10,2014);
      Date end = createDate(05,03,2016);
      printf("Resposta:\n");
      start = clock();
      lp = total_posts(tda,begin,end);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      free_long_pair(lp);
      free_date(begin);
      free_date(end);
      menu = 0;
    }
    if(menu == 4){
      printf("Ainda nao está acabada.\n");
      printf("Resposta:\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 5){ ///////////////////////////////// feita
      USER new_user;
      int id;
      printf("Qual o Id do utilizador?\n");
      scanf("%d", &id);
      printf("Resposta:\n");
      start = clock();
      new_user = get_user_info(tda,id);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      free_user(new_user);
      menu = 0;
    }
    if(menu == 6){ ////////////////////////////////// feita
      int tamanho;
      Date begin = createDate(01,01,2010);
      Date end = createDate(31,12,2017);
      printf("Qual o número de utilizadores que pretende?\n");
      scanf("%d",&tamanho);
      LONG_list l = create_list(tamanho);
      printf("Resposta:\n");
      start = clock();
      l = most_voted_answers(tda, tamanho, begin, end);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      free_date(begin);
      free_date(end);
      free_list(l);
      menu = 0;
    }
    if(menu == 7){ ////////////////////////////////// feita
      int tamanho;
      Date begin = createDate(01,01,2010);
      Date end = createDate(31,12,2017);
      printf("Qual o número de utilizadores que pretende?\n");
      scanf("%d",&tamanho);
      LONG_list l = create_list(tamanho);
      printf("Resposta:\n");
      start = clock();
      l = most_answered_questions(tda, tamanho, begin, end);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      free_date(begin);
      free_date(end);
      free_list(l);
      menu = 0;
    }
    if(menu == 8){ /////////////////////////////////// erros
      LONG_list l = create_list(10);
      int tamanho;
      printf("Qual o número de perguntas que pretende?\n");
      scanf("%d",&tamanho);
      printf("Resposta:\n");
      start = clock();
      l = contains_word(tda, "Ho", tamanho);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 9){
      printf("Ainda nao está acabada.\n");
      printf("Resposta:\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 10){
      printf("Ainda nao está acabada.\n");
      printf("Resposta:\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 11){
      printf("Ainda nao está acabada.\n");
      printf("Resposta:\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu==-1) break;
  }


  free(tda);
  
  printf("Program Done...\n");
  return 0;
} 