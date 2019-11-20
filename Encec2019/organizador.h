#ifndef ORGANIZADOR_H_INCLUDED
#define ORGANIZADOR_H_INCLUDED

typedef struct organizador organizador;
typedef struct elemento_org* ListaO;
typedef struct elemento_org elemento_org;

organizador *cadastrarO(char *nome,char *cpf,char *email);
void liberarO(organizador *o);
void acessarO(organizador *o, char *cpf,char *nome,char *email);
void modificar_infoO(organizador *o,char *nome,char *email);
ListaO *cria_listaO();
void libera_listaO(ListaO *li);
int tamanho_listaO(ListaO *li);
int lista_vaziaO(ListaO *li);
int insere_lista_finalO(ListaO *li,organizador o);
//criar lista

//adicionar na lista

//remover da lista

//editar na lista

#endif // ORGANIZADOR_H_INCLUDED
