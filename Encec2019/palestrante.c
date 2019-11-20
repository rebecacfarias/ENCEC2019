#include <stdlib.h>
#include <string.h>
#include "palestrante.h"

struct palestrante{
    char *cpf;
    char *nome;
    char *email;
    int num_cadastro;
    lista_eventos *codigos_eventos;
};
struct elemento_p{
    palestrante dados;
    elemento_p *prox;
};
struct codigos_eventoP{
    int codigo;
    codigos_eventoP *prox;
};
lista_eventos *cria_lista_eventosP(){
    lista_eventos *li = (lista_eventos*)malloc(sizeof(lista_eventos));
    if(li!=NULL)
        *li = NULL;
    return li;
}
int insere_eventoP(lista_eventos *li,int codigo){
        if(li==NULL) return 0;
        codigos_eventoP *no = (codigos_eventoP*)malloc(sizeof(codigos_eventoP));
        if(no==NULL) return 0;
        no->codigo = codigo;
        no->prox = NULL;
        if((*li)==NULL){
          *li = no;
        }else{
          codigos_eventoP *aux = *li;
          while(aux->prox!=NULL){
            aux = aux->prox;
          }
          aux->prox = no;
        }
        return 1;
      }


ListaP *cria_listaP(){
      ListaP *li = (ListaP*)malloc(sizeof(ListaP));
      if (li!=NULL)
        *li = NULL;
      return li;
}
void libera_listaP(ListaP *li){
      if(li!=NULL){
        elemento_p* no;
        while((*li)!=NULL){
          no = *li;
          *li = (*li)->prox;
          free(no);
        }
        free(li);
      }
}
int tamanho_listaP(ListaP *li){
    if(li == NULL) return 0;
    int cont = 0;
    elemento_p* no = *li;
    while(no!=NULL){
        cont++;
        no = no->prox;
      }
    return cont;
    }
int lista_vaziaP(ListaP *li){
    if(li==NULL)
        return 1;
    if(*li == NULL)
        return 1;
      return 0;
    }
int insere_lista_finalP(ListaP *li,palestrante p){
        if(li==NULL) return 0;
        elemento_p *no = (elemento_p*)malloc(sizeof(elemento_p));
        if(no==NULL) return 0;
        no->dados = p;
        no->prox = NULL;
        if((*li)==NULL){
          *li = no;
        }else{
          elemento_p *aux = *li;
          while(aux->prox!=NULL){
            aux = aux->prox;
          }
          aux->prox = no;
        }
        return 1;
      }


palestrante *cadastrarP(char *cpf,char *nome,char *email,int num_cadastro){
    palestrante *p = (palestrante*) malloc(sizeof(palestrante));
    if(p!=NULL){
        p->cpf=cpf;
        p->nome=nome;
        p->email=email;
        p->num_cadastro = num_cadastro;
    }
    return p;
}

void liberarP(palestrante *p){
    free(p);
}

void acessarP(palestrante *p,char *cpf,char *nome,char *email,int *num_cadastro){
    cpf = p->cpf;
    nome = p->nome;
    email = p->email;
    *num_cadastro = p->num_cadastro;
}

void modificar_infoP(palestrante *p,char *nome,char *email){
    p->nome=nome;
    p->email=email;
}
void adiciona_eventoP(palestrante *p,int codigo){

}
void remover_eventoP(palestrante *p,int codigo){
//implementar
}

void acessar_eventosP(palestrante *p, lista_eventos *eventos){
        eventos = p->codigos_eventos;
}
