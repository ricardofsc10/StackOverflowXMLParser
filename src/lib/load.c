#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "struct.c"
#include "load.h"

Date stringToDias (char* data) { // "2011-11-11"
    
    char ano[4];
    char mes[2];
    char dia[2];
    int i;
    for (i=0;i<4;i++)
        ano[i]=data[i];
    for(i=5; i<7;i++)
        mes[i]=data[i];
    for(i=8; i<10;i++)
        dia[i]=data[i];
    Date ndata = (atoi(dia),atoi(mes),atoi(ano));
}


void getReferenceUser (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) { // acho que está tudo bem nesta função

    xmlChar *nome_l, *id_l, *bio_l, *reputacao_l;
    cur = cur->xmlChildrenNode;
    int i = 0;
    long array[10] = {0}; // está aqui para ser usado apenas no create_user()

    while (cur != NULL) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
       	   id_l = xmlGetProp(cur, "Id");
           nome_l = xmlGetProp(cur, "DisplayName");
           bio_l = xmlGetProp(cur, "AboutMe");
           reputacao_l = xmlGetProp(cur, "Reputation");
           
           // preenche os parametros do utilizador
           com->utilizador[i]->id = atoi(id_l); // usa-se o atoi porque na estrutura o id é um int
           com->utilizador[i]->nome = nome_l;
           com->utilizador[i]->user = create_user(bio_l,array);
           com->utilizador[i]->reputacao = reputacao_l;

           xmlFree(id_l);
           xmlFree(nome_l);
           xmlFree(bio_l);
           xmlFree(reputacao_l);
           
           if ((com->espaco_users - com->n_utilizadores) == 1){ // testa se ainda tem espaço para alocar o proximo
               redimensiona_utilizadores(com);
           }

           i++;
           com->n_utilizadores++;
        }
        cur = cur->next;
    }
    printf("%d Users\n", i);
}


// -- ainda há muito a melhorar
// -- falta inserir datas
// -- falta redimensionar tamanhos do array de posts quando necessário
// -- provavelmente faltam mais cenas ...........
void getReferencePosts (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) {

   xmlChar *id_l, *post_type_id_l, *creation_date_l, *score_l, *body_l, *owner_user_id_l, *parent_id_l, *title_l, *tags_l, *answer_count_l, *comment_count_l, *favorite_count_l;
   cur = cur->xmlChildrenNode;
   int i=0,id_bin;

   while (cur != NULL) {
       if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
       	   id_l = xmlGetProp(cur, "Id");
       	   post_type_id_l = xmlGetProp(cur, "PostTypeId");
       	   creation_date_l = xmlGetProp(cur, "CreationDate");
       	   score_l = xmlGetProp(cur, "Score");
       	   body_l = xmlGetProp(cur, "Body");
           owner_user_id_l = xmlGetProp(cur, "OwnerUserId");
           parent_id_l=xmlGetProp(cur,"ParentId");
           title_l = xmlGetProp(cur, "Title");
           tags_l = xmlGetProp(cur, "Tags");
           answer_count_l = xmlGetProp(cur, "AnswerCount");
           comment_count_l = xmlGetProp(cur, "CommentCount");
           favorite_count_l = xmlGetProp(cur, "FavoriteCount");

           // preenche os parametros dos posts
           if(owner_user_id_l == NULL);
           else{
               id_bin = procura_binaria_u(com, atoi(owner_user_id_l),com->n_utilizadores);
               com->posts[i]->data=stringToDias(creation_date_l);
               com->utilizador[id_bin]->posts_u++;
               com->posts[i]->id_post = atoi(id_l);
               com->posts[i]->score = score_l;
               com->posts[i]->owner_user_id= owner_user_id_l;
               com->posts[i]->title = title_l;
               com->posts[i]->body = body_l;
               com->posts[i]->post_type_id = post_type_id_l;
               if(com->posts[i]->post_type_id==2) {
                  com->posts[i]->parent_id = atoi(parent_id_l);
               }
               com->posts[i]->tags[0] = tags_l;
               com->posts[i]->answer_count = answer_count_l;
               com->posts[i]->comment_count = comment_count_l;
               com->posts[i]->favorite_count = favorite_count_l;
              }
               xmlFree(id_l);
               xmlFree(post_type_id_l);
               xmlFree(creation_date_l);
               xmlFree(score_l);
               xmlFree(body_l);
               xmlFree(owner_user_id_l);
               xmlFree(parent_id_l);
               xmlFree(title_l);
               xmlFree(tags_l);
               xmlFree(answer_count_l);
               xmlFree(comment_count_l);
               xmlFree(favorite_count_l);

               if ((com->espaco_posts - com->posts_t)== 1) {
                redimensiona_posts(com);

               }
               com->posts_t++;
               i++;
           }
       cur = cur->next;
   }
   printf("%d Posts\n", i);
}


TAD_community load(TAD_community com, char* dump_path){
    
    xmlDocPtr doc_user, doc_posts;
	  xmlNodePtr cur_user, cur_posts;

    ////////////////////////////////// Faz-se o parse do Users
    char path_users[50];
    strcpy(path_users, dump_path);
    strcat(path_users,"./Users.xml");

  	doc_user = xmlParseFile(path_users);

  	if (doc_user == NULL) {
          fprintf(stderr,"Document not parsed successfully. \n");
          return 0;
    }

    cur_user = xmlDocGetRootElement(doc_user);

    if (cur_user == NULL) {
        fprintf(stderr,"empty document\n");
        xmlFreeDoc(doc_user);
        return 0;
    }

    if (xmlStrcmp(cur_user->name, (const xmlChar *) "users")) {
        fprintf(stderr,"document of the wrong type, root node != users\n");
        xmlFreeDoc(doc_user);
        return 0;
    }

    printf("[load.c] Ínicio do parse do documento Users.xml........\n");

    getReferenceUser (doc_user,cur_user,com);
    xmlFreeDoc(doc_user);

    printf("[load.c] Parse do documento Users.xml foi feito com sucesso ...\n");


    ////////////////////////////////// Faz-se o parse do Posts
    char path_posts[50];
    strcpy(path_posts, dump_path);
    strcat(path_posts,"./Posts.xml");

  	doc_posts = xmlParseFile(path_posts);

  	if (doc_posts == NULL) {
          fprintf(stderr,"Document not parsed successfully. \n");
          return 0;
    }

    cur_posts = xmlDocGetRootElement(doc_posts);

    if (cur_posts == NULL) {
        fprintf(stderr,"empty document\n");
        xmlFreeDoc(doc_posts);
        return 0;
    }

    if (xmlStrcmp(cur_posts->name, (const xmlChar *) "posts")) {
        fprintf(stderr,"document of the wrong type, root node != posts\n");
        xmlFreeDoc(doc_posts);
        return 0;
    }

    printf("[load.c] Ínicio do parse do documento Posts.xml........\n");

    getReferencePosts (doc_posts,cur_posts,com);
    xmlFreeDoc(doc_posts);

    printf("[load.c] Parse do documento Posts.xml foi feito com sucesso ...\n");

    return com;
}
