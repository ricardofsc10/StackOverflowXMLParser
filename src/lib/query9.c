#include "list.h"
#include "struct.c"

LONG_list both_participated(TAD_community com, long id1, long id2, int N){

int array [100] = {0};
int k=0;

	for(int i=0; i<com->posts_t; i++){
		if(com->posts[i]->post_type_id == 1){
			int x1=0,x2=0;
			if(com->posts[i]->owner_user_id == id1){
				x1=1;
				for(int j=i; j<com->posts_t; j++){
					if(com->posts[j]->parent_id == com->posts[i]->id_post){
						if(com->posts[j]->owner_user_id == id2) x2=1;
					}
				}
				if (x1==1 && x2==1){
					array[k] = com->posts[i]->id_post;
					k++;
				}
			}
		}
	}
	for(int l=0; l<N; l++)
		printf("%d\n", array[l]);
	return 0;
}