#include "struct.c"
#include "funções.h"

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