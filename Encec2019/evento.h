#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED
#include "data_hora.c"

typedef struct evento Evento;

Evento *cadastrarE(char nome[30],int codigo, char tipo[20], char palestrante[30],char local[20],hora carga_horaria,data_hora horario);
void liberarE(Evento *e);
void acessarE(Evento *e, char *nome[30],int *codigo, char *tipo[20], char *palestrante[30],char *local[20],hora *carga_horaria,data_hora *horario);
void modificar_infoE(Evento *e,char nome[30], char tipo[20], char palestrante[30],char local[20],hora carga_horaria,data_hora horario);



#endif // EVENTO_H_INCLUDED
