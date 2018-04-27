#include <stdlib.h>
#include "posts.h"
#include "common.h"
#include "date.h"
#include <glib.h>

struct posts{
    gint key_id_post;
    Date data;
    gchar* data_string;
    gint score;
    gint owner_user_id;
    gchar* title;
    gchar* body;
    gint post_type_id; // 1-pergunta 2-resposta
    gint parent_id;
    GList* tags;
    gint comment_count;
};

POSTS create_posts(){
    POSTS p = malloc(sizeof(struct posts));
    p->key_id_post = 0;
    p->data = createDate(0,0,0);
    p->data_string = NULL;
    p->score = 0;
    p->owner_user_id = 0;
    p->title = NULL;
    p->body = NULL;
    p->post_type_id = 0;
    p->parent_id = 0;
    p->tags = NULL;
    p->comment_count = 0;
    return p;
}

long get_key_id_post(POSTS p){
    return p->key_id_post;
}

Date get_data(POSTS p){
    return p->data;
}

gchar* get_data_string(POSTS p){
    return p ? mystrdup(p->data_string) : NULL;
}

long get_score(POSTS p){
    return p->score;
}

long get_owner_user_id(POSTS p){
    return p->owner_user_id;
}

gchar* get_title(POSTS p){
    return p ? mystrdup(p->title) : NULL;
}

gchar* get_body(POSTS p){
    return p ? mystrdup(p->body) : NULL;
}

int get_post_type_id(POSTS p){
    return p->post_type_id;
}

long get_parent_id(POSTS p){
    return p->parent_id;
}

GList* get_tags(POSTS p){
    return p->tags;
}

long get_comment_count(POSTS p){
    return p->comment_count;
}

void set_key_id_post(POSTS p, int key_id_post){
    p->key_id_post = key_id_post;
}

void set_data(POSTS p, Date data){
    p->data = data;
}

void set_data_string(POSTS p, char* str){
    free(p->data_string);
    p->data_string = mystrdup(str);
}

void set_score(POSTS p, int score){
    p->score = score;
}

void set_owner_user_id(POSTS p, int owner_user_id){
    p->owner_user_id = owner_user_id;
}

void set_title(POSTS p, char* str){
    free(p->title);
    p->title = mystrdup(str);
}

void set_body(POSTS p, char* str){
    free(p->body);
    p->body = mystrdup(str);
}

void set_post_type_id(POSTS p, int post_type_id){
    p->post_type_id = post_type_id;
}

void set_parent_id(POSTS p, int parent_id){
    p->parent_id = parent_id;
}

void set_tags(POSTS p, char* str){
    p->tags = g_list_prepend(p->tags, str);
}

void set_comment_count(POSTS p, int comment_count){
    p->comment_count = comment_count;
}

void free_posts(POSTS p){
    if(p){
        free_date(p->data);
        free(p->data_string);
        free(p->title);
        free(p->body);

        // liberta a glist tags
        while(p->tags != NULL){
            p->tags = g_list_remove(p->tags, (p->tags)->data);
        }
        g_list_free (p->tags);

        free(p);
    }
}
