#include <stdlib.h>
#include "tag.h"
#include "common.h"
#include <glib.h>
#include <string.h>

struct tag{
	gchar* key_tag_name;
	gint id_tag;
};

TAG create_tag(){
	TAG t = malloc(sizeof(struct tag));
	t->key_tag_name = NULL;
	t->id_tag = 0;
	return t;
}

gchar* get_key_tag_name(TAG t){
	return t ? mystrdup(t->key_tag_name) : NULL;
}

long get_id_tag(TAG t){
	return t->id_tag;
}

void set_key_tag_name(TAG t, char* str){
	free(t->key_tag_name);
	t->key_tag_name = mystrdup(str);
}

void set_id_tag(TAG t, int id_tag){
	t->id_tag = id_tag;
}

void free_tag(TAG t){
	if(t){
    	free(t->key_tag_name);
    	free(t);
	}
}