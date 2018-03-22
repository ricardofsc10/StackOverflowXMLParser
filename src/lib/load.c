#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "struct.c"

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
           com->utilizador[i]->id = id_l;
           com->utilizador[i]->nome = nome_l;
           com->utilizador[i]->user = create_user(bio_l,array);
           com->utilizador[i]->reputacao = reputacao_l;

           xmlFree(id_l);
           xmlFree(nome_l);
           xmlFree(bio_l);
           xmlFree(reputacao_l);
           i++;
           com->n_utilizadores++;
        }
        cur = cur->next;
    }
    printf("%d Users\n", i);
}

/*
-- ainda há muito a melhorar
-- o owner_user_id_l não é a posiçao onde está o utilizador, so o estou a usar para testar
    -- podemos fazer um genero de probing para encontrar mais há frente caso nao esteja na posiçao(sugestão)
    -- podemos fazer procura binaria (para este caso nao acho q seja o ideal)
-- falta inserir datas
-- falta redimensionar tamanhos do array de posts quando necessário
-- provavelmente faltam mais cenas ...........
*/

void getReferencePosts (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) {

   xmlChar *id_l, *post_type_id_l, *creation_date_l, *score_l, *body_l, *owner_user_id_l, *title_l, *tags_l;
   cur = cur->xmlChildrenNode;
   int i=0;

   while (cur != NULL) {
       if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
       	   id_l = xmlGetProp(cur, "Id");
       	   post_type_id_l = xmlGetProp(cur, "PostTypeId");
       	   creation_date_l = xmlGetProp(cur, "CreationDate");
       	   score_l = xmlGetProp(cur, "Score");
       	   body_l = xmlGetProp(cur, "Body");
           owner_user_id_l = xmlGetProp(cur, "OwnerUserId");
           title_l = xmlGetProp(cur, "Title");
           tags_l = xmlGetProp(cur, "Tags");

           if(owner_user_id_l == NULL); // há um post que nao tem userid daí ter esta condição
           else{  // preenche os parametros dos posts
               int num_posts = com->utilizador[atoi(owner_user_id_l)]->n_posts;

               com->utilizador[atoi(owner_user_id_l)]->n_posts += 1;
               com->utilizador[atoi(owner_user_id_l)]->posts[num_posts]->id_post = id_l;
               com->utilizador[atoi(owner_user_id_l)]->posts[num_posts]->score = score_l;
               com->utilizador[atoi(owner_user_id_l)]->posts[num_posts]->title = title_l;
               com->utilizador[atoi(owner_user_id_l)]->posts[num_posts]->body = body_l;
               com->utilizador[atoi(owner_user_id_l)]->posts[num_posts]->tipo = post_type_id_l;
               com->utilizador[atoi(owner_user_id_l)]->posts[num_posts]->tags[0] = tags_l;

               xmlFree(id_l);
               xmlFree(post_type_id_l);
               xmlFree(creation_date_l);
               xmlFree(score_l);
               xmlFree(body_l);
               xmlFree(owner_user_id_l);
               xmlFree(title_l);
               xmlFree(tags_l);
               i++;
           }
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

    getReferenceUser (doc_user,cur_user,com);
    xmlFreeDoc(doc_user);

    printf("O parse do documento Users.xml foi feito com sucesso........\n");


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

    getReferencePosts (doc_posts,cur_posts,com);
    xmlFreeDoc(doc_posts);

    printf("O parse do documento Posts.xml foi feito com sucesso........\n");

    return com;
}
