#include <stdlib.h>
#include "user.h"
#include "date.h"
#include "struct.h"

struct TCD_community{
	UTILIZADOR* utilizador;
	int n_utilizadores;
};

struct utilizador{
 	char* nome;
 	char* id;
 	USER user; // bio e array para 10 posts
	int n_posts;
	char* reputacao;
	POSTS* posts;
};

struct posts{
	Date data;
	char* id_post;
	char* score;
	char* title;
	char* body;
	int tipo; // 1-pergunta 2-resposta
	char** tags;
};