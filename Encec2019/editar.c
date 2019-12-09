#include <stdio.h>
#include <string.h>
#include "arquivo.h"


#define AUD1 150
#define AUD2 100
#define AUD3 50
#define SALA1 50
#define SALA2 50
#define SALA3 30
#define LAB 20



int editar_palestrante(){
    char cpf[15];
    char email[30];
    char nome[30];
    char novo_dado[50];
    int op,mudar_linha;
    printf("DIGITE O CPF DO PALESTRANTE: ");
    setbuf(stdin,NULL);
    gets(cpf);
    if(pesquisa_no_arquivo(ARQ_PALESTRANTE,cpf)){
        int linha = linha_selecionada(ARQ_PALESTRANTE,cpf);

        do{
        printf("DESEJA MODIFICAR: 1. NOME  -  2. EMAIL ?(DIGITE 1 OU 2)");
        scanf("%d",&op);
        }while(op!=1 && op !=2);
        mudar_linha = linha+op;
        if(op==1){
            printf("NOME ATUALIZADO: ");
            setbuf(stdin,NULL);
            gets(nome);
            strupr(nome);
            strcpy(novo_dado,"NOME: ");
            strcat(novo_dado,nome);
            strcat(novo_dado,"\n");

        }
        else if(op==2){
            printf("EMAIL ATUALIZADO: ");
            setbuf(stdin,NULL);
            gets(email);
            strupr(email);
            strcpy(novo_dado,"EMAIL: ");
            strcat(novo_dado,email);
            strcat(novo_dado,"\n");
        }
        editar_dados_pessoas(ARQ_PALESTRANTE,mudar_linha-2,novo_dado);
        return 1;

    }
    else{
        printf("\nPALESTRANTE NAO REGISTRADO.");
        return 0;
    }
}

int editar_congressista(){
    char cpf[15];
    char email[30];
    char nome[30];
    char novo_dado[50];
    int op,mudar_linha;
    printf("DIGITE O CPF DO CONGRESSISTA: ");
    setbuf(stdin,NULL);
    gets(cpf);
    if(pesquisa_no_arquivo(ARQ_CONGRESSISTA,cpf)){
        int linha = linha_selecionada(ARQ_CONGRESSISTA,cpf);
        do{
        printf("DESEJA MODIFICAR: 1. NOME  -  2. EMAIL ?(DIGITE 1 OU 2)");
        scanf("%d",&op);
        }while(op!=1 && op !=2);
        mudar_linha = linha+op;
        if(op==1){
            printf("NOME ATUALIZADO: ");
            setbuf(stdin,NULL);
            gets(nome);
            strupr(nome);
            strcpy(novo_dado,"NOME: ");
            strcat(novo_dado,nome);
            strcat(novo_dado,"\n");

        }
        else if(op==2){
            printf("EMAIL ATUALIZADO: ");
            setbuf(stdin,NULL);
            gets(email);
            strupr(email);
            strcpy(novo_dado,"EMAIL: ");
            strcat(novo_dado,email);
            strcat(novo_dado,"\n");

        }
        editar_dados_pessoas(ARQ_CONGRESSISTA,mudar_linha,novo_dado);
        return 1;

    }
    else{
        printf("\nCONGRESSISTA NAO REGISTRADO.");
        return 0;
    }
}
int editar_evento(){
    char nome[30];
    char palestrante[50];
    char cod[1];
    char novo_dado[50];
    char caminho[] = "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\";
    int op,mudar_linha;
    printf("DIGITE O CODIGO DO EVENTO: ");
    setbuf(stdin,NULL);
    gets(cod);
    if(pesquisa_no_arquivo(ARQ_EVENTOS,cod)){
        strcat(caminho,cod);
        strcat(caminho,".txt");
        int linha = linha_selecionada(ARQ_EVENTOS,cod);
        ;
        do{
        printf("DESEJA MODIFICAR: 1. TEMA  -  2. PALESTRANTE - 3. DATA,HORA,LOCAL (DIGITE 1,2 ou 3)");
        scanf("%d",&op);
        }while(op<1 || op>3);
        mudar_linha = linha+op;
        if(op==1){
            printf("NOVO TEMA: ");
            setbuf(stdin,NULL);
            gets(nome);
            strupr(nome);
            strcpy(novo_dado,"TEMA: ");
            strcat(novo_dado,nome);
            strcat(novo_dado,"\n");
            editar_dados_pessoas(caminho,2,novo_dado);

        }
        else if(op==2){
            printf("NOVO PALESTRANTE: ");
            setbuf(stdin,NULL);
            gets(palestrante);
            strupr(palestrante);
            if(!pesquisa_no_arquivo(ARQ_PALESTRANTE,palestrante)){
                printf("\nPALESTRANTE NAO CADASTRADO\n");
                return 0;
            }
            strcpy(novo_dado,"PALESTRANTE: ");
            strcat(novo_dado,palestrante);
            strcat(novo_dado,"\n");
            editar_dados_pessoas(caminho,3,novo_dado);
        }
        else if(op==3){
            char local[15];
            char data[11];
            char horario[5];
            printf("DATA: ");
            setbuf(stdin,NULL);
            gets(data);
            printf("HORA: ");
            setbuf(stdin,NULL);
            gets(horario);
            printf("LOCAL: ");
            setbuf(stdin,NULL);
            gets(local);
            strupr(local);
            char teste[50] = "DATA: ";
            strcat(teste,data);
            strcat(teste,"\n");
            strcat(teste,"LOCAL: ");
            strcat(teste,local);
            strcat(teste,"\n");
            strcat(teste,"HORA: ");
            strcat(teste,horario);
            if(pesquisa_no_arquivo(ARQ_EVENTOS,teste)){
                printf("\nHORARIO INDISPONIVEL.\n");
                return 0;
            }
            strcpy(novo_dado,"DATA: ");
            strcat(novo_dado,data);
            strcat(novo_dado,"\n");
            editar_dados_pessoas(caminho,4,novo_dado);
            editar_dados_pessoas(ARQ_EVENTOS,mudar_linha,novo_dado);
            strcpy(novo_dado,"LOCAL: ");
            strcat(novo_dado,local);
            strcat(novo_dado,"\n");
            editar_dados_pessoas(caminho,5,novo_dado);
            mudar_linha++;
            editar_dados_pessoas(ARQ_EVENTOS,mudar_linha,novo_dado);
            strcpy(novo_dado,"HORA: ");
            strcat(novo_dado,horario);
            strcat(novo_dado,"\n");
            editar_dados_pessoas(caminho,6,novo_dado);
            mudar_linha++;
            editar_dados_pessoas(ARQ_EVENTOS,mudar_linha,novo_dado);

        }
        if(op!=3)
            editar_dados_pessoas(ARQ_EVENTOS,mudar_linha,novo_dado);
        return 1;

    }
    else{
        printf("\nEVENTO NAO REGISTRADO.");
        return 0;
    }

}
int editar_organizador(){
    char cpf[15];
    char email[30];
    char nome[30];
    char novo_dado[50];
    int op,mudar_linha;
    printf("DIGITE O CPF DO ORGANIZADOR: ");
    setbuf(stdin,NULL);
    gets(cpf);
    if(pesquisa_no_arquivo(ARQ_ORGANIZADORES,cpf)){
        int linha = linha_selecionada(ARQ_ORGANIZADORES,cpf);

        do{
        printf("DESEJA MODIFICAR: 1. NOME  -  2. EMAIL ?(DIGITE 1 OU 2)");
        scanf("%d",&op);
        }while(op!=1 && op !=2);
        mudar_linha = linha+op;
        if(op==1){
            printf("NOME ATUALIZADO: ");
            setbuf(stdin,NULL);
            gets(nome);
            strupr(nome);
            strcpy(novo_dado,"NOME: ");
            strcat(novo_dado,nome);
            strcat(novo_dado,"\n");

        }
        else if(op==2){
            printf("EMAIL ATUALIZADO: ");
            setbuf(stdin,NULL);
            gets(email);
            strupr(email);
            strcpy(novo_dado,"EMAIL: ");
            strcat(novo_dado,email);
            strcat(novo_dado,"\n");
        }
        editar_dados_pessoas(ARQ_ORGANIZADORES,mudar_linha,novo_dado);
        return 1;
    }
     else{
        printf("\nORGANIZADOR NAO REGISTRADO.");
        return 0;
    }

}
