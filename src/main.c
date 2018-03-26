#include <interface.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  TAD_community tda = NULL;
  STR_pair par = create_str_pair(NULL,NULL);
  LONG_list l = create_list(5);
  
  tda = init();
  printf("A estrutura já foi inicializada...\n");

  char* path1 = "../../dumpexemplo/askubuntu.com/";
  char* path2 = "../../dumpexemplo/android/";
  tda = load(tda, path2);

  //par = info_from_post(tda,4567);
  l = top_most_active(tda,5);

  free(tda);
  
  printf("Done.. grande load.\n");
  return 0;
} 