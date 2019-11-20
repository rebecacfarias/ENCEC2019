#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "congressista.h"



struct codigos_eventoC{
    int codigo;
    codigos_eventoC *prox;
};
lista_eventosC *cria_lista_eventosC(){
    lista_eventosC *li = (lista_eventosC*)malloc(sizeof(lista_eventosC));
    if(li!=NULL)
        *li = NULL;
    return li;
}

int insere_eventoC(lista_eventosC *li,int codigo){
        if(li==NULL) return 0;
        codigos_eventoC *no = (codigos_eventoC*)malloc(sizeof(codigos_eventoC));
        if(no==NULL) return 0;
        no->codigo = codigo;
        no->prox = NULL;
        if((*li)==NULL){
          *li = no;
        }else{
          codigos_eventoC *aux = *li;
          while(aux->prox!=NULL){
            aux = aux->prox;
          }
          aux->prox = no;
        }
        return 1;
}



