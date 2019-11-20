#include <stdlib.h>
#include <string.h>
#include "organizador.h"

struct organizador{
    char *nome;
    char *cpf;
    char *email;
};

struct elemento_org{
    organizador dados;
    elemento_org *prox;
};
//tipo de lista para organizador
ListaO *cria_listaO(){
      ListaO *li = (ListaO*)malloc(sizeof(ListaO));
      if (li!=NULL)
        *li = NULL;
      return li;
}
void libera_listaO(ListaO *li){
      if(li!=NULL){
        elemento_org* no;
        while((*li)!=NULL){
          no = *li;
          *li = (*li)->prox;
          free(no);
        }
        free(li);
      }
}
int tamanho_listaO(ListaO *li){
    if(li == NULL) return 0;
    int cont = 0;
    elemento_org* no = *li;
    while(no!=NULL){
        cont++;
        no = no->prox;
      }
    return cont;
    }
int lista_vaziaO(ListaO *li){
    if(li==NULL)
        return 1;
    if(*li == NULL)
        return 1;
      return 0;
    }
int insere_lista_finalO(ListaO *li,organizador o){
        if(li==NULL) return 0;
        elemento_org *no = (elemento_org*)malloc(sizeof(elemento_org));
        if(no==NULL) return 0;
        no->dados = o;
        no->prox = NULL;
        if((*li)==NULL){
          *li = no;
        }else{
          elemento_org *aux = *li;
          while(aux->prox!=NULL){
            aux = aux->prox;
          }
          aux->prox = no;
        }
        return 1;
      }

organizador *cadastrarO(char *nome,char *cpf,char *email){
    organizador *o = (organizador*) malloc(sizeof(organizador));
    if(o!=NULL){
        o->nome=nome;
        o->cpf=cpf;
        o->email=email;
    }
    return o;
}
void liberarO(organizador *o){
    free(o);
}
void acessarO(organizador *o, char *cpf,char *nome,char *email){
    cpf = o->cpf;
    nome = o->nome;
    email = o->email;
}
void modificar_infoO(organizador *o,char *nome,char *email){
    o->nome=nome;
    o->email=email;
}
