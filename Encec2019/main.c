#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "arquivo.h"

char cod_eventos1[26][1] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","X","W","Y","Z"};
char cod_eventos2[26][1] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","x","w","y","z"};

int inscricao1(char nome[30],char cpf[15]);

int tela_inicial();
void cadastrar_congressista();
void cadastrar_palestrante();
void cadastrar_evento();
void cadastrar_organizador();
int cadastrar_evento2(char *nome, char*cpf);

void editar_congressista();
void editar_evento();
void editar_organizador();
void editar_palestrante();

void listar_congressista();
void listar_evento();
void listar_organizador();
void listar_palestrante();
int listar_inscricoes();
int listar_inscritos();
int listar_palestras(char *cpf,char cod_eventos1[26][1],char cod_eventos2[26][1]);
int listar_eventos(char *cpf,char cod_eventos1[26][1],char cod_eventos2[26][1],char *tipo);

void remover_congressista();
void remover_evento();
void remover_organizador();
void remover_palestrante();

void submenu_cadastrar();
void submenu_remover();
void submenu_editar();
void submenu_listar();
int submenu_ja_cadastrado();

void pontinhos();
void linhas();

void cabecalho(){
    pontinhos();
    printf("\n\t\t\tGERENCIAMENTO ENCEC 2019\n");
    printf("\n\t\t_______________________________________\n");
}
void linha(){
    printf("\n\t\t_______________________________________\n");
}

void menu(){
    system("cls");
    int op=0;
    cabecalho();
    printf("\n\t\t\t1 - CADASTRAR\n");
    printf("\n\t\t\t2 - EDITAR\n");
    printf("\n\t\t\t3 - REMOVER\n");
    printf("\n\t\t\t4 - LISTAR\n");
    printf("\n\t\t\t5 - PARTICIPANTE CADASTRADO\n");
    printf("\n\t\t\t6 - SAIR\n");
    printf("\n\t\t\t-> ");

    scanf("%d",&op);
    while(op<=0||op>6){
        system("cls");
        printf("\n\t\t\tGERENCIAMENTO ENCEC 2019\n");
        linha();
        printf("\n\t\t\t1 - CADASTRAR\n");
        printf("\n\t\t\t2 - EDITAR\n");
        printf("\n\t\t\t3 - REMOVER\n");
        printf("\n\t\t\t4 - LISTAR\n");
        printf("\n\t\t\t5 - PARTICIPANTE CADASTRADO\n");
        printf("\n\t\t\t6 - SAIR\n");
        printf("\n\t\t\t-> ");
        scanf("%d",&op);
    }

    switch(op){
    case 1: submenu_cadastrar(); break;
    case 2: submenu_editar(); break;
    case 3: submenu_remover(); break;
    case 4: submenu_listar();break;
    case 5: submenu_ja_cadastrado();break;
    case 6: tela_inicial();
    default: menu();
    }
    printf("\n\t\t>pressione qualquer tecla para voltar ao inicio<");
    setbuf(stdin,NULL);
    getchar();
    menu();
}
void submenu_cadastrar(){
    Sleep(300);
    system("cls");
    int op=0;
    printf("\n\t\t\tCADASTRAMENTO ENCEC 2019\n");
    linhas();
    printf("\n\t\t\t1 - CADASTRAR CONGRESSISTA\n");
    printf("\n\t\t\t2 - CADASTRAR PALESTRANTE\n");
    printf("\n\t\t\t3 - CADASTRAR EVENTO\n");
    printf("\n\t\t\t4 - CADASTRAR ORGANIZADOR\n");
    printf("\n\t\t\t5 - VOLTAR AO GERENCIAMENTO\n");
    printf("\n\t\t\t-> ");
    scanf("%d",&op);
    while(op<=0||op>5){
        system("cls");
        printf("\n\t\t\tCADASTRAMENTO ENCEC 2019\n");
        linha();
        printf("\n\t\t\t1 - CADASTRAR CONGRESSISTA\n");
        printf("\n\t\t\t2 - CADASTRAR PALESTRANTE\n");
        printf("\n\t\t\t3 - CADASTRAR EVENTO\n");
        printf("\n\t\t\t4 - CADASTRAR ORGANIZADOR\n");
        printf("\n\t\t\t5 - VOLTAR AO GERENCIAMENTO\n");
        printf("\n\t\t\t-> ");
        scanf("%d",&op);
    }
    system("cls");
    printf("\n");
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
        cadastrar_organizador();
    }
    else{menu();}
}
void submenu_editar(){
    Sleep(300);
    system("cls");
    int op=0;
    printf("\n\t\t\t(EDITAR) ENCEC 2019\n");
    linhas();
    printf("\n\t\t\t1 - EDITAR CONGRESSISTA\n");
    printf("\n\t\t\t2 - EDITAR PALESTRANTE\n");
    printf("\n\t\t\t3 - EDITAR EVENTO\n");
    printf("\n\t\t\t4 - EDITAR ORGANIZADOR\n");
    printf("\n\t\t\t5 - VOLTAR AO GERENCIAMENTO\n");
    printf("\n\t\t\t-> ");
    scanf("%d",&op);
    while(op<=0||op>5){
        system("cls");
        printf("\n\t\t\t(EDITAR) ENCEC 2019\n");
        linha();
        printf("\n\t\t\t1 - EDITAR CONGRESSISTA\n");
        printf("\n\t\t\t2 - EDITAR PALESTRANTE\n");
        printf("\n\t\t\t3 - EDITAR EVENTO\n");
        printf("\n\t\t\t4 - EDITAR ORGANIZADOR\n");
        printf("\n\t\t\t5 - VOLTAR AO GERENCIAMENTO\n");
        printf("\n\t\t\t-> ");
        scanf("%d",&op);
    }
    system("cls");
    switch(op){
    case 1: editar_congressista();break;
    case 2: editar_palestrante();break;
    case 3: editar_evento();break;
    case 4: editar_organizador();break;
    default: menu();
    }
}
void submenu_remover(){
    Sleep(300);
    system("cls");
    int op=0;
    printf("\n\t\t\t(REMOVER) ENCEC 2019\n\n");
    linhas();
    printf("\n\t\t\t1 - REMOVER CONGRESSISTA\n");
    printf("\n\t\t\t2 - REMOVER PALESTRANTE\n");
    printf("\n\t\t\t3 - REMOVER EVENTO\n");
    printf("\n\t\t\t4 - REMOVER ORGANIZADOR\n");
    printf("\n\t\t\t5 - VOLTAR AO GERENCIAMENTO");
    printf("\n\t\t\t-> ");
    scanf("%d",&op);
    while(op<=0||op>5){
        system("cls");
        printf("\n\t\t\t(REMOVER) ENCEC 2019\n");
        linha();
        printf("\n\t\t\t1 - REMOVER CONGRESSISTA\n");
        printf("\n\t\t\t2 - REMOVER PALESTRANTE\n");
        printf("\n\t\t\t3 - REMOVER EVENTO\n");
        printf("\n\t\t\t4 - REMOVER ORGANIZADOR\n");
        printf("\n\t\t\t5 - VOLTAR AO GERENCIAMENTO\n");
        printf("\n\t\t\t-> ");
        scanf("%d",&op);
    }
    system("cls");
    switch(op){
    case 1: remover_congressista(cod_eventos1,cod_eventos2);break;
    case 2: remover_palestrante();break;
    case 3: remover_evento();break;
    case 4: remover_organizador();break;
    default: menu();
    }
}
void submenu_listar(){
    Sleep(300);
    system("cls");
    int op=0;
    printf("\n\t\t\t(LISTAR) ENCEC 2019\n");
    linhas();
    printf("\n\t\t\t1 - LISTAR CONGRESSISTAS\n");
    printf("\n\t\t\t2 - LISTAR PALESTRANTES\n");
    printf("\n\t\t\t3 - LISTAR EVENTOS\n");
    printf("\n\t\t\t4 - LISTAR ORGANIZADORES\n");
    printf("\n\t\t\t5 - LISTAR INSCRITOS EM EVENTOS\n");
    printf("\n\t\t\t6 - VOLTAR AO GERENCIAMENTO\n");
    printf("\n\t\t\t -> ");
    scanf("%d",&op);
    while(op<=0||op>6){
        system("cls");
        printf("\n\t\t\t(LISTAR) ENCEC 2019\n");
        linha();
        printf("\n\t\t\t1 - LISTAR CONGRESSISTAS\n");
        printf("\n\t\t\t2 - LISTAR PALESTRANTES\n");
        printf("\n\t\t\t3 - LISTAR EVENTOS\n");
        printf("\n\t\t\t4 - LISTAR ORGANIZADORES\n");

        printf("\n\t\t\t5 - LISTAR INSCRITOS EM EVENTOS\n");
        printf("\n\t\t\t6 - VOLTAR AO GERENCIAMENTO\n");
        printf("\n\t\t\t -> ");
        scanf("%d",&op);
    }

    system("cls");
    switch(op){
    case 1: listar_congressista();break;
    case 2: listar_palestrante();break;
    case 3: listar_evento();break;
    case 4: listar_organizador();break;
    case 5: listar_inscritos();break;
    default: menu();
    }
}

int submenu_ja_cadastrado(){
    int op;
    do{
    system("cls");
    cabecalho();
    printf("\n\t\t\t1 - ACESSAR CONGRESSISTA\n");
    printf("\n\t\t\t2 - ACESSAR PALESTRANTE\n");
    printf("\n\t\t\t3 - VOLTAR\n");

    printf("\n\t\t\t-> ");
    scanf("%d",&op);
    }while(op<1 || op>3);
    if(op==3)
        return 0;
    char nome[30];
    char cpf[15];
    system("cls");
    printf("\n\t\t\t>NOME: ");
    setbuf(stdin,NULL);
    gets(nome);
    printf("\n\t\t\t>CPF: ");
    setbuf(stdin,NULL);
    gets(cpf);
    if(op==1){

      if(!pesquisa_no_arquivo(ARQ_CONGRESSISTA,cpf)){
        printf("\n\t\t\tCONGRESSISTA NAO CADASTRADO.");
        return 0;
      }
      do{
        system("cls");
        cabecalho();
        printf("\n\t\t\t1 - CADASTRAR-SE EM EVENTO\n");
        printf("\n\t\t\t2 - VOLTAR\n");

        printf("\n\t\t\t-> ");
        scanf("%d",&op);
      }while(op<1 || op>3);
      system("cls");
      cabecalho();
      if(op==2){
        inscricao1(nome,cpf);
      }
      else{menu();}

    }else
     if(op==2){
      if(!pesquisa_no_arquivo(ARQ_PALESTRANTE,cpf)){
        printf("\n\t\tPALESTRANTE NAO CADASTRADO.");
        return 0;
      }
      do{
        system("cls");
        cabecalho();
        printf("\n\t\t\t1 - CADASTRAR EVENTO\n");
        printf("\n\t\t\t2 - VOLTAR\n");
        printf("\n\t\t\t-> ");
        scanf("%d",&op);
      }while(op<1 || op>3);
      system("cls");
      cabecalho();
      switch(op){
        case 1: cadastrar_evento2(nome,cpf);break;
        default: menu();
      }
    }else menu();
    submenu_ja_cadastrado();
    return 1;
}
int submenu_logar(){
    system("cls");
    char cpf[15];
    cabecalho();
    printf("\n\t\t\t- CPF: ");
    setbuf(stdin,NULL);
    gets(cpf);
    if(pesquisa_no_arquivo(ARQ_ORGANIZADORES,cpf)){
        menu();
        return 1;
    }
    else{
      printf("\n\t\t\tACESSO NEGADO!");
      printf("\n\t\t\t<pressione enter para voltar ao inicio>");
      setbuf(stdin,NULL);
      getchar();
      Sleep(200);
      return 0;
    }


}

int tela_inicial(){
    system("cls");
    int op=0;
    cabecalho();
    printf("\n\t\t\t1 - CADASTRAR ORGANIZADOR\n");
    printf("\n\t\t\t2 - LOGAR COMO ORGANIZADOR\n");
    printf("\n\t\t\t0 - SAIR\n");
    printf("\n\t\t\t-> ");
    scanf("%d",&op);
    while(op<0||op>2){
        system("cls");
        cabecalho();
        printf("\n\t\t\t1 - CADASTRAR ORGANIZADOR\n");
        printf("\n\t\t\t2 - LOGAR COMO ORGANIZADOR\n");
        printf("\n\t\t\t0 - SAIR\n");
        printf("\n\t\t\t-> ");
        scanf("%d",&op);
    }
    switch(op){
    case 1: cadastrar_organizador(); break;
    case 2: submenu_logar(); break;
    default: return 0;
    }
    return 0;
}

//coisinhas
void pontinhos(){
    putchar('\n');
    putchar('\t');
    putchar('\t');
    putchar('\t');
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
        Sleep(30);
        printf(".");
    }
}
}
//coisinhas
void linhas(){
    putchar('\n');
    putchar('\t');
    putchar('\t');

    for(int i = 0;i<5;i++){
        for(int j = 0;j<10;j++){
        Sleep(30);
        printf("_");
    }
}
        putchar('\n');
}
void tela_carregamento(){
    linhas();
    char texto[] = "ENCEC 2019";
    putchar('\n');
    putchar('\t');
    putchar('\t');
    putchar('\t');
    putchar('\t');

    for(int j = 0;j<strlen(texto);j++){
        Sleep(30);
        printf("%c",texto[j]);
    }
    linhas();
    Sleep(50);
}
int main(){
    system("mode con:cols=90 lines=34");
    system("color 1F");
    tela_carregamento();
    printf("\n\n\t\t>pressione enter para iniciar o gerenciamento<");
    setbuf(stdin,NULL);
    getchar();
    tela_inicial();
    return 0;
}
