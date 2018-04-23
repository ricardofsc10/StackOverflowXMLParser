/*
#include <stdio.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "list.h"
#include "query11.h"

// query 11

void getReferenceTags (xmlDocPtr doc, xmlNodePtr cur, TAD_community com){
   xmlChar *id_tag_l, *tag_name_l;
   cur = cur->xmlChildrenNode;

   while (cur != NULL) {
       if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
          id_tag_l = xmlGetProp(cur, (const xmlChar *) "Id");
          tag_name_l = xmlGetProp(cur, (const xmlChar *) "TagName");
         

         xmlFree(id_tag_l);
         xmlFree(tag_name_l);
       }
       cur = cur->next;
   }
}


LONG_list most_used_best_rep(TAD_community com, int N, Date begin, Date end){

  LONG_list l_topusers = create_list(N);
  int conta __unused; // so para nao dar warning
  for(int i=0; i<N; i++) 
    set_list(l_topusers,i,0);
  

// inserir ordenadamente
// percorrer o resto dos users inserindo ordenadamente
  

// percorrer os posts todos verificar se pertence a um "top user"
// verificar se está entre as datas e fazer um levantamento das tags

  int i=0; // so declarei para nao dar erro
  if(difDatas(com->posts[i]->data,begin,end) == 0){ //verifica se esta entre o intervalo de tempo

  } 
  return l_topusers;
}
*/