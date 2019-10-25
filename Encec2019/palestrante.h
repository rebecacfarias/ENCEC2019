#ifndef PALESTRANTE_H_INCLUDED
#define PALESTRANTE_H_INCLUDED
#include "evento.h"

typedef struct palestrante palestrante;

palestrante *cadastrarP(char cpf[12],char nome[12],char email[30]);
void liberarP(palestrante *p);
void acessarP(palestrante *p,char *cpf[12],char *nome[12],char *email[30]);
void acessarEventosP(palestrante *p,char *cpf[12],char *nome[12],char *email[30]);
void modificar_infoP(palestrante *p,char nome[12],char email[30]);
void criar_evento(palestrante *p);


#endif // PALESTRANTE_H_INCLUDED
