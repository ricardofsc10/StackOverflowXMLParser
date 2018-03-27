#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "struct.c"
#include "pair.h"
#include "query1.h"

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

STR_pair info_from_post(TAD_community com, int id) {
	STR_pair par= create_str_pair(NULL,NULL);
	int user_id;
	int l;
    char* t;
    char* n;

    l = procura_binaria_p(com, id, com->posts_t); // indice do array posts onde esta o post com o id dado

	if (com->posts[l]->post_type_id == 1){	
		//set_fst_str(par, com->posts[l]->title);
        t = com->posts[l]->title;
		user_id = procura_binaria_u(com, com->posts[l]->owner_user_id, com->n_utilizadores);
		//set_snd_str(par, com->utilizador[user_id]->nome);
        n = com->utilizador[user_id]->nome;
    }
	else { //é uma resposta
		int x = procura_binaria_p(com, com->posts[l]->parent_id, com->posts_t);
		set_fst_str(par, com->posts[x]->title);
		user_id= procura_binaria_u(com, com->posts[x]->owner_user_id, com->n_utilizadores);
	    set_snd_str(par, com->utilizador[user_id]->nome);
	}
    //printf("%s\n", get_fst_str(par) );
    //printf("%s\n", get_snd_str(par) );
    printf("%s\n", t);
    printf("%s\n", n);
	return par;
}


