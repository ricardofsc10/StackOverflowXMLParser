#include <stdlib.h>

typedef struct TCD_community{
	int n_utilizador,pontos_reputacao,votacoes;
	String respostas[],tags[];
	struct nodoTCD_community *esq, * dir;
}TCD_community* pergunta;

