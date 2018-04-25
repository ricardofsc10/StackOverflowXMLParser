#ifndef __DATE_H__
#define __DATE_H__

/**
@file clean.h
Função clean do projeto.
*/

typedef struct date* Date;

/**
\brief Função que cria uma data no formato Date.

@param day Dia.
@param month Mês.
@param year Ano.

@returns A data tipo Date.
*/

Date createDate(int day, int month, int year);

/**
\brief Função que retorna o dia de uma data.

@param d Data.

@returns O inteiro dia.
*/

int get_day(Date d);

/**
\brief Função que retorna o mês de uma data.

@param d Data.

@returns O inteiro mês.
*/

int get_month(Date d); // must return a value between 0 and 11 

/**
\brief Função que retorna o ano de uma data.

@param d Data.

@returns O inteiro ano.
*/
int get_year(Date d);

/**
\brief Função que liberta a memória alocada por uma data.

@param d Data.
*/

void free_date(Date d);
#endif
