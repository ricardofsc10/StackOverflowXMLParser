#ifndef __POSTS__
#define __POSTS__

#include "date.h"
#include "common.h"
#include <glib.h>

typedef struct posts* POSTS;

POSTS create_posts();
long get_key_id_post(POSTS p);
Date get_data(POSTS p);
gchar* get_data_string(POSTS p);
long get_score(POSTS p);
long get_owner_user_id(POSTS p);
gchar* get_title(POSTS p);
gchar* get_body(POSTS p);
int get_post_type_id(POSTS p);
long get_parent_id(POSTS p);
GList* get_tags(POSTS p);
long get_answer_count(POSTS p);
long get_comment_count(POSTS p);
void set_key_id_post(POSTS p, int key_id_post);
void set_data(POSTS p, Date data);
void set_data_string(POSTS p, char* str);
void set_score(POSTS p, int score);
void set_owner_user_id(POSTS p, int owner_user_id);
void set_title(POSTS p, char* str);
void set_body(POSTS p, char* str);
void set_post_type_id(POSTS p, int post_type_id);
void set_parent_id(POSTS p, int parent_id);
void set_tags(POSTS p, char* str);
void set_answer_count(POSTS p, int answer_count);
void set_comment_count(POSTS p, int comment_count);
void free_posts(POSTS p);
#endif
