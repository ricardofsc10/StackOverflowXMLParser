#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <gmodule.h>
#include <glib.h>
#include "tcd.h"
#include "utilizador.h"
#include "posts.h"
#include "common.h"

// query 0 (load)

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

void strToTag (POSTS value_post, char* str){
  char* token;
  const char delim[3] = "&;"; //caracteres em que a string é dividida
  token = strtok (str,delim);
  while (token != NULL){
      set_tags(value_post, token);
      //para testar:
      //printf("%s\n", com->posts[i]->tags);
      token = strtok (NULL, delim);
  }
}

int myelem (int* l, int id, int N){ // ve se um elemento esta num array
    for(int i = 0; i < N ; i++){
      if(id == l[i]) return 1; // caso de ter
    }
    return 0; // caso de nao ter
}

/*
void redimensiona_posts_frequentados(TAD_community com, int id_bin){ // recebe a posição do array onde esta o utilizador a redimensionar
    com->utilizador[id_bin]->posts_frequentados = realloc(com->utilizador[id_bin]->posts_frequentados, sizeof(int) * (com->utilizador[id_bin]->espaco_posts_frequentados + 5));
    for(int i = com->utilizador[id_bin]->espaco_posts_frequentados ; i < com->utilizador[id_bin]->espaco_posts_frequentados + 5 ; i++){
        com->utilizador[id_bin]->posts_frequentados[i] = 0;
    }
    com->utilizador[id_bin]->espaco_posts_frequentados += 5;
}*/

void getReferenceUser (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) { 

    cur = cur->xmlChildrenNode;
    int i = 0;

    while (cur != NULL) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {



           xmlChar *nome_l, *bio_l, *reputacao_l;
           long id_l; // = malloc(sizeof(int));

           id_l = atol( (const char *) xmlGetProp(cur, (const xmlChar *) "Id"));
           printf("ID: %ld\n", id_l);
           nome_l = xmlGetProp(cur, (const xmlChar *) "DisplayName");
           bio_l = xmlGetProp(cur, (const xmlChar *) "AboutMe");
           reputacao_l = xmlGetProp(cur, (const xmlChar *) "Reputation");

           // preenche os parametros do utilizador
           UTILIZADOR value_user = create_utilizador();

           set_key_id(value_user, id_l);
           set_nome(value_user, mystrdup( (char *) nome_l));
           set_bio(value_user, mystrdup((char *) bio_l));
           set_reputacao(value_user, atoi( (const char *) reputacao_l));

           set_utilizador(com, id_l, value_user);
           //g_hash_table_insert (get_utilizador(com), (gpointer) id_l, (gpointer) value_user);

           xmlFree(nome_l);
           xmlFree(bio_l);
           xmlFree(reputacao_l);
           //free_utilizador(value_user);

           i++;
        }
        cur = cur->next;
    }
    printf("[load] %d Users...\n", i);

    
    /*// testa se contem elementos
    long key; // = malloc(sizeof(int));
    key = 10;
    gboolean g = g_hash_table_contains(get_utilizador(com), (gpointer) key);
    if(g == TRUE){
      printf("contem..\n");
      UTILIZADOR u = g_hash_table_lookup(get_utilizador(com), (gpointer) key);
      printf("id: %d\n", get_key_id(u) );
      printf("reputação: %d\n", get_reputacao(u));
    }
    else printf("nao contem..\n");*/
}


void getReferencePosts (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) {

   cur = cur->xmlChildrenNode;
   int i=0;

   while (cur != NULL) {
       if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {

           xmlChar *post_type_id_l, *creation_date_l, *score_l, *body_l, *parent_id_l, *title_l, *tags_l, *answer_count_l, *comment_count_l;
           long owner_user_id_l; 
           long id_l;

           id_l = atol((const char *) xmlGetProp(cur, (const xmlChar *) "Id"));
           post_type_id_l = xmlGetProp(cur, (const xmlChar *) "PostTypeId");
           creation_date_l = xmlGetProp(cur, (const xmlChar *) "CreationDate");
           score_l = xmlGetProp(cur, (const xmlChar *) "Score");
           body_l = xmlGetProp(cur, (const xmlChar *) "Body");
           owner_user_id_l = atol((const char *) xmlGetProp(cur, (const xmlChar *) "OwnerUserId"));
           parent_id_l=xmlGetProp(cur, (const xmlChar *) "ParentId");
           title_l = xmlGetProp(cur, (const xmlChar *) "Title");
           tags_l = xmlGetProp(cur, (const xmlChar *) "Tags");
           answer_count_l = xmlGetProp(cur, (const xmlChar *) "AnswerCount");
           comment_count_l = xmlGetProp(cur, (const xmlChar *) "CommentCount");

           // preenche os parametros dos posts e dos utilizadores
           POSTS value_post = create_posts();

           // value_user fica com valor associado à chave passada
           UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) owner_user_id_l);

           printf("id: %d\n", get_key_id(value_user) );

           set_posts_u(value_user, (get_posts_u(value_user)+1));
           
           set_key_id_post(value_post, id_l);
           set_data(value_post, stringToDias( (char *) creation_date_l));
           set_score(value_post, atoi( (const char *) score_l));
           set_owner_user_id(value_post, owner_user_id_l);
           set_body(value_post, mystrdup( (char *) body_l));
           set_post_type_id(value_post, atoi( (const char *) post_type_id_l));

           if(get_post_type_id(value_post)==2) {
              set_parent_id(value_post, atoi( (const char *) parent_id_l));
              set_title(value_post, NULL);
              // inserir o id da pergunta no utilizador que faz a pergunta
             // if(myelem(value_user->posts_frequentados, value_post->parent_id, value_user->contador_posts_frequentados) == 0){
                // se nao tem o id no array, insere-o
                //value_user->posts_frequentados[value_user->contador_posts_frequentados] = value_post->parent_id;
               // value_user->contador_posts_frequentados++;
              //}
           }
           else{
              set_title(value_post, mystrdup( (char *) title_l));
              set_parent_id(value_post, 0);
              strToTag(value_post, (char *) tags_l);
              // inserir o id da pergunta no utilizador que faz a pergunta
              //if(myelem(value_user->posts_frequentados, atoi((const char *) id_l), value_user->contador_posts_frequentados) == 0){
                // se nao tem o id no array, insere-o
                //value_user->posts_frequentados[value_user->contador_posts_frequentados] = value_post->parent_id;
                //value_user->contador_posts_frequentados++;
              //}
           }
           if(answer_count_l == NULL){ // alguns posts sem answer_count, dava segmentation fault sem esta condição
              set_answer_count(value_post, 0);
           }
           else{
              set_answer_count(value_post, atoi( (const char *) answer_count_l));
           }
           set_comment_count(value_post, atoi( (const char *) comment_count_l));
           set_dif_votes(value_post, 0);

           // insere todos os parametros do post na chave (id) associado
           //g_hash_table_insert (com->posts, (gpointer) id_l, (gpointer) value_post);
           set_posts(com,(gpointer) id_l, (gpointer) value_post);

          
           xmlFree(post_type_id_l);
           xmlFree(creation_date_l);
           xmlFree(score_l);
           xmlFree(body_l);
           xmlFree(parent_id_l);
           xmlFree(title_l);
           xmlFree(tags_l);
           xmlFree(answer_count_l);
           xmlFree(comment_count_l);
           //free_posts(value_post);
           //free_utilizador(value_user);

           i++;
       }
       cur = cur->next;
   }
   printf("[load] %d Posts...\n", i);
}

void getReferenceVotes (xmlDocPtr doc, xmlNodePtr cur, TAD_community com){

    cur = cur->xmlChildrenNode;
    int i = 0;

    while (cur != NULL) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {

           xmlChar *votes_l;
           long postid_l;

           votes_l = xmlGetProp(cur, (const xmlChar *) "VoteTypeId");
           postid_l = atol((const char *) xmlGetProp(cur, (const xmlChar *) "PostId"));
           
           POSTS value_post = create_posts();
           value_post = (POSTS) g_hash_table_lookup(get_posts(com), (gpointer) postid_l);
           if(value_post != NULL){
              // preenche os parametros do utilizador
              if(atoi((const char *) (votes_l)) == 2){
                set_dif_votes(value_post, (get_dif_votes(value_post)+1));
              }
              if(atoi((const char *) (votes_l)) == 3){
                set_dif_votes(value_post, (get_dif_votes(value_post)-1));
              }
            }

          xmlFree(votes_l);
          //free_posts(value_post);

          i++;
        }
        cur = cur->next;
    }
    printf("[load] %d Votes...\n", i);
}


TAD_community load(TAD_community com, char* dump_path){
    
    xmlDocPtr doc_user, doc_posts, doc_votes, doc_tags __unused ;
    xmlNodePtr cur_user, cur_posts, cur_votes, cur_tags __unused;

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

    printf("[load] Ínicio do parse do documento Users.xml...\n");

    getReferenceUser (doc_user,cur_user,com);
    xmlFreeDoc(doc_user);

    printf("[load] Parse do documento Users.xml foi feito com sucesso...\n");

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

    printf("[load] Ínicio do parse do documento Posts.xml...\n");

    getReferencePosts (doc_posts,cur_posts,com);
    xmlFreeDoc(doc_posts);

    printf("[load] Parse do documento Posts.xml foi feito com sucesso...\n");

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

    printf("[load] Ínicio do parse do documento Votes.xml...\n");

    getReferenceVotes (doc_votes,cur_votes,com);
    xmlFreeDoc(doc_votes);

    printf("[load] Parse do documento Votes.xml foi feito com sucesso...\n");

   ////////////////////////////////// Faz-se o parse do Tags
   /*char path_tags[50];
   strcpy(path_tags, dump_path);
   strcat(path_tags,"./Tags.xml");

   doc_tags = xmlParseFile(path_tags);

   if (doc_tags == NULL) {
         fprintf(stderr,"Document not parsed successfully. \n");
         return 0;
   }

   cur_tags = xmlDocGetRootElement(doc_tags);

   if (cur_tags == NULL) {
       fprintf(stderr,"empty document\n");
       xmlFreeDoc(doc_tags);
       return 0;
   }

   if (xmlStrcmp(cur_tags->name, (const xmlChar *) "tags")) {
       fprintf(stderr,"document of the wrong type, root node != tags\n");
       xmlFreeDoc(doc_tags);
       return 0;
   }

   printf("[load] Ínicio do parse do documento Tags.xml...\n");

   getReferenceTags (doc_tags,cur_tags,com);
   xmlFreeDoc(doc_tags);

   printf("[load] Parse do documento Tags.xml foi feito com sucesso...\n");*/

    return com;
}