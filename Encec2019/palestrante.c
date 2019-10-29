#include <stdlib.h>
#include <string.h>
#include "palestrante.h"

struct palestrante{
    char cpf[15];
    char nome[30];
    char email[30];
    int num_cadastro;
    int codigos_eventos[10];
};

palestrante *cadastrarP(char cpf[15],char nome[30],char email[30],int num_cadastro){
    palestrante *p = (palestrante*) malloc(sizeof(palestrante));
    if(p!=NULL){
        strcpy(p->cpf,cpf);
        strcpy(p->nome,nome);
        strcpy(p->email,email);
        p->num_cadastro = num_cadastro;
    }
    return p;
}

void liberarP(palestrante *p){
    free(p);
}

void acessarP(palestrante *p,char *cpf[12],char *nome[12],char *email[30],int *num_cadastro){
    *cpf = p->cpf;
    *nome = p->nome;
    *email = p->email;
    *num_cadastro = p->num_cadastro;
}

void modificar_infoP(palestrante *p,char nome[12],char email[30]){
    strcpy(p->nome,nome);
    strcpy(p->email,email);
}
void adiciona_eventoP(palestrante *p,int codigo){
    //implementar
}
void remover_eventoP(palestrante *p,int codigo){
//implementar
}

void acessar_eventosP(palestrante *p, int *eventos[10]){
        *eventos = p->codigos_eventos;
}
