#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "struct.c"

void getReferenceUser (xmlDocPtr doc, xmlNodePtr cur) {

   xmlChar *nome_l, *id_l, *bio_l;
   cur = cur->xmlChildrenNode;
   while (cur != NULL) {
       if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
       	   id_l = xmlGetProp(cur, "Id");
           nome_l = xmlGetProp(cur, "DisplayName");
           bio_l = xmlGetProp(cur, "AboutMe");
           xmlFree(id_l);
           xmlFree(nome_l);
           xmlFree(bio_l);
       }
       cur = cur->next;
   }
}

void getReferencePosts (xmlDocPtr doc, xmlNodePtr cur) {

   xmlChar *id_l, *post_type_id_l, *creation_date_l, *score_l, *body_l, *owner_user_id_l, *title_l, *tags_l;
   cur = cur->xmlChildrenNode;
   while (cur != NULL) {
       if ((!xmlStrcmp(cur->name, (const xmlChar *)"row"))) {
       	   id_l = xmlGetProp(cur, "Id");
       	   post_type_id_l = xmlGetProp(cur, "PostTypeId");
       	   creation_date_l = xmlGetProp(cur, "CreationDate");
       	   score_l = xmlGetProp(cur, "Score");
       	   body_l = xmlGetProp(cur, "Body");
           owner_user_id_l = xmlGetProp(cur, "OwnerUserId");
           title_l = xmlGetProp(cur, "Title");
           tags_l = xmlGetProp(cur, "Tags");
           xmlFree(id_l);
           xmlFree(post_type_id_l);
           xmlFree(creation_date_l);
           xmlFree(score_l);
           xmlFree(body_l);
           xmlFree(owner_user_id_l);
           xmlFree(title_l);
           xmlFree(tags_l);
       }
       cur = cur->next;
   }
}



TAD_community load(TAD_community com, char* dump_path){
	xmlDocPtr doc_user, doc_posts;
	xmlNodePtr cur_user, cur_posts;


	doc_user = xmlParseFile("Users.xml");

	if (doc_user == NULL) {
        fprintf(stderr,"Document not parsed successfully. \n");
        return 0;
    }


    cur_user = xmlDocGetRootElement(doc_user);

    if (cur_user == NULL) {
        fprintf(stderr,"empty document\n");
        xmlFreeDoc(doc_user);
        return 0;
    }

    if (xmlStrcmp(cur_user->name, (const xmlChar *) "users")) {
        fprintf(stderr,"document of the wrong type, root node != users\n");
        xmlFreeDoc(doc_user);
        return 0;
    }

    getReferenceUser (doc_user,cur_user);
    xmlFreeDoc(doc_user);


	doc_posts = xmlParseFile("Posts.xml");

	if (doc_posts == NULL) {
        fprintf(stderr,"Document not parsed successfully. \n");
        return 0;
    }

    cur_posts = xmlDocGetRootElement(doc_posts);

    if (cur_posts == NULL) {
        fprintf(stderr,"empty document\n");
        xmlFreeDoc(doc_posts);
        return 0;
    }

    if (xmlStrcmp(cur_posts->name, (const xmlChar *) "posts")) {
        fprintf(stderr,"document of the wrong type, root node != posts\n");
        xmlFreeDoc(doc_posts);
        return 0;
    }

    getReferencePosts (doc_posts,cur_posts);
    xmlFreeDoc(doc_posts);

    return com;
}
