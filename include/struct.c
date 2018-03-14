#include <stdlib.h>
#include "user.h"


typedef struct TCD_community{
	user utilizador;
	INFO info;
} TCD_community * TCD_community;

typedef struct info{
	int n_posts;
	int reputacao;
	POSTS posts[];
} INFO * info;

typedef struct posts{
	Date data;
	char* id_post;
	char* perguntas[];	
	int tipo; //0 //1
}
