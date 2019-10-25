#ifndef CONGRESSISTA_H_INCLUDED
#define CONGRESSISTA_H_INCLUDED
#include "evento.h"
typedef struct congressista congressista;

congressista *cadastrarC(char cpf[12],char nome[30],char email[30],int num_cadastro);
void liberarC(congressista *c);
void acessarC(congressista *c, char *cpf[12],char *nome[30],char *email[30],int num_cadastro);
void acessar_eventosC(congressista *c, evento *eventos[10]);
void modificar_infoC(congressista *c,char nome[30],char email[30]);
void inscrever_eventoC(congressista *c, evento e);
void cancelar_inscricaoC(congressista *c, evento e);







#endif // CONGRESSISTA_H_INCLUDED
