#ifndef PALESTRANTE_H_INCLUDED
#define PALESTRANTE_H_INCLUDED


typedef struct palestrante palestrante;
typedef struct elemento_p elemento_p;
typedef struct elemento_p* ListaP;
typedef struct codigos_eventoP codigos_eventoP;
typedef struct codigos_eventoP* lista_eventos;

lista_eventos *cria_lista_eventosP();
int insere_eventoP(lista_eventos *li,int codigo);
ListaP *cria_listaP();
void libera_listaP(ListaP *li);
int tamanho_listaP(ListaP *li);
int lista_vaziaP(ListaP *li);
int insere_lista_finalP(ListaP *li,palestrante p);

palestrante *cadastrarP(char *cpf,char *nome,char *email,int num_cadastro);
void liberarP(palestrante *p);
void acessarP(palestrante *p,char *cpf,char *nome,char *email,int *num_cadstro);
void adiciona_eventoP(palestrante *p,int codigo);
void remover_eventoP(palestrante *p,int codigo);
void acessar_eventosP(palestrante *p, lista_eventos *eventos);
void modificar_infoP(palestrante *p,char *nome,char *email);


//criar lista

//adicionar na lista

//remover da lista

//editar na lista


#endif // PALESTRANTE_H_INCLUDED
