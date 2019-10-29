#include <stdlib.h>
#include <string.h>
#include "congressista.h"

struct congressista{
    char cpf[15];
    char nome[30];
    char email[30];
    int num_cadastro;
    int codigos_eventos[10];
};

congressista *cadastrarC(char cpf[15],char nome[30],char email[30],int num_cadastro){
    congressista *c = (congressista*) malloc(sizeof(congressista));
    if(c!=NULL){
        strcpy(c->cpf,cpf);
        strcpy(c->nome,nome);
        strcpy(c->email,email);
        c->num_cadastro = num_cadastro;
    }
    return c;
}

void liberarC(congressista *c){
    free(c);
}
void acessarC(congressista *c, char *cpf[12],char *nome[30],char *email[30],int *num_cadastro){
    *cpf = c->cpf;
    *nome = c->nome;
    *email = c->email;
    *num_cadastro = c->num_cadastro;
}

void modificar_infoC(congressista *c,char nome[30],char email[30]){
    strcpy(c->nome,nome);
    strcpy(c->email,email);
}

void acessar_eventosC(congressista *c, int *eventos[10]){
    //checar se o vetor n eh vazio e se condiz com algum dos codigos dos eventos
    *eventos = c->codigos_eventos;
}
void adiciona_eventoP(congressista *c,int codigo);
void remover_eventoP(congressista *c,int codigo);


