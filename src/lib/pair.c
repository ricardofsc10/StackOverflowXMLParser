#include <stdlib.h>
#include <string.h>
#include "pair.h"

struct str_pair {
  char* fst;
  char* snd;
};

STR_pair create_pair(char* fst, char* snd) {
  STR_pair p = malloc(sizeof(struct str_pair));
  p->fst = strdup(fst);
  p->snd = strdup(snd);
  return p;
}

void set_fst(STR_pair pair, char* str) {
  free(pair->fst);
  pair->fst = strdup(str);
}

void set_snd(STR_pair pair, char* str) {
  free(pair->snd);
  pair->snd = strdup(str);
}

char* get_fst(STR_pair pair) {
  return pair? strdup(pair->fst) : NULL;
}

char* get_snd(STR_pair pair) {
  return pair? strdup(pair->snd) : NULL;
}

void free_pair(STR_pair pair) {
  if(pair) {
    free(pair->fst);
    free(pair->snd);
    free(pair);
  }
}




