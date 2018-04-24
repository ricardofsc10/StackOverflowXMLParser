#ifndef __TAG__
#define __TAG__

#include <glib.h>

typedef struct tag * TAG;

TAG create_tag();
long get_id_tag(TAG t);
gchar* get_tag_name(TAG t);
void set_key_id_tag(TAG t, int key_id_tag);
void set_tag_name(TAG t, char* str);
void free_tag(TAG t);
#endif
