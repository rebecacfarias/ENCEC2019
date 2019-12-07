#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "arquivo.h"



void listar_palestrante(){
    printf("PALESTRANTES INSCRITOS: \n");
    exibe_arquivo(ARQ_PALESTRANTE);
}
void listar_congressista(){
    printf("CONGRESSISTAS INSCRITOS: \n");
    exibe_arquivo(ARQ_CONGRESSISTA);
}
void listar_evento(){
    printf("EVENTOS CADASTRADOS: \n");
    exibe_arquivo(ARQ_EVENTOS);
}
void listar_organizador(){
    printf("ORGANIZADORES: \n");
    exibe_arquivo(ARQ_ORGANIZADORES);
}
int listar_eventos(char *cpf,char cod_eventos1[26][1],char cod_eventos2[26][1]){
    int i;
    char evento[65];
    if(!conta_linhas(ARQ_EVENTOS))
        return 0;
    for(i = 0;i<26;i++){
      if(checa_existencia_evento(cod_eventos1[i])){
        strcpy(evento,CAMINHO);
        strcat(evento,cod_eventos1[i]);
        strcat(evento,".txt");
        if(!pesquisa_no_arquivo(evento,cpf))
            continue;
        char aux[12] = CODIGO_STR;
        strcat(aux,cod_eventos1[i]);
        exibir_dados_evento(aux);
      }
    }
    for(i = 0;i<26;i++){
      if(checa_existencia_evento(cod_eventos2[i])){
        strcpy(evento,CAMINHO);
        strcat(evento,cod_eventos2[i]);
        strcat(evento,".txt");
        if(!pesquisa_no_arquivo(evento,cpf))
            continue;
        char aux[12] = CODIGO_STR;
        strcat(aux,cod_eventos2[i]);
        exibir_dados_evento(aux);
      }
    }
    return 1;

}
int listar_palestras(char *cpf,char cod_eventos1[26][1],char cod_eventos2[26][1]){
    int i;
    char evento[65];

    if(!conta_linhas(ARQ_EVENTOS))
        return 0;
        /*
    printf("CPF DO PALESTRANTE: ");
    setbuf(stdin,NULL);
    gets(cpf);
    */
    for(i = 0;i<26;i++){
      if(checa_existencia_evento(cod_eventos1[i])){
        strcpy(evento,CAMINHO);
        strcat(evento,cod_eventos1[i]);
        strcat(evento,".txt");
        if(!pesquisa_no_arquivo(evento,cpf))
            continue;
        char aux[12] = CODIGO_STR;
        strcat(aux,cod_eventos1[i]);
        exibir_dados_evento(aux);
      }
    }
    for(i = 0;i<26;i++){
      if(checa_existencia_evento(cod_eventos2[i])){
        strcpy(evento,CAMINHO);
        strcat(evento,cod_eventos2[i]);
        strcat(evento,".txt");
        if(!pesquisa_no_arquivo(evento,cpf))
            continue;
        char aux[12] = CODIGO_STR;
        strcat(aux,cod_eventos2[i]);
        exibir_dados_evento(aux);
      }
    }
    return 1;
}
void listar_historico_insc_congs(){
    printf("HISTORICO DE INSCRICOES DE CONGRESSISTAS\n");
    exibe_arquivo(ARQ_INSC_CONG);
}

void listar_historico_insc_palest(){
   printf("HISTORICO DE INSCRICOES DE PALESTRANTES\n");
   exibe_arquivo(ARQ_INSC_PALEST);
}

int listar_inscritos(){
    char cod[1];
    char arquivo[80];
    printf("CODIGO DO EVENTO: ");
    setbuf(stdin,NULL);
    gets(cod);
    if(!checa_existencia_evento(cod)){
        printf("\nEVENTO NAO CADASTRADO\n");
        return 0;
    }
    strcpy(arquivo,CAMINHO);
    strcat(arquivo,cod);
    strcat(arquivo,".txt");
    exibe_arquivo(arquivo);
    return 1;

}

int listar_inscricoes(){
    int op;
    do{
    system("cls");
    printf("1 - CONGRESSISTAS INSCRITOS \n");
    printf("2 - PALESTRANTES INSCRITOS \n");
    printf("3 - VOLTAR\n");
    scanf("%d",&op);
    }while(op<1 ||op>3);
    switch(op){
        case 1: listar_historico_insc_congs();break;
        case 2: listar_historico_insc_palest();break;
        case 3: return 0;
    }
    return 1;
}
