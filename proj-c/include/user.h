#ifndef __USER__
#define __USER__

/**
@file user.h
User do projeto.
*/

typedef struct user* USER;

/**
\brief Função que cria uma estrutura USER.

@returns Estrutura inicializada de USER.
*/

USER create_user(char* short_bio, long* post_history);

/**
\brief Função que recebe uma estrutura USER e retorna a biografia do utilzador.

@param p Estrutura USER.

@returns Biografia do user .
*/

char* get_bio(USER u);

/**
\brief Função que recebe uma estrutura USER e retorna o últimos 10 posts feitos pelo user.

@param p Estrutura USER.

@returns Nº de posts feitos pelo user.
*/

long* get_10_latest_posts(USER u); // caso um utilizador tenha menos 
                                   // de 10 posts, por -1 como padding 

/**
\brief Função que recebe uma estrutura USER e liberta a memória alocada por esta.

@param u User.
*/

void free_user(USER u);

#endif
