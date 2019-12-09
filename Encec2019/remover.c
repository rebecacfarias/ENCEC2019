#include <stdio.h>
#include <string.h>
#include "arquivo.h"




void remover_arq_evento(char *cod){
    char evento[65];
    strcpy(evento,CAMINHO);
    strcat(evento,cod);
    strcat(evento,".txt");
    remove(evento);
}
int remover_de_eventos(char *cpf,char cod_eventos1[26][1],char cod_eventos2[26][1]){
    int i;
    int mudar_linha;
    char evento[65];
    if(!conta_linhas(ARQ_EVENTOS))
        return 0;
    for(i = 0;i<26;i++){
      if(checa_existencia_evento(cod_eventos1[i])){
        strcpy(evento,CAMINHO);
        strcat(evento,cod_eventos1[i]);
        strcat(evento,".txt");
        mudar_linha = linha_selecionada(evento,cpf);
        if(!busca_cpf(evento,cpf))
            continue;
        remover_dados(evento,mudar_linha-1,1);
      }
    }
    for(i = 0;i<26;i++){
      if(checa_existencia_evento(cod_eventos2[i])){
        strcpy(evento,CAMINHO);
        strcat(evento,cod_eventos2[i]);
        strcat(evento,".txt");
        mudar_linha = linha_selecionada(evento,cpf);
        if(!busca_cpf(evento,cpf))
            continue;
        remover_dados(evento,mudar_linha-1,1);
      }
    }
    return 1;

}
int remover_palestrante(){
    char cpf[15];
    char nome[30];
    int mudar_linha, linha_evento;
    printf("DIGITE O CPF DO PALESTRANTE: ");
    setbuf(stdin,NULL);
    gets(cpf);
    if(pesquisa_no_arquivo(ARQ_PALESTRANTE,cpf)){
        mudar_linha = linha_selecionada(ARQ_PALESTRANTE,cpf);
        remover_dados(ARQ_PALESTRANTE,mudar_linha-2,mudar_linha+LINHAS_PESSOA-1);
        if(busca_cpf_palest(ARQ_EVENTOS,nome)){
            linha_evento = linha_selecionada(ARQ_EVENTOS,cpf);
            remover_dados(ARQ_EVENTOS,linha_evento-2,linha_evento+4);
        }
        return 1;
    }else{
        printf("\nPALESTRANTE NAO CADASTRADO.\n");
        return 0;
    }
}
int remover_congressista(char cod_eventos1[26][1],char cod_eventos2[26][1]){
    char cpf[15];
    int mudar_linha;
    printf("DIGITE O CPF DO CONGRESSISTA: ");
    setbuf(stdin,NULL);
    gets(cpf);
    if(busca_cpf(ARQ_CONGRESSISTA,cpf)){
        mudar_linha = linha_selecionada(ARQ_CONGRESSISTA,cpf);
        remover_dados(ARQ_CONGRESSISTA,mudar_linha,LINHAS_PESSOA-1);

        remover_de_eventos(cpf,cod_eventos1,cod_eventos2);
        return 1;
    }else{
        printf("\nCONGRESSISTA NAO CADASTRADO.\n");
        return 0;
    }
}
int remover_evento(){
    char cod[1];
    char aux[30] = CODIGO_STR;
    int mudar_linha;
    printf("DIGITE O CODIGO DO EVENTO: ");
    setbuf(stdin,NULL);
    gets(cod);
    strcat(aux,cod);
    if(pesquisa_no_arquivo(ARQ_EVENTOS,aux)){
        mudar_linha = linha_selecionada(ARQ_EVENTOS,aux);
        remover_dados(ARQ_EVENTOS,mudar_linha,mudar_linha+LINHAS_EVENTO-1);
        remover_arq_evento(cod);
        return 1;
    }else{
        printf("\nEVENTO NAO CADASTRADO.\n");
        return 0;
    }
}
int remover_organizador(){
    char cpf[15];
    int mudar_linha;
    printf("DIGITE O CPF DO ORGANIZADOR: ");
    setbuf(stdin,NULL);
    gets(cpf);
    if(busca_cpf(ARQ_ORGANIZADORES,cpf)){
        mudar_linha = linha_selecionada(ARQ_ORGANIZADORES,cpf);
        remover_dados(ARQ_ORGANIZADORES,mudar_linha,mudar_linha+LINHAS_PESSOA-2);
        return 1;
    }else{
        printf("\nORGANIZADOR NAO CADASTRADO.\n");
        return 0;
    }
}
