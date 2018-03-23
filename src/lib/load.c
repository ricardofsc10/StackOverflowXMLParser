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
           com->utilizador[i]->id = atoi(id_l); // usa-se o atoi porque na estrutura o id é um int
           com->utilizador[i]->nome = nome_l;
           com->utilizador[i]->user = create_user(bio_l,array);
           com->utilizador[i]->reputacao = reputacao_l;

           xmlFree(id_l);
           xmlFree(nome_l);
           xmlFree(bio_l);
           xmlFree(reputacao_l);
           
           if ((com->espaco_estrutura - com->n_utilizadores) == 1){ // testa se ainda tem espaço para alocar o proximo
               redimensiona_utilizadores(com);
           }

           i++;
           com->n_utilizadores++;
        }
        cur = cur->next;
    }
    printf("%d Users\n", i);
}


int procuraBinaria (TAD_community com, int id, int Tam){
    int inf = 0;
    int sup = Tam-1;
    int meio;
    while (inf <= sup){
        meio = (inf + sup)/2;

        if (id == com->utilizador[meio]->id) return meio;

        if (id < com->utilizador[meio]->id) sup = meio - 1;
        
        else inf = meio + 1;
    }
    return -1;   // não encontrado
}


/*
-- ainda há muito a melhorar
-- falta inserir datas
-- falta redimensionar tamanhos do array de posts quando necessário
-- provavelmente faltam mais cenas ...........
*/

void getReferencePosts (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) {

   xmlChar *id_l, *post_type_id_l, *creation_date_l, *score_l, *body_l, *owner_user_id_l, *title_l, *tags_l, *answer_count_l;
   cur = cur->xmlChildrenNode;
   int i=0, indice_utilizador;

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
           answer_count_l = xmlGetProp(cur, "AnswerCount");

           if(owner_user_id_l == NULL); // há um post que nao tem userid daí ter esta condição
           else{  // preenche os parametros dos posts

               indice_utilizador = procuraBinaria(com, atoi(owner_user_id_l), com->n_utilizadores); // ao fazer isto descobre-se qual o indice do array

               int num_posts = com->utilizador[indice_utilizador]->n_posts; // coloca-se numa variavel para ser mais facil em baixo

               com->utilizador[indice_utilizador]->n_posts += 1; // ao adicionar este post, o numero de posts aumenta
               com->utilizador[indice_utilizador]->posts[num_posts]->id_post = id_l;
               com->utilizador[indice_utilizador]->posts[num_posts]->score = score_l;
               com->utilizador[indice_utilizador]->posts[num_posts]->title = title_l;
               com->utilizador[indice_utilizador]->posts[num_posts]->body = body_l;
               com->utilizador[indice_utilizador]->posts[num_posts]->tipo = post_type_id_l;
               com->utilizador[indice_utilizador]->posts[num_posts]->tags[0] = tags_l;
               com->utilizador[indice_utilizador]->posts[num_posts]->answer_count = answer_count_l;

               xmlFree(id_l);
               xmlFree(post_type_id_l);
               xmlFree(creation_date_l);
               xmlFree(score_l);
               xmlFree(body_l);
               xmlFree(owner_user_id_l);
               xmlFree(title_l);
               xmlFree(tags_l);
               xmlFree(answer_count_l);
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

    printf("Loading: Parse do documento Users.xml........\n");

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

    printf("Loading: Parse do documento Posts.xml........\n");

    getReferencePosts (doc_posts,cur_posts,com);
    xmlFreeDoc(doc_posts);

    printf("O parse do documento Posts.xml foi feito com sucesso........\n");

    return com;
}
