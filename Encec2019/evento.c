#include <stdlib.h>
#include <string.h>
#include "evento.h"

//checar relevancia de alterar palestrante[] para tipo palestrante

struct evento{
    char *nome;
    int codigo;
    char *tipo;
    char *palestrante;
    char *local;
    hora carga_horaria;
    data_hora horario;
};

struct elemento_ev{
    Evento dados;
    elemento_ev *prox;
};
//tipo de lista para eventos

ListaE *cria_listaE(){
      ListaE *li = (ListaE*)malloc(sizeof(ListaE));
      if (li!=NULL)
        *li = NULL;
      return li;
}
void libera_listaE(ListaE *li){
        if(li!=NULL){
        elemento_ev* no;
        while((*li)!=NULL){
          no = *li;
          *li = (*li)->prox;
          free(no);
        }
        free(li);
      }
}
int tamanho_listaE(ListaE *li){
    if(li == NULL) return 0;
    int cont = 0;
    elemento_ev* no = *li;
    while(no!=NULL){
        cont++;
        no = no->prox;
      }
    return cont;
}
int lista_vaziaE(ListaE *li){
    if(li==NULL)
        return 1;
    if(*li == NULL)
        return 1;
      return 0;
}
int insere_lista_finalE(ListaE *li,Evento e){
     if(li==NULL) return 0;
        elemento_ev *no = (elemento_ev*)malloc(sizeof(elemento_ev));
        if(no==NULL) return 0;
        no->dados = e;
        no->prox = NULL;
        if((*li)==NULL){
          *li = no;
        }else{
          elemento_ev *aux = *li;
          while(aux->prox!=NULL){
            aux = aux->prox;
          }
          aux->prox = no;
        }
        return 1;
}

Evento *cadastrarE(char *nome,int codigo, char *tipo, char *palestrante,char *local,hora carga_horaria,data_hora horario){
    Evento *e = (Evento*) malloc(sizeof(Evento));
    if(e!=NULL){
        e->nome=nome;
        e->codigo = codigo;
        e->tipo=tipo;
        e->palestrante=palestrante;
        e->local=local;
        e->carga_horaria = carga_horaria;
        e->horario = horario;
    }
    return e;
}

void liberarE(Evento *e){
    free(e);
}

void acessarE(Evento *e, char *nome,int *codigo, char *tipo, char *palestrante,char *local,hora *carga_horaria,data_hora *horario){
    nome = e->nome;
    *codigo = e->codigo;
    tipo = e->tipo;
    palestrante = e->palestrante;
    local = e->local;
    *carga_horaria = e->carga_horaria;
    *horario = e->horario;
}

void modificar_infoE(Evento *e,char *nome, char *tipo, char *palestrante,char *local,hora carga_horaria,data_hora horario){
    strcpy(e->nome,nome);
    strcpy(e->tipo,tipo);
    strcpy(e->palestrante,palestrante);
    strcpy(e->local,local);
    e->carga_horaria = carga_horaria;
    e->horario = horario;
}




