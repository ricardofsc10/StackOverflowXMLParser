#include <interface.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  TAD_community tda = NULL;
  
  tda = init();
  printf("A estrutura já foi inicializada...\n");

  char* path1 = "../../dumpexemplo/askubuntu.com/";
  char* path2 = "../../dumpexemplo/android/";
  tda = load(tda, path2);

  free(tda);
  
  printf("Done.. grande load.\n");
  return 0;
} 