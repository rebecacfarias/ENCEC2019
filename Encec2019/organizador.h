#ifndef ORGANIZADOR_H_INCLUDED
#define ORGANIZADOR_H_INCLUDED

typedef struct organizador organizador;

organizador *cadastrarO(char nome[30],char cpf[15],char email[30]);
void liberarO(organizador *o);
void acessarO(organizador *o, char *cpf[12],char *nome[30],char *email[30]);
void modificar_infoO(organizador *o,char nome[30],char email[30]);

#endif // ORGANIZADOR_H_INCLUDED
