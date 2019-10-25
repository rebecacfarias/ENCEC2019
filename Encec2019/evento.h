#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED
#import "congressista.h"
typedef struct evento evento;

evento *cadastrarE(char nome[30],int codigo, char tipo[20], char palestrante[30],char local[20],char carga_horaria[6],char horario[6]);
void liberarE(evento *e);
void acessarE(evento *e, char *nome[30],int *codigo, char *tipo[20], char *palestrante[30],char *local[20],char *carga_horaria[6],char *horario[6]);
void modificar_infoE(evento *e,char nome[30], char tipo[20], char palestrante[30],char local[20],char carga_horaria[6],char horario[6]);



#endif // EVENTO_H_INCLUDED
