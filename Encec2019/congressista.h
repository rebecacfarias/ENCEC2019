#ifndef CONGRESSISTA_H_INCLUDED
#define CONGRESSISTA_H_INCLUDED



typedef struct congressista congressista;

congressista *cadastrarC(char cpf[15],char nome[30],char email[30],int num_cadastro);
void liberarC(congressista *c);
void acessarC(congressista *c, char *cpf[12],char *nome[30],char *email[30],int *num_cadastro);
void acessar_eventosC(congressista *c, int *eventos[10]);
void modificar_infoC(congressista *c,char nome[30],char email[30]);
void adiciona_eventoC(congressista *c,int codigo);
void remover_eventoC(congressista *c,int codigo);







#endif // CONGRESSISTA_H_INCLUDED
