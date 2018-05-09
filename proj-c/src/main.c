#include <interface.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "funcoes.h"

int main(){
  TAD_community tda = NULL;
  
  // inicialização
  tda = init();
  printf("[init] Estrutura inicializada...\n");

  char* path = escolhe_ficheiros();

  // load
  printf("[load] Ínicio do load...\n");
  clock_t start = clock();
  tda = load(tda, path);
  clock_t stop = clock();
  printf("[load] Tempo de execução: %.6f segundos.\n", (stop - start)*pow(10,(-6)) ); // faz-se esta conta pq tempo vem em mili

  // processo interativo das questões
  interatividade(tda);

  // limpeza da estrutura 
  tda = clean(tda);

  printf("[clean] Estrutura limpa...\n");
  
  printf("[main] Program Done...\n");

  return 0;
} 