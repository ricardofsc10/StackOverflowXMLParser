#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "struct.c"
#include "load.h"
#include "init.h"
#include "funções.h"

Date stringToDias (char* data) { // "2011-11-11"
    
    char ano[5];
    char mes[3];
    char dia[3];
    int i,j;
    for (i=0,j=0;i<4;i++,j++)
        ano[j]=data[i];
        ano[j]='\0';
    for(i=5,j=0; i<7;i++,j++)
        mes[j]=data[i];
        mes[j]='\0';
    for(i=8,j=0; i<10;i++,j++)
        dia[j]=data[i];
        dia[j]='\0';
    Date ndata = createDate (atoi(dia),atoi(mes),atoi(ano));
    return ndata;
}



void getReferenceUser (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) { // acho que está tudo bem nesta função

    xmlChar *nome_l, *id_l, *bio_l, *reputacao_l;
    cur = cur->xmlChildrenNode;
    int i = 0;
    long array[10] = {0}; // está aqui para ser usado apenas no create_user()

    while (cur != NULL) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
       	   id_l = xmlGetProp(cur, (const xmlChar *) "Id");
           nome_l = xmlGetProp(cur, (const xmlChar *) "DisplayName");
           bio_l = xmlGetProp(cur, (const xmlChar *) "AboutMe");
           reputacao_l = xmlGetProp(cur, (const xmlChar *) "Reputation");
           
           // preenche os parametros do utilizador
           com->utilizador[i]->id = atoi( (const char *) id_l); // usa-se o atoi porque na estrutura o id é um int
           com->utilizador[i]->nome = nome_l;
           com->utilizador[i]->user = create_user( (char *) bio_l,array);
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
    printf("[load.c] %d Users...\n", i);
}


void getReferencePosts (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) {

   xmlChar *id_l, *post_type_id_l, *creation_date_l, *score_l, *body_l, *owner_user_id_l, *parent_id_l, *title_l, *tags_l, *answer_count_l, *comment_count_l, *favorite_count_l;
   cur = cur->xmlChildrenNode;
   int i=0,id_bin;

   while (cur != NULL) {
       if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
       	   id_l = xmlGetProp(cur, (const xmlChar *) "Id");
       	   post_type_id_l = xmlGetProp(cur, (const xmlChar *) "PostTypeId");
       	   creation_date_l = xmlGetProp(cur, (const xmlChar *) "CreationDate");
       	   score_l = xmlGetProp(cur, (const xmlChar *) "Score");
       	   body_l = xmlGetProp(cur, (const xmlChar *) "Body");
           owner_user_id_l = xmlGetProp(cur, (const xmlChar *) "OwnerUserId");
           parent_id_l=xmlGetProp(cur, (const xmlChar *) "ParentId");
           title_l = xmlGetProp(cur, (const xmlChar *) "Title");
           tags_l = xmlGetProp(cur, (const xmlChar *) "Tags");
           answer_count_l = xmlGetProp(cur, (const xmlChar *) "AnswerCount");
           comment_count_l = xmlGetProp(cur, (const xmlChar *) "CommentCount");
           favorite_count_l = xmlGetProp(cur, (const xmlChar *) "FavoriteCount");

           // preenche os parametros dos posts
           if(owner_user_id_l == NULL);
           else{
               id_bin = procura_binaria_u(com, atoi( (const char *) owner_user_id_l),com->n_utilizadores);
               com->posts[i]->data=stringToDias( (char *) creation_date_l);
               com->utilizador[id_bin]->posts_u++;
               com->posts[i]->id_post = atoi( (const char *) id_l);
               com->posts[i]->score = score_l;
               com->posts[i]->owner_user_id= atoi( (const char *) owner_user_id_l);
               com->posts[i]->body = body_l;
               com->posts[i]->post_type_id = atoi( (const char *) post_type_id_l);
               if(com->posts[i]->post_type_id==2) {
                  com->posts[i]->parent_id = atoi( (const char *) parent_id_l);
               }
               else{
                  com->posts[i]->title = title_l;
               }
               com->posts[i]->tags[0] = tags_l;
               if(answer_count_l == NULL){ // alguns posts sem answer_count, dava segmentation fault sem esta condição
                  com->posts[i]->answer_count = 0;
               }
               else{
                  com->posts[i]->answer_count = atoi( (const char *) answer_count_l);
               }
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
   printf("[load.c] %d Posts...\n", i);
}

void getReferenceVotes (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) { // acho que está tudo bem nesta função

    xmlChar *votes_l, *postid_l;
    cur = cur->xmlChildrenNode;

    while (cur != NULL) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
           votes_l = xmlGetProp(cur, (const xmlChar *) "VoteTypeId");
           postid_l = xmlGetProp(cur, (const xmlChar *) "PostId");
           
           int id_bin = procura_binaria_p(com,atoi((const char *)postid_l), com->posts_t);
           if(id_bin != -1){
              // preenche os parametros do utilizador
              if(atoi((const char *) (votes_l)) == 2){
                com->posts[id_bin]->dif_votes++;
              }
              if(atoi((const char *) (votes_l)) == 3){
                com->posts[id_bin]->dif_votes--;
              }
            }

          xmlFree(votes_l);
          xmlFree(postid_l);
        }
        cur = cur->next;
    }
}


TAD_community load(TAD_community com, char* dump_path){
    
    xmlDocPtr doc_user, doc_posts, doc_votes;
	  xmlNodePtr cur_user, cur_posts, cur_votes;

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

    printf("[load.c] Ínicio do parse do documento Users.xml...\n");

    getReferenceUser (doc_user,cur_user,com);
    xmlFreeDoc(doc_user);

    printf("[load.c] Parse do documento Users.xml foi feito com sucesso...\n");


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

    printf("[load.c] Ínicio do parse do documento Posts.xml...\n");

    getReferencePosts (doc_posts,cur_posts,com);
    xmlFreeDoc(doc_posts);

    printf("[load.c] Parse do documento Posts.xml foi feito com sucesso...\n");

    ////////////////////////////////// Faz-se o parse do Votes
    char path_votes[50];
    strcpy(path_votes, dump_path);
    strcat(path_votes,"./Votes.xml");

    doc_votes = xmlParseFile(path_votes);

    if (doc_votes == NULL) {
          fprintf(stderr,"Document not parsed successfully. \n");
          return 0;
    }

    cur_votes = xmlDocGetRootElement(doc_votes);

    if (cur_votes == NULL) {
        fprintf(stderr,"empty document\n");
        xmlFreeDoc(doc_votes);
        return 0;
    }

    if (xmlStrcmp(cur_votes->name, (const xmlChar *) "votes")) {
        fprintf(stderr,"document of the wrong type, root node != votes\n");
        xmlFreeDoc(doc_votes);
        return 0;
    }

    printf("[load.c] Ínicio do parse do documento Votes.xml...\n");

    getReferenceVotes (doc_votes,cur_votes,com);
    xmlFreeDoc(doc_votes);

    printf("[load.c] Parse do documento Votes.xml foi feito com sucesso...\n");

    return com;
}
