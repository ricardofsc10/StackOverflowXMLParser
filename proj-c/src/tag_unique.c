#include <stdlib.h>
#include "tag_unique.h"
#include "common.h"
#include <glib.h>
#include <string.h>

struct tag_unique{
	gchar* key_tag_unique_name;
	gint ocorrencias;
};

TAG_UNIQUE create_tag_unique(){
	TAG_UNIQUE t = malloc(sizeof(struct tag_unique));
	t->key_tag_unique_name = NULL;
	t->ocorrencias = 0;
	return t;
}

long get_ocorrencias(TAG_UNIQUE t){
	return t->ocorrencias;
}

gchar* get_key_tag_unique_name(TAG_UNIQUE t){
	return t ? mystrdup(t->key_tag_unique_name) : NULL;
}

void set_ocorrencias(TAG_UNIQUE t, int incremento){
	t->ocorrencias = t->ocorrencias + incremento;
}

void set_key_tag_unique_name(TAG_UNIQUE t, char* str){
	free(t->key_tag_unique_name);
	t->key_tag_unique_name = mystrdup(str);
}

void free_tag_unique(TAG_UNIQUE t){
	if(t){
    	free(t->key_tag_unique_name);
    	free(t);
	}
}