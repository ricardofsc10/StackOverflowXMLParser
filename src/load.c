#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <gmodule.h>
#include <glib.h>
#include <unistd.h>
#include "tcd.h"
#include "utilizador.h"
#include "posts.h"
#include "tag.h"
#include "common.h"
#include "funcoes.h"

// query 0 (load)

void getReferenceUser (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) { 

    cur = cur->xmlChildrenNode;
    int i = 0;

    while (cur != NULL) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
           xmlChar *nome_l, *bio_l, *reputacao_l;
           long id_l; 

           // faz o parse dos parametros necessários
           id_l = atol( (const char *) xmlGetProp(cur, (const xmlChar *) "Id"));
           nome_l = xmlGetProp(cur, (const xmlChar *) "DisplayName");
           bio_l = xmlGetProp(cur, (const xmlChar *) "AboutMe");
           reputacao_l = xmlGetProp(cur, (const xmlChar *) "Reputation");

           // preenche os parametros do utilizador
           UTILIZADOR value_user = create_utilizador();
           set_key_id(value_user, id_l);
           set_nome(value_user, (char *) nome_l);
           set_bio(value_user,(char *) bio_l);
           set_reputacao(value_user, atoi( (const char *) reputacao_l));

           // insere na tabela de hash referente aos utilizadores
           set_utilizador(com, id_l, value_user);

           // faz free das variáveis usadas
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

   cur = cur->xmlChildrenNode;
   int i=0;

   while (cur != NULL) {
       if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
          xmlChar *post_type_id_l, *creation_date_l, *score_l, *body_l, *parent_id_l, *title_l, *tags_l, *answer_count_l, *comment_count_l;
          long owner_user_id_l, id_l;

          // faz o parse dos parametros necessários
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

          if(atoi( (const char *) post_type_id_l) == 1 || atoi( (const char *) post_type_id_l) == 2){
             // value_user fica com valor associado à chave passada
             UTILIZADOR value_user = (UTILIZADOR) g_hash_table_lookup(get_utilizador(com), (gpointer) owner_user_id_l);
             set_posts_u(value_user, (get_posts_u(value_user)+1));
             
             // preenche os parametros dos posts e dos utilizadores
             POSTS value_post = create_posts();
             set_key_id_post(value_post, id_l);
             set_data(value_post, stringToDias( (char *) creation_date_l));
             set_data_string(value_post, (char *) creation_date_l);
             set_score(value_post, atoi( (const char *) score_l));
             set_owner_user_id(value_post, owner_user_id_l);
             set_body(value_post,(char *) body_l);
             set_post_type_id(value_post, atoi( (const char *) post_type_id_l));
             set_comment_count(value_post, atoi( (const char *) comment_count_l));

             if(get_post_type_id(value_post)==2) {
                set_parent_id(value_post, atoi( (const char *) parent_id_l));
                set_title(value_post, NULL);
                // inserir o id da pergunta no utilizador que faz a pergunta
                set_posts_frequentados(value_user, get_parent_id(value_post));
             }
             if(get_post_type_id(value_post)==1){
                set_title(value_post,(char *) title_l);
                set_parent_id(value_post, 0);
                strToTag(value_post, (char *) tags_l);
                set_posts_frequentados(value_user, get_key_id_post(value_post));
                set_posts_perguntas(value_user, value_post);
             }
             if(answer_count_l == NULL){ // alguns posts sem answer_count, dava segmentation fault sem esta condição
                set_answer_count(value_post, 0);
             }
             if(answer_count_l != NULL){
                set_answer_count(value_post, atoi( (const char *) answer_count_l));
             }

             // insere todos os parametros do post na chave (id) associado
             set_posts(com, id_l,  value_post);

             // insere na estrutura supostamente ordenada por datas
             adiciona_date_posts(com, value_post);

             i++;
          }
          
          xmlFree(post_type_id_l);
          xmlFree(creation_date_l);
          xmlFree(score_l);
          xmlFree(body_l);
          xmlFree(parent_id_l);
          xmlFree(title_l);
          xmlFree(tags_l);
          xmlFree(answer_count_l);
          xmlFree(comment_count_l);

       }
       cur = cur->next;
   }
   ordena(com);

   printf("[load] %d Posts...\n", i);
}

void getReferenceTags (xmlDocPtr doc, xmlNodePtr cur, TAD_community com){

   cur = cur->xmlChildrenNode;
   int i = 0;

   while (cur != NULL) {
       if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {

          xmlChar* id_tag_l;
          char* tag_name_l;

          id_tag_l = xmlGetProp(cur, (const xmlChar *) "Id");
          tag_name_l = (char*) xmlGetProp(cur, (const xmlChar *) "TagName");
         
          TAG value_tag = create_tag();
          set_key_tag_name(value_tag, tag_name_l);
          set_id_tag(value_tag, atoi( (const char *) id_tag_l));

          set_tag(com,tag_name_l,value_tag);

          //teste
          /*
          TAG exemplo_tag = (TAG) g_hash_table_lookup(get_tag(com), "464xlat");
            if(get_key_tag_name(exemplo_tag) != NULL){
            printf("%ld\n", get_id_tag(exemplo_tag));
            printf("%s\n", get_key_tag_name(exemplo_tag));
          }
          */


          xmlFree(tag_name_l);

          i++;
        }
       cur = cur->next;
   }
   printf("[load] (processo filho) %d Tags...\n", i);
}


TAD_community load(TAD_community com, char* dump_path){
    
    xmlDocPtr doc_user, doc_posts, doc_tags;
    xmlNodePtr cur_user, cur_posts, cur_tags;

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

    ////////////////////////////////// Faz-se o parse do Tags
    int pid;
    if((pid = fork()) == 0){
       char path_tags[50];
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

       printf("[load] (processo filho) Ínicio do parse do documento Tags.xml...\n");

       getReferenceTags (doc_tags,cur_tags,com);
       xmlFreeDoc(doc_tags);

       printf("[load] (processo filho) Parse do documento Tags.xml foi feito com sucesso...\n");
       _exit(0);
    }
    if(pid == -1)
      perror("ERROR: tags falhou...");


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

    return com;
}