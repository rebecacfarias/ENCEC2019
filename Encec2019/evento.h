#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED
#include "data_hora.c"

typedef struct evento Evento;
typedef struct elemento_ev* ListaE;
typedef struct elemento_ev elemento_ev;

Evento *cadastrarE(char *nome,int codigo, char *tipo, char *palestrante,char *local,hora carga_horaria,data_hora horario);
void liberarE(Evento *e);
void acessarE(Evento *e, char *nome,int *codigo, char *tipo, char *palestrante,char *local,hora *carga_horaria,data_hora *horario);
void modificar_infoE(Evento *e,char *nome, char *tipo, char *palestrante,char *local,hora carga_horaria,data_hora horario);

ListaE *cria_listaE();
void libera_listaE(ListaE *li);
int tamanho_listaE(ListaE *li);
int lista_vaziaE(ListaE *li);
int insere_lista_finalE(ListaE *li,Evento e);


#endif // EVENTO_H_INCLUDED
