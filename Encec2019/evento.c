#include <stdlib.h>
#include <string.h>
#include "evento.h"

//checar relevancia de alterar palestrante[] para tipo palestrante

struct evento{
    char nome[30];
    int codigo;
    char tipo[20];
    char palestrante[30];
    char local[20];
    hora carga_horaria;
    data_hora horario;
};

Evento *cadastrarE(char nome[30],int codigo, char tipo[20], char palestrante[30],char local[20],hora carga_horaria,data_hora horario){
    Evento *e = (Evento*) malloc(sizeof(Evento));
    if(e!=NULL){
        strcpy(e->nome,nome);
        e->codigo = codigo;
        strcpy(e->tipo,tipo);
        strcpy(e->palestrante,palestrante);
        strcpy(e->local,local);
        e->carga_horaria = carga_horaria;
        e->horario = horario;
    }
    return e;
}

void liberarE(Evento *e){
    free(e);
}

void acessarE(Evento *e, char *nome[30],int *codigo, char *tipo[20], char *palestrante[30],char *local[20],hora *carga_horaria,data_hora *horario){
    *nome = e->nome;
    *codigo = e->codigo;
    *tipo = e->tipo;
    *palestrante = e->palestrante;
    *local = e->local;
    *carga_horaria = e->carga_horaria;
    *horario = e->horario;
}

void modificar_infoE(Evento *e,char nome[30], char tipo[20], char palestrante[30],char local[20],hora carga_horaria,data_hora horario){
    strcpy(e->nome,nome);
    strcpy(e->tipo,tipo);
    strcpy(e->palestrante,palestrante);
    strcpy(e->local,local);
    e->carga_horaria = carga_horaria;
    e->horario = horario;
}




