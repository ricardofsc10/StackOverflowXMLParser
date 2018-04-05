#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "interface.h"

struct TCD_community{
	UTILIZADOR* utilizador;
	int n_utilizadores;
	int espaco_users;
	POSTS* posts;
	int posts_t;
	int espaco_posts;
};

struct utilizador{
 	xmlChar* nome;
 	int id;
 	USER user; // bio e array para 10 posts
	int posts_u;
	int reputacao;

};

struct posts{
	Date data;
	int id_post;
	int score;
	int owner_user_id;
	xmlChar* title;
	xmlChar* body;
	int post_type_id; // 1-pergunta 2-resposta
	int parent_id;
	xmlChar* tags;
	int answer_count;
	int comment_count;
	xmlChar* favorite_count;
	int dif_votes;
};

// funções auxiliares mais tarde para serem postas noutro ficheiro

int procura_binaria_u (TAD_community com, int id, int Tam){
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

int procura_binaria_p (TAD_community com, int id, int Tam){
    int inf = 0;
    int sup = Tam-1;
    int meio;
    while (inf <= sup){
        meio = (inf + sup)/2;

        if (id == com->posts[meio]->id_post) return meio;

        if (id < com->posts[meio]->id_post) sup = meio - 1;
        
        else inf = meio + 1;
    }
    return -1;   // não encontrado
}

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

// init

TAD_community init(){

	TAD_community tad = malloc(sizeof(struct TCD_community));
	tad->utilizador = malloc(sizeof(struct utilizador)*50000);
	tad->n_utilizadores = 0;
	tad->espaco_users = 50000;
	tad->posts = malloc(sizeof (struct posts)*75000);
	tad->posts_t = 0;
	tad->espaco_posts=75000;
	
	for(int i = 0 ; i!=50000 ; i++){
		tad->utilizador[i] = malloc(sizeof(struct utilizador));
		tad->utilizador[i]->nome = NULL; ////////
		tad->utilizador[i]->id = 0;
		long array[10] = {0};
		tad->utilizador[i]->user = create_user(NULL,array);
		tad->utilizador[i]->reputacao = 0;
		tad->utilizador[i]->posts_u = 0;		
	}
	for (int j = 0; j != 75000; j++) {
		tad->posts[j] = malloc(sizeof(struct posts));
		tad->posts[j]->data= createDate(0,0,0);
		tad->posts[j]->id_post = 0;
		tad->posts[j]->score = 0;
		tad->posts[j]->owner_user_id= 0;
		tad->posts[j]->title = NULL;
		tad->posts[j]->body = NULL;
		tad->posts[j]->post_type_id = 0;
		tad->posts[j]->parent_id=0;
		tad->posts[j]->tags = NULL;
		tad->posts[j]->answer_count = 0;
		tad->posts[j]->comment_count = 0;
		tad->posts[j]->favorite_count = NULL;
		tad->posts[j]->dif_votes = 0;
	}
	return tad;
}

void redimensiona_utilizadores(TAD_community com){

	//redimensiona e coloca em 'com' tudo o que ja estava, com mais espaço
	com->utilizador = realloc(com->utilizador, sizeof(struct utilizador) * (com->espaco_users + 50000));

	// faz igual à init
	for(int i = com->espaco_users ; i < (com->espaco_users + 50000) ; i++){
		com->utilizador[i] = malloc(sizeof(struct utilizador));
		com->utilizador[i]->nome = NULL; ////////
		com->utilizador[i]->id = 0;
		long array[10] = {0};
		com->utilizador[i]->user = create_user(NULL,array);
		com->utilizador[i]->reputacao = 0;
		com->utilizador[i]->posts_u= 0;		
	}
	com->espaco_users += 50000; // so faz este passo no fim por causa do primeiro for
}

void redimensiona_posts(TAD_community com) {
	com->posts = realloc(com->posts, sizeof(struct posts) * (com->espaco_posts + 75000));

	for (int j = com->espaco_posts; j <(com->espaco_posts + 75000); j++) {
		com->posts[j] = malloc(sizeof(struct posts));
		com->posts[j]->data= createDate(0,0,0);
		com->posts[j]->id_post = 0;
		com->posts[j]->score = 0;
		com->posts[j]->owner_user_id= 0;
		com->posts[j]->title = NULL;
		com->posts[j]->body = NULL;
		com->posts[j]->post_type_id = 0;
		com->posts[j]->parent_id=0;
		com->posts[j]->tags = NULL;
		com->posts[j]->answer_count = 0;
		com->posts[j]->comment_count = 0;
		com->posts[j]->favorite_count = NULL;
		com->posts[j]->dif_votes = 0;

	}
	com->espaco_posts+=75000;

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

int strToTag (TAD_community com, char* str, int i){
  char* token;
  const char delim[3] = "&;"; //caracteres em que a string é dividida
  token = strtok (str,delim);
  while (token != NULL){
      com->posts[i]->tags = token;
      //para testar:
      //printf("%s\n", com->posts[i]->tags);
      token = strtok (NULL, delim);
  }
  return 0;
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
           com->utilizador[i]->reputacao = atoi( (const char *) reputacao_l);

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
    printf("[load] %d Users...\n", i);
}


void getReferencePosts (xmlDocPtr doc, xmlNodePtr cur, TAD_community com) {

   xmlChar *id_l, *post_type_id_l, *creation_date_l, *score_l, *body_l, *owner_user_id_l, *parent_id_l, *title_l, *tags_l, *answer_count_l, *comment_count_l, *favorite_count_l;
   cur = cur->xmlChildrenNode;
   int i=0,id_bin, k;

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
           id_bin = procura_binaria_u(com, atoi( (const char *) owner_user_id_l),com->n_utilizadores);
           com->posts[i]->data=stringToDias( (char *) creation_date_l);
           com->utilizador[id_bin]->posts_u++;
           com->posts[i]->id_post = atoi( (const char *) id_l);
           com->posts[i]->score = atoi( (const char *) score_l);
           com->posts[i]->owner_user_id= atoi( (const char *) owner_user_id_l);
           com->posts[i]->body = body_l;
           com->posts[i]->post_type_id = atoi( (const char *) post_type_id_l);
           if(com->posts[i]->post_type_id==2) {
              com->posts[i]->parent_id = atoi( (const char *) parent_id_l);
           }
           else{
              com->posts[i]->title = title_l;
              k = strToTag(com, (char *) tags_l, i);
            }
           if(answer_count_l == NULL){ // alguns posts sem answer_count, dava segmentation fault sem esta condição
              com->posts[i]->answer_count = 0;
           }
           else{
              com->posts[i]->answer_count = atoi( (const char *) answer_count_l);
           }
           com->posts[i]->comment_count = atoi( (const char *) comment_count_l);
           com->posts[i]->favorite_count = favorite_count_l;
              
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
   printf("[load] %d Posts...\n", i);
}

void getReferenceVotes (xmlDocPtr doc, xmlNodePtr cur, TAD_community com){
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
    
    xmlDocPtr doc_user, doc_posts, doc_votes, doc_tags;
	  xmlNodePtr cur_user, cur_posts, cur_votes, cur_tags;

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

   printf("[load] Ínicio do parse do documento Tags.xml...\n");

   getReferenceTags (doc_tags,cur_tags,com);
   xmlFreeDoc(doc_tags);

   printf("[load] Parse do documento Tags.xml foi feito com sucesso...\n");

    return com;
}

// query 1

STR_pair info_from_post(TAD_community com, long id) {
	STR_pair par= create_str_pair(NULL,NULL);
	int user_id;
	int l;
    //char* t = NULL;
    //char* n = NULL;

    l = procura_binaria_p(com, id, com->posts_t); // indice do array posts onde esta o post com o id dado

	if (com->posts[l]->post_type_id == 1){	
		set_fst_str(par, (char *) com->posts[l]->title);
        //t = (char *) com->posts[l]->title;
		user_id = procura_binaria_u(com, com->posts[l]->owner_user_id, com->n_utilizadores);
		set_snd_str(par, (char *) com->utilizador[user_id]->nome);
        //n = (char *) com->utilizador[user_id]->nome;
    }
	else { //é uma resposta
		int x = procura_binaria_p(com, com->posts[l]->parent_id, com->posts_t);
		set_fst_str(par, (char *) com->posts[x]->title);
		user_id= procura_binaria_u(com, com->posts[x]->owner_user_id, com->n_utilizadores);
	    set_snd_str(par, (char *) com->utilizador[user_id]->nome);
	}
    printf("%s\n", get_fst_str(par) );
    printf("%s\n", get_snd_str(par) );
    //printf("%s\n", t);
    //printf("%s\n", n);
	return par;
}

// query 2

LONG_list top_most_active(TAD_community com, int N){
	LONG_list l = create_list(N);
	LONG_list lid = create_list(N);

	for(int i=0; i<N; i++){
		set_list(l,i,0);
		set_list(lid,i,0);
	}

	for(int i=0; i<com->n_utilizadores; i++){
		for(int j=0; j<N;j++){
			int k = get_list(l,j);
			if(com->utilizador[i]->posts_u>k){
				if(j==N-1) {
					set_list(l,j,com->utilizador[i]->posts_u); 
					set_list(lid,j,com->utilizador[i]->id);
					break;
				}
				else{
					set_list(l,j,get_list(l,j+1));
					set_list(lid,j,get_list(lid,j+1));
				}
			}
			else{
				set_list(l,j-1,com->utilizador[i]->posts_u);
				set_list(lid,j-1,com->utilizador[i]->id);
				break;
			}
		}
	}
	/*
	// deixei aqui para se testar se for preciso
	for(int i=0; i<N; i++){
		printf("número total de posts: %ld\n", get_list(l,i));
		printf("id utilizador: %ld\n\n", get_list(lid,i));
	}*/

	free_list(l);

	return lid;
}

// query 3

LONG_pair total_posts(TAD_community com, Date begin, Date end){
// devolve o numero total de perguntas e o numero total de respostas
	
	LONG_pair par = create_long_pair(0,0);

	for (int i=0; i<com->posts_t; i++) {
		if (difDatas(com->posts[i]->data,begin,end)==0) {
			if(com->posts[i]->post_type_id==1) set_fst_long(par,get_fst_long(par)+1); // se for pergunta
			else set_snd_long(par,get_snd_long(par)+1); // se for resposta
		}
	}
	/*
	printf("perguntas: %ld\n", get_fst_long(par));
	printf("respostas: %ld\n", get_snd_long(par));*/
	return par;
}

// query 4

LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end){
  LONG_list l = create_list(50);
  LONG_list res = create_list(50);
  int k=0;


  for (int i=0; i < 50 ; i++){ // inicialização da lista
    set_list(l,i,0); // vai conter os numeros das perguntas
    set_list(res,i,0); // lista q vai ser devolvida
  }

  for(int i=0; i < com->posts_t ; i++){
    if (com->posts[i]->post_type_id == 1){ // se é pergunta

      if(difDatas(com->posts[i]->data,begin,end) == 0){ // se está dentro das datas
          
          char* ret;
          ret = strstr((const char *) com->posts[i]->tags,tag);
          if (ret!=NULL) { // se o titulo contem a palavra
            set_list(l,k,com->posts[i]->id_post);
            k++;
          }
        }
      }
    }

  // no fim do 'for' a lista l tem os id's dos posts por ordem crescente, necessário inverter a ordem
  int j = 50-1;
  for (int i = 0 ; i < 50 ; i++){
    set_list(res, i, get_list(l, j)); 
    j--;
  }

  /*
  // para testar
  j = 50-1;
  for(int i = 0; i < 50; i++){
    printf("POST_ID: %ld\n", get_list(res,i) );
    j--;
  }
  */

  free_list(l);

  return res;
}

// query 5

USER get_user_info(TAD_community com, long id){


	int id_bin = procura_binaria_u(com, id, com->n_utilizadores);
	char* nbio = get_bio(com->utilizador[id_bin]->user);

	long posts[10] = {0};
	long temp;
	int i,j;

	for(i=0;i<com->posts_t;i++){
		if (com->posts[i]->owner_user_id == id){
			for(j=8;j>=0;j--){
				temp = posts[j+1];
				posts[j+1] = posts[j];
				posts[j] = temp;
			}
			posts[0] = com->posts[i]->id_post;
		}
	}

	USER new_user = create_user(nbio,posts);
	/*
	printf("%s\n", nbio);
	for(i=0;i<10;i++) printf("%ld\n", posts[i]);*/
		
	return new_user;
}

// query 6

LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end){ // da com mais respostas para a q tem menos
	LONG_list l = create_list(N);
	LONG_list lid = create_list(N);
	LONG_list res = create_list(N);


	for (int i=0; i < N ; i++){ // inicialização da lista
		set_list(l,i,0); // vai conter os numeros de respostas
		set_list(lid,i,0); // vai conter o id dos posts
		set_list(res,i,0); // lista q vai ser devolvida
	}

	for(int i=0; i < com->posts_t ; i++){
		if (com->posts[i]->post_type_id == 2){ // se é resposta

			if(difDatas(com->posts[i]->data,begin,end) == 0){ // se está dentro das datas
				
				for(int j = 0; j < N ; j++){
					int k = get_list(l,j);
					if(com->posts[i]->dif_votes > k){
						if(j == N-1) { // se está na última posição
							set_list(l,j,com->posts[i]->dif_votes); 
							set_list(lid,j,com->posts[i]->id_post);
							break;
						}
						else{
							set_list(l,j,get_list(l,j+1));
							set_list(lid,j,get_list(lid,j+1));
						}
					}
					else{
						set_list(l,j-1, com->posts[i]->dif_votes);
						set_list(lid,j-1,com->posts[i]->id_post);
						break;
					}
				}
			}
		}
	}
	// no fim do 'for' a lista lid tem os id's dos posts por ordem crescente, necessário inverter a ordem
	int j = N-1;
	for (int i = 0 ; i < N ; i++){
		set_list(res, i, get_list(lid, j)); 
		j--;
	}

	/*
	// para testar
	j = N-1;
	for(int i = 0; i < N; i++){
		printf("POST_ID: %ld\n", get_list(res,i) );
		printf("Dif votos: %ld\n", get_list(l,j) );
		j--;
	}*/

	free_list(l);
	free_list(lid);

	return res;
}


// query 7

LONG_list most_answered_questions(TAD_community com, int N, Date begin, Date end){ // da com mais respostas para a q tem menos
	LONG_list l = create_list(N);
	LONG_list lid = create_list(N);
	LONG_list res = create_list(N);


	for (int i=0; i < N ; i++){ // inicialização da lista
		set_list(l,i,0); // vai conter os numeros de respostas
		set_list(lid,i,0); // vai conter o id dos posts
		set_list(res,i,0); // lista q vai ser devolvida
	}

	for(int i=0; i < com->posts_t ; i++){
		if (com->posts[i]->post_type_id == 1){ // se é pergunta

			if(difDatas(com->posts[i]->data,begin,end) == 0){ // se está dentro das datas
				
				for(int j = 0; j < N ; j++){
					int k = get_list(l,j);
					if(com->posts[i]->answer_count > k){
						if(j == N-1) { // se está na última posição
							set_list(l,j,com->posts[i]->answer_count); 
							set_list(lid,j,com->posts[i]->id_post);
							break;
						}
						else{
							set_list(l,j,get_list(l,j+1));
							set_list(lid,j,get_list(lid,j+1));
						}
					}
					else{
						set_list(l,j-1, com->posts[i]->answer_count);
						set_list(lid,j-1,com->posts[i]->id_post);
						break;
					}
				}
			}
		}
	}
	// no fim do 'for' a lista lid tem os id's dos posts por ordem crescente, necessário inverter a ordem
	int j = N-1;
	for (int i = 0 ; i < N ; i++){
		set_list(res, i, get_list(lid, j)); 
		j--;
	}

	/*
	// para testar
	j = N-1;
	for(int i = 0; i < N; i++){
		printf("POST_ID: %ld\n", get_list(res,i) );
		printf("nº respostas: %ld\n", get_list(l,j) );
		j--;
	}*/

	free_list(l);
	free_list(lid);

	return res;
}

// query 8

LONG_list contains_word(TAD_community com, char* word, int N){
	
	LONG_list l = create_list(N);
	long posts[N];
	int temp;

	// inicialização do posts a 0
	for(int i = 0; i<N ; i++){
		posts[i] = 0;
	}

	for (int i=0; i < N ; i++){ // inicialização da lista
		set_list(l,i,0); // tem os id's das perguntas
	}
	
	for(int i=0; i < com->posts_t ; i++){
		if (com->posts[i]->post_type_id == 1){ // se é pergunta
			char* ret;
			ret = strstr((const char *) com->posts[i]->title,word);
			if (ret!=NULL) { // se o titulo contem a palavra
				for(int j=N-2;j>=0;j--){
					temp = posts[j+1];
					posts[j+1] = posts[j];
					posts[j] = temp;
				}
				posts[0] = com->posts[i]->id_post;
			}
		}
	}

	for(int i = 0; i<N ; i++){
		set_list(l,i,posts[i]);
	}
	/*
	// para testar
	for(int i = 0; i < N; i++){
		printf("ID's: %ld\n", get_list(l,i) );
	}*/

	return l;	
}

// query 9

LONG_list both_participated(TAD_community com, long id1, long id2, int N){

  LONG_list l = create_list(N);
  for (int i=0; i < N ; i++){ // inicialização da lista
    set_list(l,i,0);
  }

  for(int i=0; i<com->posts_t; i++){ // percorre todos os posts
    if(com->posts[i]->post_type_id == 1){ // vê se é pergunta
      int x1=0,x2=0;

      // para o caso de ser o id1 a fazer a pergunta
      if(com->posts[i]->owner_user_id == id1){
        x1=1;
        for(int j=i; j<com->posts_t; j++){ // percorre o resto dos posts
          if(com->posts[j]->parent_id == com->posts[i]->id_post){ // verifica se o parent_id é igual ao da pergunta em análise
            if(com->posts[j]->owner_user_id == id2){
              x2=1;
              break; // assim nao avança para o resto dos posts
            }
          }
        }
        // verifica se os dois participam na questão
        if (x1==1 && x2==1){
          for(int k = 1 ; k < N ; k++){ // isto é para arrastar um elemento para a direita
            long temp1, temp2;
            temp1 = get_list(l,0); // fica sempre com o primeiro elemento
            temp2 = get_list(l,k);
            set_list(l,0,temp2); // coloca na posição 0
            set_list(l,k,temp1); // coloca na posição i o q estava em 0
          }
          set_list(l,0, (long) com->posts[i]->id_post);
        }
      }
      else {
        // para o caso de ser o id2 a fazer a pergunta
        if(com->posts[i]->owner_user_id == id2){
          x2=1;
          for(int j=i; j<com->posts_t; j++){ // percorre o resto dos posts
            if(com->posts[j]->parent_id == com->posts[i]->id_post){ // verifica se o parent_id é igual ao da pergunta em análise
              if(com->posts[j]->owner_user_id == id1){
                x1=1;
                break; // assim nao avança para o resto dos posts
              }
            }
          }
          // verifica se os dois participam na questão
          if (x1==1 && x2==1){
            for(int k = 1 ; k < N ; k++){ // isto é para arrastar um elemento para a direita
              long temp1,temp2;
              temp1 = get_list(l,0); // fica sempre com o primeiro elemento
              temp2 = get_list(l,k);
              set_list(l,0,temp2); // coloca na posição 0
              set_list(l,k,temp1); // coloca na posição i o q estava em 0
            }
            set_list(l,0, (long) com->posts[i]->id_post);
          }
        }
        else{
          //para quando nao e nenhum a fazer a pergunta, só podem interagir nas respostas
          for(int j=i; j<com->posts_t; j++){ // percorre o resto dos posts
            if(com->posts[j]->parent_id == com->posts[i]->id_post){ // verifica se o parent_id é igual ao da pergunta em análise
              if(com->posts[j]->owner_user_id == id2) x2=1;
              if(com->posts[j]->owner_user_id == id1) x1=1;

              // verifica se os dois participam na questão
              if (x1==1 && x2==1){
                for(int k = 1 ; k < N ; k++){ // isto é para arrastar um elemento para a direita
                  long temp1, temp2;
                  temp1 = get_list(l,0); // fica sempre com o primeiro elemento
                  temp2 = get_list(l,k);
                  set_list(l,0,temp2); // coloca na posição 0
                  set_list(l,k,temp1); // coloca na posição i o q estava em 0
                }
                set_list(l,0, (long) com->posts[i]->id_post);
                break;
              }
            }
          }
        }
        }
    }
  }
  
  // teste
  for(int i = 0; i < N ; i++){
    printf("%ld\n", get_list(l,i));
  }

  return l;
}

// query 10

long better_answer(TAD_community com, long id){
	int melhor_media = 0, melhor_id = 0;
	for(int i=0; i < com->posts_t; i++){
		
		if(com->posts[i]->parent_id == id){
			int media;
			int id_bin = procura_binaria_u (com, com->posts[i]->owner_user_id, com->n_utilizadores);
			
			media = (0.45 * com->posts[i]->score) + (0.25 * com->utilizador[id_bin]->reputacao) + (0.2 * com->posts[i]->dif_votes) + (0.1 * com->posts[i]->comment_count);
		
			if (media>melhor_media){
				melhor_media = media;
				melhor_id = com->posts[i]->id_post;
			}
		}
	}
	// printf("melhor media: %d\n", melhor_media);
	return melhor_id;
}

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

// query 12

TAD_community clean(TAD_community com){
  
  for (int i=0;i<com->n_utilizadores; i++) {

      free(com->utilizador[i]->nome);
      free(&(com->utilizador[i]->id));
      free(com->utilizador[i]->user);
      free(&(com->utilizador[i]->reputacao));
      free(&(com->utilizador[i]->posts_u));
      free(com->utilizador[i]);
      free(com->utilizador);
 }

 free(com->utilizador);

  for(int i=0;i<com->posts_t;i++) {
      free(com->posts[i]->data);
      free(&(com->posts[i]->id_post));
      free(&(com->posts[i]->score));
      free(&(com->posts[i]->owner_user_id));
      free(com->posts[i]->title);
      free(com->posts[i]->body);
      free(&(com->posts[i]->post_type_id));
      free(&(com->posts[i]->parent_id));
      free(com->posts[i]->tags);
      free(&(com->posts[i]->answer_count));
      free(&(com->posts[i]->comment_count));
      free(com->posts[i]->favorite_count);
      free(&(com->posts[i]->dif_votes));
      free(com->posts[i]);
  }
  free(com->posts);
  free(&(com->n_utilizadores));
  free(&(com->espaco_users));
  free(&(com->posts_t));
  free(&(com->espaco_posts));
  return com;
}