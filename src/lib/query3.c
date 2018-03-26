#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "date.h"
#include "pair.h"
#include "struct.c"


LONG_pair total_posts(TAD_community com, Date begin, Date end){
// devolve o numero total de perguntas e o numero total de respostas
	
	LONG_pair par = create_long_pair(NULL,NULL);
	long n_perguntas=0;
	long n_respostas=0;

	for (int i=0; i<com->posts_t; i++) {
		if (difDatas(com->posts[i]->data)==0) {
			if(com->posts[i]->post_type_id==1) n_perguntas++;
			else n_respostas++;
		}
	}

	set_fst_long(par,n_perguntas);
	set_snd_long(par,n_respostas);
	return par;
}


int difDatas(Date x,Date begin, Date end) { // 0 ou -1 se está entre as datas ou n
	int inicio,fim;
	if(get_year(x) < get_year(begin)) inicio=-1;
	else if (get_year(x) == get_year(begin)) {

		if (get_month(x) < get_month(begin)) inicio=-1;
		else if (get_month(x) == get_month(begin)) {

			if (get_day(x) < get_day(begin)) inicio= -1;
			else inicio= 0;
		}
		else inicio = 0;
	}

	if(get_year(x) > get_year(end)) fim=-1;
	else if (get_year(x) == get_year(end)) {

		if (get_month(x) > get_month(end)) fim =-1;
		else if (get_month(x) == get_month(end)) {

			if (get_day(x) > get_day(end)) fim = -1;
			else fim = 0;
		}
		else fim = 0;
	}
	
	if (inicio== 0 && fim ==0) return 0;
	else return -1;
}

