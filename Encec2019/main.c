#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "congressista.h"
#include "palestrante.h"
#include "organizador.h"


//fazer prototipos das funcoes q tera aq

/*
obs das tads: se for precisso coloca todos os atributos no modificar pra servir de set;
              falta implementar acrescentar e tirar do vetor de codigos;

->INICIALIZAR VETORES(deixar funcs prontas pra inicializar, remover,etc);


MENU
 - SUBMENU_CADASTRAR
 - SUBMENU_REMOVER
 - SUBMENU_EDITAR
 - SUBMENU_LISTAR

SUBMENU CADASTRAR *<tipo>*lista e *arquivo, criação de arquivo,adição na lista
 - CADASTRO_CONGRESSISTA -(inscrever em evento)(checa lotação)
 - CADASTRO_ORGANIZADOR
 - CADASTRO_PALESTRANTE  -(cadastrar evento)
 - CADASTRO_EVENTO       -(checa palestrante)-(horario/local)
SUBMENU REMOVER *<tipo> *lista e *arquivo, remover do arquivo e da lista
 - REMOVER_CONGRESSISTA -(remover da lista de participantes, arq)
 - REMOVER_PALESTRANTE -(remover eventos associados,arq)
 - REMOVER_EVENTO -(remover dos inscritos e palestrantes,arq)

SUBMENU LISTAR
 - LISTAR CONGRESSISTAS
 - LISTAR ORGANIZADORES
 - LISTAR PALESTRANTES
 - LISTAR EVENTOS

SUBMENU EDITAR *<tipo> *lista *arquivo
 - EDITAR CONGRESSISTA
 - EDITAR PALESTRANTE
 - EDITAR EVENTO

                                    tad pra horario e data juntos;
CHECAR DISPONIBILIDADE_LUGAR(lista de eventos,horario HORARIO_A_SER_AGENDADO,data,lugar);

CHECAR LOTACAO_CONGRESSO(lista de congressistas e palestrantes);

CHECAR EVENTOS_DISPONIVEIS(ver se tem algum, ver os que ainda tem vagas, ver se todos estao lotados)

CHECAR_PALESTRANTE_EVENTOS

CHECA_CONGESTIONAMENTO_HORARIO(se o horario do evento n bate com outro evento do inscrito)

MOSTRAR EVENTOS DO PALESTRANTE (RECEBE UM PALESTRANTE, PROCURA NOS EVENTOS SEU NOME, GUARDA OS CODIGOS E DPS LISTA OS CODIGOS)

CADASTRAR EM EVENTOS;
CANCELAR INSCRIÇÃO EM EVENTOS;

-> adiciona na lista de codigos dos eventos, remove, etc;
*/

int main()
{

    return 0;
}
