#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "arquivo.h"



void listar_palestrante(){
    if(conta_linhas(ARQ_PALESTRANTE)){
    printf("PALESTRANTES INSCRITOS: \n\n");
    exibe_arquivo2(ARQ_PALESTRANTE);
    }else{
        printf("\t\t\tNAO HA PALESTRANTES CADASTRADOS.");
    }
}
void listar_congressista(){
    if(conta_linhas(ARQ_CONGRESSISTA)){
    printf("CONGRESSISTAS INSCRITOS: \n\n");
    exibe_arquivo2(ARQ_CONGRESSISTA);
    }else{
        printf("\t\t\tNAO HA CONGRESSISTAS CADASTRADOS.");
    }
}
void listar_evento(){
    if(conta_linhas(ARQ_EVENTOS)){
    printf("EVENTOS CADASTRADOS: \n\n");
    exibe_arquivo2(ARQ_EVENTOS);
    }else{
        printf("\t\t\tNAO HA EVENTOS CADASTRADOS.");
    }
}
void listar_organizador(){
    printf("ORGANIZADORES: \n\n");
    exibe_arquivo2(ARQ_ORGANIZADORES);

}

int listar_inscritos(){
    char cod[15];
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
    exibe_arquivo2(arquivo);
    return 1;

}


