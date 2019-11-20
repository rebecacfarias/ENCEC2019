#include <stdlib.h>
typedef struct codigos_evento codigos_evento;
typedef struct codigos_evento* lista_eventos;
struct codigos_evento{
    int codigo;
    codigos_evento *prox;
};
lista_eventos *cria_lista_eventos(){
    lista_eventos *li = (lista_eventos*)malloc(sizeof(lista_eventos));
    if(li!=NULL)
        *li = NULL;
    return li;
}
int insere_evento(lista_eventos *li,int codigo){
        if(li==NULL) return 0;
        codigos_evento *no = (codigos_evento*)malloc(sizeof(codigos_evento));
        if(no==NULL) return 0;
        no->codigo = codigo;
        no->prox = NULL;
        if((*li)==NULL){
          *li = no;
        }else{
          codigos_evento *aux = *li;
          while(aux->prox!=NULL){
            aux = aux->prox;
          }
          aux->prox = no;
        }
        return 1;
      }
