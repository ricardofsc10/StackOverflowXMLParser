#include <stdlib.h>
#include "tag.h"
#include "common.h"
#include <glib.h>
#include <string.h>

struct tag{
	gint key_id_tag;
	gchar* tag_name;
};

TAG create_tag(){
	TAG t = malloc(sizeof(struct tag));
	t->key_id_tag = 0;
	t->tag_name = NULL;
	return t;
}

long get_key_id_tag(TAG t){
	return t->key_id_tag;
}

gchar* get_tag_name(TAG t){
	return t ? mystrdup(t->tag_name) : NULL;
}

void set_key_id_tag(TAG t, int key_id_tag){
	t->key_id_tag = key_id_tag;
}

void set_tag_name(TAG t, char* str){
	free(t->tag_name);
	t->tag_name = mystrdup(str);
}

void free_tag(TAG t){
	if(t){
    	free(t->tag_name);
    	free(t);
	}
}