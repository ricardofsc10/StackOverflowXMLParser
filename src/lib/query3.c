#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "struct.c"

LONG_pair total_posts(TAD_community com, Date begin, Date end){
// devolve o numero total de perguntas e o numero total de respostas
	par = create_long_pair(NULL,NULL);
	long n_perguntas=0;
	long n_respostas=0;

	for (int i=0; i<posts_t; i++) {
		if (difDatas(stringToDias(com->posts[i]->data))==0) {
			if(com->posts[i]->post_type_id==1) n_perguntas++;
			else n_respostas++;
		}
	}

	set_fst_long(par,n_perguntas);
	set_snd_long(par,n_respostas);
	return par;
}







Date stringToDias (char* data) { // "2011-11-11"
	Date data = malloc(sizeof (struct date));
	char ano[4];
	char mes[2];
	char dia[2];
	int i;
	for (i=0;i<4;i++)
		ano[i]=data[i];
	for(i=5; i<7;i++)
		mes[i]=data[i];
	for(i=8; i<10;i++)
		dia[i]=data[i];
	data.day=dia;
	data.month=mes;
	data.ano=ano;
}

int difDatas(Date x,Date inicio, Date fim) { // 0 ou -1 se está entre as datas ou n
	int inicio, fim;
	if(x->year < inicio->year) inicio=-1;
	else if (x->year == inicio->year) {

		if (x->month <inicio->month) inicio=-1;
		else if (x->month == inicio ->month) {

			if (x->day < inicio->day) inicio= -1;
			else inicio= 0;
		}
		else inicio = 0;
	}

	if(x->year > fim->year) fim=-1;
	else if (x->year == fim->year) {

		if (x->month > fim->month) fim =-1;
		else if (x->month == fim ->month) {

			if (x->day > fim->day) fim = -1;
			else fim = 0;
		}
		else fim = 0;
	}
	
	if (inicio== 0 && fim ==0) return 0;
	else return -1;
}