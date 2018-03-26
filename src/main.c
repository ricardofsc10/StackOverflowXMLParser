#include <interface.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  TAD_community tda = NULL;
  STR_pair par = create_str_pair(NULL,NULL);
  LONG_list l = create_list(10);
  int menu = 0;
  
  tda = init();
  printf("[init.c] Estrutura já foi inicializada...\n");

  char* path1 = "../../dumpexemplo/askubuntu.com/";
  char* path2 = "../../dumpexemplo/android/";
  printf("[load.c] Ínicio do load ...\n");
  tda = load(tda, path2);
  printf("[load.c] load done ...\n");

  while(menu == 0){
    printf("Que questão deseja resolver? (-1, para sair do programa)\n");
    scanf("%d", &menu);

    if(menu == 1){
      printf("Ainda nao está acabada.\n");
      //par = info_from_post(tda,4567);
      menu = 0;
    }
    if(menu == 2){
      int tamanho;
      printf("Qual o número de utilizadores que pretende?\n");
      scanf("%d",&tamanho);
      printf("Resposta:\n");
      LONG_list l = create_list(tamanho);
      l = top_most_active(tda,tamanho);
      menu = 0;
    }
    if(menu == 3){
      Date begin = createDate(03,10,2014);
      Date end = createDate(05,03,2016);
      total_posts(tda,begin,end);
      menu = 0;
    }
    if(menu == 4){
      printf("Ainda nao está acabada.\n");
      //par = info_from_post(tda,4567);
      menu = 0;
    }
    if(menu == 5){
      printf("Ainda nao está acabada.\n");
      //par = info_from_post(tda,4567);
      menu = 0;
    }
    if(menu == 6){
      printf("Ainda nao está acabada.\n");
      //par = info_from_post(tda,4567);
      menu = 0;
    }
    if(menu == 7){
      printf("Ainda nao está acabada.\n");
      //par = info_from_post(tda,4567);
      menu = 0;
    }
    if(menu == 8){
      printf("Ainda nao está acabada.\n");
      //par = info_from_post(tda,4567);
      menu = 0;
    }
    if(menu == 9){
      printf("Ainda nao está acabada.\n");
      //par = info_from_post(tda,4567);
      menu = 0;
    }
    if(menu == 10){
      printf("Ainda nao está acabada.\n");
      //par = info_from_post(tda,4567);
      menu = 0;
    }
    if(menu == 11){
      printf("Ainda nao está acabada.\n");
      //par = info_from_post(tda,4567);
      menu = 0;
    }
    if(menu==-1) break;
  }

  free(tda);
  
  printf("Program Done...\n");
  return 0;
} 