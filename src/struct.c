#include <stdlib.h>
#include "user.h"


typedef struct TCD_community{
	UTILIZADOR utilizador[];
} TCD_community * TCD_community;

typedef struct utilizador{
 	char* nome;
 	char* id;
 	user user; // bio e array para 10 posts
	int n_posts;
	char* reputacao;
	POSTS posts[];
} UTILIZADOR * utilizador;

typedef struct posts{
	Date data;
	char* id_post;
	char* score;
	char* title;
	char* post;
	int tipo; // 1-pergunta 2-resposta
	char* tags[];
} POSTS * posts;