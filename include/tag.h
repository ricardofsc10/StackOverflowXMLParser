#ifndef __TAG__
#define __TAG__

#include <glib.h>

typedef struct tag * TAG;

TAG create_tag();
gchar* get_key_tag_name(TAG t);
long get_id_tag(TAG t);
void set_key_tag_name(TAG t, char* str);
void set_id_tag(TAG t, int id_tag);
void free_tag(TAG t);
#endif
