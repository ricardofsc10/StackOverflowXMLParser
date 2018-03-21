#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "struct.c"



TAD_community load(TAD_community com, char* dump_path){
	xmlDocPtr doc_user, doc_posts;
	xmlNodePtr cur_user, cur_posts;

	doc_user = xmlParseFile("Users.xml");
	doc_posts = xmlParseFile("Posts.xml");

	if (doc_user == NULL || doc_posts == NULL ) {
        fprintf(stderr,"Document not parsed successfully. \n");
    }

    cur_user = xmlDocGetRootElement(doc_user);
    cur_posts = xmlDocGetRootElement(doc_posts);


    return com;
}
