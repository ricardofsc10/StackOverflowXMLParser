#include <stdlib.h>
#include "posts.h"
#include "common.h"
#include "date.h"
#include <glib.h>

struct posts{
    gint key_id_post;
    Date data;
    gint score;
    gint owner_user_id;
    gchar* title;
    gchar* body;
    gint post_type_id; // 1-pergunta 2-resposta
    gint parent_id;
    gchar* tags;
    gint answer_count;
    gint comment_count;
    gint dif_votes;
};

POSTS create_posts(){
    POSTS p = malloc(sizeof(struct posts));
    p->key_id_post = 0;
    p->data = createDate(0,0,0);
    p->score = 0;
    p->owner_user_id = 0;
    p->title = NULL;
    p->body = NULL;
    p->post_type_id = 0;
    p->parent_id = 0;
    p->tags = NULL;
    p->answer_count = 0;
    p->comment_count = 0;
    p->dif_votes = 0;
    return p;
}

long get_key_id_post(POSTS p){
    return p->key_id_post;
}

Date get_data(POSTS p){
    return p->data;
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

long get_post_type_id(POSTS p){
    return p->post_type_id;
}

long get_parent_id(POSTS p){
    return p->parent_id;
}

gchar* get_tags(POSTS p){
    return p ? mystrdup(p->tags) : NULL;
}

long get_answer_count(POSTS p){
    return p->answer_count;
}

long get_comment_count(POSTS p){
    return p->comment_count;
}

long get_dif_votes(POSTS p){
    return p->dif_votes;
}

void set_key_id_post(POSTS p, int key_id_post){
    p->key_id_post = key_id_post;
}

void set_data(POSTS p, Date data){
    p->data = data;
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
    free(p->tags);
    p->tags = mystrdup(str);
}

void set_answer_count(POSTS p, int answer_count){
    p->answer_count = answer_count;
}

void set_comment_count(POSTS p, int comment_count){
    p->comment_count = comment_count;
}

void set_dif_votes(POSTS p, int dif_votes){
    p->dif_votes = dif_votes;
}

void free_posts(POSTS p){
    if(p){
        free_date(p->data);
        free(p->title);
        free(p->body);
        free(p->tags);
        free(p);
    }
}
