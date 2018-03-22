#include <interface.h>
#include <stdio.h>

int main(){
  TAD_community tda = NULL;
  
  tda = init();
  printf("A estrutura já foi inicializada...\n");

  char* path = "../../dumpexemplo/askubuntu.com/";
  tda = load(tda, path);
  
  printf("Done.. grande load.\n");
  return 0;
} 