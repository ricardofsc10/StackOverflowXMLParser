#include <stdlib.h>
#include "user.h"
#include "date.h"
#include "struct.h"
#include <libxml/parser.h>

struct TCD_community{
	UTILIZADOR* utilizador;
	int n_utilizadores;
	int espaco_estrutura;
};

struct utilizador{
 	xmlChar* nome;
 	xmlChar* id;
 	USER user; // bio e array para 10 posts
	int n_posts;
	xmlChar* reputacao;
	POSTS* posts;
};

struct posts{
	Date data;
	xmlChar* id_post;
	xmlChar* score;
	xmlChar* title;
	xmlChar* body;
	xmlChar* post_type_id; // 1-pergunta 2-resposta
	xmlChar** tags;
	xmlChar* answer_count;
	xmlChar* comment_count;
	xmlChar* favorite_count;
};