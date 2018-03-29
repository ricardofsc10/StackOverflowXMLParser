
#include "struct.c"
#include "funções.h"
#include "list.h"


LONG_list contains_word(TAD_community com, char* word, int N){

	LONG_list l = create_list(N);
	LONG_list res= create_list(N);

	for (int i=0; i < N ; i++){ // inicialização da lista
		set_list(l,i,0); // tem os id's das perguntas
		set_list(res,i,0); // lista q vai ser devolvida
	}

	
	for(int i=0; i < com->posts_t ; i++){
		if (com->posts[i]->post_type_id == 1){ // se é pergunta

			if (strstr(com->posts->title,word)!=NULL) {// se o titulo contem a palavra

				if(i==N-1){ // se está na ultima posição
					set_list(l,i,com->posts[i]->id_post);
					break;
				}

				else set_list(l,i,com->posts[i]->id_post);

			}
		}
	}

	// no fim do 'for' a lista l tem os id's das perguntas por ordem cronologica normal, necessário inverter a ordem
	int j = N-1;
	for (int i = 0 ; i < N ; i++){
		set_list(res, i, get_list(l, j)); 
		j--;
	}
	return res;	
}

