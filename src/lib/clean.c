#include "tcd.h"

// clean

TAD_community clean(TAD_community com){
  free_tad(com);
 
  return com;
}