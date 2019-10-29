#ifndef PALESTRANTE_H_INCLUDED
#define PALESTRANTE_H_INCLUDED


typedef struct palestrante palestrante;

palestrante *cadastrarP(char cpf[15],char nome[30],char email[30],int num_cadastro);
void liberarP(palestrante *p);
void acessarP(palestrante *p,char *cpf[12],char *nome[12],char *email[30],int *num_cadstro);
void adiciona_eventoP(palestrante *p,int codigo);
void remover_eventoP(palestrante *p,int codigo);
void acessar_eventosP(palestrante *p, int *eventos[10]);
void modificar_infoP(palestrante *p,char nome[12],char email[30]);



#endif // PALESTRANTE_H_INCLUDED
