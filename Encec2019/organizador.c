#include <stdlib.h>
#include <string.h>
#include "organizador.h"

struct organizador{
    char nome[30];
    char cpf[15];
    char email[30];
};

organizador *cadastrarO(char nome[30],char cpf[15],char email[30]){
    organizador *o = (organizador*) malloc(sizeof(organizador));
    if(o!=NULL){
        strcpy(o->nome,nome);
        strcpy(o->cpf,cpf);
        strcpy(o->email,email);
    }
    return o;
}
void liberarO(organizador *o){
    free(o);
}
void acessarO(organizador *o, char *cpf[12],char *nome[30],char *email[30]){
    *cpf = o->cpf;
    *nome = o->nome;
    *email = o->email;
}
void modificar_infoO(organizador *o,char nome[30],char email[30]){
    strcpy(o->nome,nome);
    strcpy(o->email,email);
}
