#include <interface.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  TAD_community tda = NULL;
  STR_pair par = create_str_pair(NULL,NULL);
  
  tda = init();
  printf("A estrutura já foi inicializada...\n");

  char* path1 = "../../dumpexemplo/askubuntu.com/";
  char* path2 = "../../dumpexemplo/android/";
  tda = load(tda, path2);

  par = info_from_post(tda,4567);

  free(tda);
  
  printf("Done.. grande load.\n");
  return 0;
} 