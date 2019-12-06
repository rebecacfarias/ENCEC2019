#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "arquivo.h"




void cadastrar_congressista();
void cadastrar_palestrante();
void cadastrar_evento();
void cadastrar_organizador();

void editar_congressista();
void editar_evento();
void editar_organizador();
void editar_palestrante();

void listar_congressista();
void listar_evento();
void listar_organizador();
void listar_palestrante();

void remover_congressista();
void remover_evento();
void remover_organizador();
void remover_palestrante();

void submenu_cadastrar();
void submenu_remover();
void submenu_editar();
void submenu_listar();
void submenu_ja_cadastrado();
//coisinhas
void pontinhos(){
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
        Sleep(50);
        printf(".");
    }
}
}
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

void menu(){
    system("cls");
    pontinhos();
    int op=0;
    printf("\nGERENCIAMENTO ENCEC 2019\n");
    printf("1 - CADASTRAR\n");
    printf("2 - EDITAR\n");
    printf("3 - REMOVER\n");
    printf("4- LISTAR\n");
    scanf("%d",&op);
    while(op<=0||op>4){
        system("cls");
        printf("GERENCIAMENTO ENCEC 2019\n");
        printf("1 - CADASTRAR\n");
        printf("2 - EDITAR\n");
        printf("3 - REMOVER\n");
        printf("4 - LISTAR\n");
        printf("5 - PARTICIPANTE CADASTRADO\n");
        scanf("%d",&op);
    }
    switch(op){
    case 1: submenu_cadastrar(); break;
    case 2: submenu_editar(); break;
    case 3: submenu_remover(); break;
    case 4: submenu_listar();break;
    case 5: submenu_ja_cadastrado();break;
    default: menu();
    }
    printf("\nPRESSIONE QUALQUER TECLA PARA VOLTAR AO INICIO");
    setbuf(stdin,NULL);
    getchar();
    menu();
}
void submenu_cadastrar(){
    system("cls");
    //pontinhos();
    Sleep(300);
    system("cls");
    int op=0;
    printf("CADASTRAMENTO ENCEC 2019\n");
    printf("1 - CADASTRAR CONGRESSISTA\n");
    printf("2 - CADASTRAR PALESTRANTE\n");
    printf("3 - CADASTRAR EVENTO\n");
    printf("4 - CADASTRAR ORGANIZADOR\n");
    printf("5 - VOLTAR AO GERENCIAMENTO\n");
    printf("DIGITE 1,2,3,4 OU 5: ");
    scanf("%d",&op);
    while(op<=0||op>5){
        system("cls");
        printf("CADASTRAMENTO ENCEC 2019\n");
        printf("1 - CADASTRAR CONGRESSISTA\n");
        printf("2 - CADASTRAR PALESTRANTE\n");
        printf("3 - CADASTRAR EVENTO\n");
        printf("4 - CADASTRAR ORGANIZADOR\n");
        printf("5 - VOLTAR AO GERENCIAMENTO\n");
        printf("DIGITE 1,2,3,4 OU 5: ");
        scanf("%d",&op);
    }

    if(op==1){
        cadastrar_congressista();
    }

    else if (op == 2){
         cadastrar_palestrante();
    }
    else if (op ==3){
        cadastrar_evento();
    }
    else if(op == 4){

    }
    else{menu();}
}
void submenu_editar(){
    system("cls");
    pontinhos();
    Sleep(300);
    system("cls");
    int op=0;
    printf("(EDITAR) ENCEC 2019\n");
    printf("1 - EDITAR CONGRESSISTA\n");
    printf("2 - EDITAR PALESTRANTE\n");
    printf("3 - EDITAR EVENTO\n");
    printf("4 - EDITAR ORGANIZADOR\n");
    printf("5 - VOLTAR AO GERENCIAMENTO\n");
    scanf("%d",&op);
    while(op<=0||op>5){
        system("cls");
        printf("(EDITAR) ENCEC 2019\n");
        printf("1 - EDITAR CONGRESSISTA\n");
        printf("2 - EDITAR PALESTRANTE\n");
        printf("3 - EDITAR EVENTO\n");
        printf("4 - EDITAR ORGANIZADOR\n");
        printf("5 - VOLTAR AO GERENCIAMENTO\n");
        scanf("%d",&op);
    }
    switch(op){
    case 1: editar_congressista();break;
    case 2: editar_palestrante();break;
    case 3: editar_evento();break;
    case 4: editar_organizador();break;
    default: menu();
    }
}
void submenu_remover(){
    system("cls");
    pontinhos();
    Sleep(300);
    system("cls");
    int op=0;
    printf("(REMOVER) ENCEC 2019\n\n");
    printf("1 - REMOVER CONGRESSISTA\n");
    printf("2 - REMOVER PALESTRANTE\n");
    printf("3 - REMOVER EVENTO\n");
    printf("4 - REMOVER ORGANIZADOR\n");
    printf("5 - VOLTAR AO GERENCIAMENTO");
    scanf("%d",&op);
    while(op<=0||op>5){
        system("cls");
        printf("(REMOVER) ENCEC 2019\n");
        printf("1 - REMOVER CONGRESSISTA\n");
        printf("2 - REMOVER PALESTRANTE\n");
        printf("3 - REMOVER EVENTO\n");
        printf("4 - REMOVER ORGANIZADOR\n");
        printf("5 - VOLTAR AO GERENCIAMENTO\n");
        scanf("%d",&op);
    }
    switch(op){
    case 1: remover_congressista();break;
    case 2: remover_palestrante();break;
    case 3: remover_evento();break;
    case 4: remover_organizador();break;
    default: menu();
    }
}
void submenu_listar(){
     system("cls");
    pontinhos();
    Sleep(300);
    system("cls");
    int op=0;
    printf("(LISTAR) ENCEC 2019\n");
    printf("1 - LISTAR CONGRESSISTAS\n");
    printf("2 - LISTAR PALESTRANTES\n");
    printf("3 - LISTAR EVENTOS\n");
    printf("4 - LISTAR ORGANIZADORES\n");
    printf("5 - VOLTAR AO GERENCIAMENTO\n");
    scanf("%d",&op);
    while(op<=0||op>5){
        system("cls");
        printf("(LISTAR) ENCEC 2019\n");
        printf("1 - LISTAR CONGRESSISTAS\n");
        printf("2 - LISTAR PALESTRANTES\n");
        printf("3 - LISTAR EVENTOS\n");
        printf("4 - LISTAR ORGANIZADORES\n");
        printf("5 - VOLTAR AO GERENCIAMENTO\n");
        scanf("%d",&op);
    }
    switch(op){
    case 1: listar_congressista();break;
    case 2: listar_palestrante();break;
    case 3: listar_evento();break;
    case 4: listar_organizador();break;
    default: menu();
    }
}

void submenu_ja_cadastrado(){
}
int submenu_logar(){
    pontinhos();
    system("cls");
    char cpf[15];
    printf("\nGERENCIAMENTO ENCEC 2019\n");
    printf("- CPF: ");
    setbuf(stdin,NULL);
    gets(cpf);
    if(pesquisa_no_arquivo(ARQ_ORGANIZADORES,cpf)){
        menu();
        return 1;
    }
    else{
      printf("ACESSO NEGADO!");
      printf("\n<pressione enter para voltar ao inicio>");
      Sleep(200);
      return 0;
    }


}

int tela_inicial(){
    system("cls");
    pontinhos();
    int op=0;
    printf("\nGERENCIAMENTO ENCEC 2019\n");
    printf("1 - CADASTRAR ORGANIZADOR\n");
    printf("2 - LOGAR COMO ORGANIZADOR\n");
    printf("0 - SAIR\n");
    scanf("%d",&op);
    while(op<0||op>2){
        system("cls");
        printf("\nGERENCIAMENTO ENCEC 2019\n");
        printf("1 - CADASTRAR ORGANIZADOR\n");
        printf("2 - LOGAR COMO ORGANIZADOR\n");
        printf("0 - SAIR\n");
        scanf("%d",&op);
    }
    switch(op){
    case 1: cadastrar_organizador(); break;
    case 2: submenu_logar(); break;
    default: return 0;
    }
    tela_inicial();
    return 0;
}

int main(){

    tela_inicial();
    return 0;
}
