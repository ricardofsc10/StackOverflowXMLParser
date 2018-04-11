#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <gmodule.h>
#include <glib.h>
#include "interface.h"

// definições da glib
// typedef void* gpointer;
// typedef char gchar;
// gint(); ver no site

struct TCD_community{
  GHashTable* utilizador;
  GHashTable* posts;
};

struct utilizador{
  gchar* nome;
  gchar* bio;
  gint* posts_frequentados; // so contem o id das perguntas em que ele interage
  gint contador_posts_frequentados;
  gint espaco_posts_frequentados;
  gint posts_u;
  gint reputacao;
};

struct posts{
  Date data;
  gint score;
  gint owner_user_id;
  gchar* title;
  gchar* body;
  gint post_type_id; // 1-pergunta 2-resposta
  gint parent_id;
  gchar* tags;
  gint answer_count;
  gint comment_count;
  gchar* favorite_count;
  gint dif_votes;
};

// init

TAD_community init(){
    TAD_community tad = malloc(sizeof(struct TCD_community));
    tad->utilizador = g_hash_table_new (g_int_hash, g_int_equal);
    tad->posts = g_hash_table_new (g_int_hash, g_int_equal);
    return tad;
}


// funções auxiliares mais tarde para serem postas noutro ficheiro

int difDatas(Date x,Date begin, Date end) { // 0 ou -1 se está entre as datas ou n
    int inicio = 0,fim;
    if(get_year(x) < get_year(begin)) inicio=-1;
    else {
        if (get_year(x) == get_year(begin)) {
            if (get_month(x) < get_month(begin)) inicio=-1;
            else {
                if (get_month(x) == get_month(begin)) {
                    if (get_day(x) < get_day(begin)) inicio= -1;
                    else inicio= 0;
                }
                else inicio = 0;
            }
        }
        else inicio = 0;
    }

    if(get_year(x) > get_year(end)) fim=-1;
    else {
        if (get_year(x) == get_year(end)) {
            if (get_month(x) > get_month(end)) fim =-1;
            else {
                if (get_month(x) == get_month(end)) {
                    if (get_day(x) > get_day(end)) fim = -1;
                    else fim = 0;
                }
                else fim = 0;
            }
        }
        else fim = 0;
    }
    
    if (inicio== 0 && fim ==0) return 0;
    else return -1;
}

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

int strToTag (TAD_community com, char* str, size_t id){
  char* token;
  POSTS value_post;
  value_post = (POSTS) g_hash_table_lookup(com->posts, (const void *) id);
  const char delim[3] = "&;"; //caracteres em que a string é dividida
  token = strtok (str,delim);
  while (token != NULL){
      value_post->tags = token;
      //para testar:
      //printf("%s\n", com->posts[i]->tags);
      token = strtok (NULL, delim);
  }
  return 0;
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

void getReferenceUser (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) { // acho que está tudo bem nesta função

    xmlChar *nome_l, *bio_l, *reputacao_l;
    cur = cur->xmlChildrenNode;
    int i = 0;
    size_t id_l;

    while (cur != NULL) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
           id_l = atoi( (const char *) xmlGetProp(cur, (const xmlChar *) "Id"));
           nome_l = xmlGetProp(cur, (const xmlChar *) "DisplayName");
           bio_l = xmlGetProp(cur, (const xmlChar *) "AboutMe");
           reputacao_l = xmlGetProp(cur, (const xmlChar *) "Reputation");

           // preenche os parametros do utilizador
           UTILIZADOR value = malloc(sizeof(struct utilizador));
           value->nome = mystrdup( (char *) nome_l);
           value->bio = mystrdup((char *) bio_l);
           value->reputacao = atoi( (const char *) reputacao_l);

           gint boolean = g_hash_table_insert (com->utilizador, (gpointer)id_l, value);
           if(boolean == FALSE) break;

           xmlFree(nome_l);
           xmlFree(bio_l);
           xmlFree(reputacao_l);

           i++;
        }
        cur = cur->next;
    }
    printf("[load] %d Users...\n", i);
}


void getReferencePosts (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) {

   xmlChar *post_type_id_l, *creation_date_l, *score_l, *body_l, *parent_id_l, *title_l, *tags_l, *answer_count_l, *comment_count_l, *favorite_count_l;
   cur = cur->xmlChildrenNode;
   int i=0, k;
   size_t owner_user_id_l, id_l;

   while (cur != NULL) {
       if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
           id_l = atoi((const char *) xmlGetProp(cur, (const xmlChar *) "Id"));
           post_type_id_l = xmlGetProp(cur, (const xmlChar *) "PostTypeId");
           creation_date_l = xmlGetProp(cur, (const xmlChar *) "CreationDate");
           score_l = xmlGetProp(cur, (const xmlChar *) "Score");
           body_l = xmlGetProp(cur, (const xmlChar *) "Body");
           owner_user_id_l = atoi((const char *) xmlGetProp(cur, (const xmlChar *) "OwnerUserId"));
           parent_id_l=xmlGetProp(cur, (const xmlChar *) "ParentId");
           title_l = xmlGetProp(cur, (const xmlChar *) "Title");
           tags_l = xmlGetProp(cur, (const xmlChar *) "Tags");
           answer_count_l = xmlGetProp(cur, (const xmlChar *) "AnswerCount");
           comment_count_l = xmlGetProp(cur, (const xmlChar *) "CommentCount");
           favorite_count_l = xmlGetProp(cur, (const xmlChar *) "FavoriteCount");

           // preenche os parametros dos posts
           POSTS value = malloc(sizeof(struct posts));
           UTILIZADOR value_user;

           value->data = stringToDias( (char *) creation_date_l);
           value_user = (UTILIZADOR) g_hash_table_lookup(com->utilizador, (gpointer) owner_user_id_l);
           value_user->posts_u++;
           value->score = atoi( (const char *) score_l);
           value->owner_user_id= atoi( (const char *) owner_user_id_l);
           value->body = mystrdup( (char *) body_l);
           value->post_type_id = atoi( (const char *) post_type_id_l);

           if(value->post_type_id==2) {
              value->parent_id = atoi( (const char *) parent_id_l);
              // inserir o id da pergunta no utilizador que faz a pergunta
              if(myelem(value_user->posts_frequentados, value->parent_id, value_user->contador_posts_frequentados) == 0){
                // se nao tem o id no array, insere-o
                value_user->posts_frequentados[value_user->contador_posts_frequentados] = value->parent_id;
                value_user->contador_posts_frequentados++;
              }
           }
           else{
              value->title = mystrdup( (char *) title_l);
              k = strToTag(com, (char *) tags_l, atoi( (const char *) id_l));
              // inserir o id da pergunta no utilizador que faz a pergunta
              if(myelem(value_user->posts_frequentados, atoi((const char *) id_l), value_user->contador_posts_frequentados) == 0){
                // se nao tem o id no array, insere-o
                value_user->posts_frequentados[value_user->contador_posts_frequentados] = value->parent_id;
                value_user->contador_posts_frequentados++;
              }
           }
           if(answer_count_l == NULL){ // alguns posts sem answer_count, dava segmentation fault sem esta condição
              value->answer_count = 0;
           }
           else{
              value->answer_count = atoi( (const char *) answer_count_l);
           }
           value->comment_count = atoi( (const char *) comment_count_l);
           value->favorite_count = mystrdup( (char *)favorite_count_l);

           g_hash_table_insert (com->posts, (gpointer) id_l, value);

          
           xmlFree(post_type_id_l);
           xmlFree(creation_date_l);
           xmlFree(score_l);
           xmlFree(body_l);
           xmlFree(parent_id_l);
           xmlFree(title_l);
           xmlFree(tags_l);
           xmlFree(answer_count_l);
           xmlFree(comment_count_l);
           xmlFree(favorite_count_l);

           i++;
       }
       cur = cur->next;
   }
   printf("[load] %d Posts...\n", i);
}

void getReferenceVotes (xmlDocPtr doc, xmlNodePtr cur, TAD_community com){
    xmlChar *votes_l;
    size_t postid_l;
    cur = cur->xmlChildrenNode;

    while (cur != NULL) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
           votes_l = xmlGetProp(cur, (const xmlChar *) "VoteTypeId");
           postid_l = atoi((const char *) xmlGetProp(cur, (const xmlChar *) "PostId"));
           
           POSTS value_tags;  //procura_binaria_p(com,atoi((const char *)postid_l), com->posts_t);
           value_tags = (POSTS) g_hash_table_lookup(com->posts, (gpointer) postid_l);
           if(value_tags != NULL){
              // preenche os parametros do utilizador
              if(atoi((const char *) (votes_l)) == 2){
                value_tags->dif_votes++;
              }
              if(atoi((const char *) (votes_l)) == 3){
                value_tags->dif_votes--;
              }
            }

          xmlFree(votes_l);
        }
        cur = cur->next;
    }
}


TAD_community load(TAD_community com, char* dump_path){
    
    xmlDocPtr doc_user, doc_posts, doc_votes, doc_tags __unused;
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