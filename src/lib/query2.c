#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "struct.c"
#include "list.h"

LONG_list top_most_active(TAD_community com, int N){
	LONG_list l = create_list(N);

	for(int i=0; i<N; i++){
		set_list(l,i,0);
	}

	for(int i=0; i<com->n_utilizadores; i++){
		for(int j=0; j<N;j++){
			int k = get_list(l,j);
			if(com->utilizador[i]->posts_u>k){
				if(j==N-1) {
					set_list(l,j,com->utilizador[i]->posts_u); 
					break;
				}
				set_list(l,j,get_list(l,j+1));
			}
			else{
				set_list(l,j-1,com->utilizador[i]->posts_u);
				break;
			}
		}
	}
	for(int i=0; i<N; i++)
		printf("%ld\n", get_list(l,i));
	return l;
}