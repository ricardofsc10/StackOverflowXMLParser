#ifndef __TAG_UNIQUE__
#define __TAG_UNIQUE__

#include <glib.h>

typedef struct tag_unique * TAG_UNIQUE;

TAG_UNIQUE create_tag_unique();
long get_ocorrencias(TAG_UNIQUE t);
gchar* get_key_tag_unique_name(TAG_UNIQUE t);
void set_ocorrencias(TAG_UNIQUE t, int incremento);
void set_key_tag_unique_name(TAG_UNIQUE t, char* str);
void free_tag_unique(TAG_UNIQUE t);
#endif