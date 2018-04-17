#ifndef __POSTS__
#define __POSTS__

#include "date.h"
#include <glib.h>

typedef struct posts* POSTS;

POSTS create_posts();
gint get_key_id_post(POSTS p);
Date get_data(POSTS p);
gint get_score(POSTS p);
gint get_owner_user_id(POSTS p);
gchar* get_title(POSTS p);
gchar* get_body(POSTS p);
gint get_post_type_id(POSTS p);
gint get_parent_id(POSTS p);
gchar* get_tags(POSTS p);
gint get_answer_count(POSTS p);
gint get_comment_count(POSTS p);
gint get_dif_votes(POSTS p);
void set_key_id_post(POSTS p, int key_id_post);
void set_data(POSTS p, Date data);
void set_score(POSTS p, int score);
void set_owner_user_id(POSTS p, int owner_user_id);
void set_title(POSTS p, char* str);
void set_body(POSTS p, char* str);
void set_post_type_id(POSTS p, int post_type_id);
void set_parent_id(POSTS p, int parent_id);
void set_tags(POSTS p, char* str);
void set_answer_count(POSTS p, int answer_count);
void set_comment_count(POSTS p, int comment_count);
void set_dif_votes(POSTS p, int dif_votes);
void free_posts(POSTS p);
#endif
