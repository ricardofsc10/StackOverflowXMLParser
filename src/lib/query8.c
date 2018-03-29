#include <string.h>
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

			//if (strstr( (const char *) com->posts[i]->title,word)!=NULL) {// se o titulo contem a palavra

				
					set_list(l,i,50);

			//}
		}
	}

	// no fim do 'for' a lista l tem os id's das perguntas por ordem cronologica normal, necessário inverter a ordem
	/*int j = N-1;
	for (int i = 0 ; i < N ; i++){
		set_list(res, i, get_list(l, j)); 
		j--;
	}*/
	
	// para testar
	int j = N-1;
	for(int i = 0; i < N; i++){
		printf("nº respostas: %ld\n", get_list(l,j) );
		j--;
	}

	return res;	
}

