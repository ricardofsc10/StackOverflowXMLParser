#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "struct.c"
#include "pair.h"
#include "query1.h"
#include "funções.h"

STR_pair info_from_post(TAD_community com, int id) {
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


