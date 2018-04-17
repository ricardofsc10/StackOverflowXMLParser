#include "interface.c"

// init

TAD_community init(){
    TAD_community tad = malloc(sizeof(struct TCD_community));
    tad->utilizador = g_hash_table_new (g_int_hash, g_int_equal);
    tad->posts = g_hash_table_new (g_int_hash, g_int_equal);
    return tad;
}