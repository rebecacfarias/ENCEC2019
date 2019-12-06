#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arquivo.h"


void exibe_arquivo(char *arquivo){
    FILE *c;
    char ch;
    c = fopen(arquivo,"r");
    if(c==NULL)
        printf("erro");

    while (!feof(c))        		/* Enquanto não se chegar no final do arquivo */
    {
     printf("%c",ch); 		/*   Imprime o caracter na tela */
     ch = getc(c);    		/* Le um novo caracter no arquivo */
    }
    fclose(c);
}


int conta_linhas(char *arquivo){
    FILE *arqv;
    arqv = fopen(arquivo,"r");
    if(arqv == NULL)
        return 0;
    char caracter;
    int linhas=0;
    while (caracter!=EOF) {
      caracter = fgetc(arqv);
      if (caracter=='\n') {
             linhas++;
             }
    }
    fclose(arqv);
    return linhas;
}

int pesquisa_no_arquivo(char *arquivo,char *str){
    FILE *arqv;
    arqv = fopen(arquivo,"r");
    if(arqv == NULL)
        return 0;
    char caracter;
    int iguais=0,i=0,aux=0;
    while (caracter!=EOF) {
      caracter = fgetc(arqv);
      if (caracter==str[i]) {
             if(iguais == 0 && i == 0){
             iguais++;
             i++;
             }
             else{
                if(aux){
                    iguais = 0;
                    i = 0;
                    continue;
                }
                else{
                    iguais++;
                    i++;
                    if(iguais==strlen(str))
                        break;
                }
             }
             aux = 0;
            }
      else {
        aux++;
      }
    }
      fclose(arqv);
      if(iguais==strlen(str))
        return 1;
    return 0;

}

int linha_selecionada(char *arquivo, char *str){
    int linha = 1;
    FILE *arqv;
    arqv = fopen(arquivo,"r");
    if(arqv == NULL)
        return 0;
    char caracter;
    int iguais=0,i=0;
    while (caracter!=EOF) {
      caracter = fgetc(arqv);
      if (caracter==str[i]) {
             iguais++;
             i++;
             }
      if(caracter == '\n')
        linha++;
      if(iguais==strlen(str)){
        break;
      }
    }
   fclose(arqv);
   return linha;


}
/*
void exibir_dados_pessoas(char *arquivo,char *str){
    FILE *arqv;
    arqv = fopen(arquivo,"r");
    if(arqv==NULL){
        printf("erro");
    }
    int linha_atual = 0;
    int linha = linha_selecionada(arquivo,str);
    if(arqv != NULL){

    char texto[400], caracter;
    while(caracter!=EOF){
        caracter = fgetc(arqv);
        if(linha_atual >= linha && linha_atual<=linha+LINHAS_PESSOA){
            fputs(texto, arqv);
        }
        memset(texto, 0, sizeof(char) * 400);
        linha_atual++;
    }
    }

}

void exibir_dados_evento(char *str){
    FILE *arqv;
    char *arquivo = ARQ_EVENTOS;
    arqv = fopen(arquivo,"r");
    if(arqv==NULL){
        printf("erro");
    }
    int linha_atual = 0;
    int linha = linha_selecionada(arquivo,str);
    if(arqv != NULL){

    char texto[100], caracter;
    while(caracter!=EOF){
        caracter = fgetc(arqv);
        if(linha_atual >= linha && linha_atual<=linha+LINHAS_EVENTO){
            fgets(texto,100,arqv);
        }
        memset(texto, 0, sizeof(char) * 100);
        linha_atual++;
    }
    }

}
*/
//STACK OVERFLOW
void editar_dados_pessoas(char *arquivo,int linha,char *novo_dado){
    FILE *input = fopen(arquivo, "r"); //Arquivo de entrada.
    FILE *output = fopen(ARQ_TRANSFERIR, "w"); //Arquivo de saída.
    if(input==NULL || output ==NULL){
        printf("erro");
    }
    int linha_atual = 1;
    char caracter;
    int cont = 0;
    while(caracter!=EOF){
        caracter = fgetc(input);
        if(linha_atual != linha){
            fputc(caracter,output);
        }else{
            if(!cont)
             fprintf(output,"%s",novo_dado);
            cont++;
        }
        if(caracter == '\n')
            linha_atual++;
    }
    fclose(input);
    fclose(output);
    remove(arquivo);
    rename(ARQ_TRANSFERIR, arquivo);

}

int remover_dados(char *arquivo,int linha,int seguintes){
    FILE *input = fopen(arquivo, "r"); //Arquivo de entrada.
    FILE *output = fopen(ARQ_TRANSFERIR, "w"); //Arquivo de saída.
    if(input==NULL || output ==NULL){
        printf("erro");
        return 0;
    }
    int linha_atual = 1;
    char caracter;
    while(caracter!=EOF){
        caracter = fgetc(input);
        if(linha_atual<linha || linha_atual>linha+seguintes)
            fputc(caracter,output);
        if(caracter == '\n')
            linha_atual++;
    }
    fclose(input);
    fclose(output);
    remove(arquivo);
    rename(ARQ_TRANSFERIR, arquivo);

return 1;
}

int checa_existencia_evento(char *cod){
    char texto[15] = "CODIGO: ";
    strcat(texto,cod);
    return pesquisa_no_arquivo(ARQ_EVENTOS,texto);
}

int limpar_caracteres(char *arquivo){
    FILE *input = fopen(arquivo, "r"); //Arquivo de entrada.
    FILE *output = fopen(ARQ_TRANSFERIR, "w"); //Arquivo de saída.
    if(input==NULL || output ==NULL){
        printf("erro");
        return 0;
    }
    int linha_atual = 1;
    char caracter;
    while(caracter!=EOF){
        caracter = fgetc(input);
        if(caracter=='ÿ')
            fputc('-',output);
        else
            fputc(caracter,output);
        if(caracter == '\n')
            linha_atual++;
    }
    fclose(input);
    fclose(output);
    remove(arquivo);
    rename(ARQ_TRANSFERIR, arquivo);

return 1;
}
