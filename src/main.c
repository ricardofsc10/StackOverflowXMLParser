#include <interface.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  TAD_community tda = NULL;
  STR_pair par = create_str_pair(NULL,NULL);
  LONG_list l = create_list(10);
  int menu = 0;
  
  tda = init();
  printf("[init.c] Estrutura já foi inicializada...\n");

  char* path1 = "../../dumpexemplo/askubuntu.com/";
  char* path2 = "../../dumpexemplo/android/";
  printf("[load.c] Ínicio do load...\n");

  clock_t start = clock();
  tda = load(tda, path2);
  clock_t stop = clock();
  
  printf("[load.c] Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) ); // faz-se esta conta pq tempo vem em mili

  while(menu == 0){ // interatividade
    printf("Que questão deseja resolver? (-1, para sair do programa)\n");
    scanf("%d", &menu);

    if(menu == 1){
      printf("Ainda nao está acabada.\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 2){
      int tamanho;
      printf("Qual o número de utilizadores que pretende?\n");
      scanf("%d",&tamanho);
      printf("Resposta:\n");
      LONG_list l = create_list(tamanho);
      start = clock();
      l = top_most_active(tda,tamanho);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 3){
      Date begin = createDate(03,10,2014);
      Date end = createDate(05,03,2016);
      start = clock();
      total_posts(tda,begin,end);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 4){
      printf("Ainda nao está acabada.\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 5){
      printf("Ainda nao está acabada.\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 6){
      printf("Ainda nao está acabada.\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 7){
      printf("Ainda nao está acabada.\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 8){
      printf("Ainda nao está acabada.\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 9){
      printf("Ainda nao está acabada.\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 10){
      printf("Ainda nao está acabada.\n");
      start = clock();
      //par = info_from_post(tda,4567);
      stop = clock();
      printf("Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) );
      menu = 0;
    }
    if(menu == 11){
      printf("Ainda nao está acabada.\n");
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