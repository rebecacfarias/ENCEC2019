#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "data_hora.c"

#define LINHAS_PESSOA 6
#define LINHAS_EVENTO 6


typedef struct{
    char cpf[12];
    char nome[30];
    char email[30];
    int num_cadastro;
}congressista;

typedef struct {
    char nome[30];
    char codigo[5];
    char tipo[15];
    char palestrante[50];
    char local[15];
    char carga_horaria[5];
    char horario[5];
}evento;


void inscricao1(char *cong_nome,char *cpf);
void inscricao2(char *arquivo_evento,char *nome,char *cpf,int limite_evento);


void limpa_tela(){
      for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
        Sleep(100);
        printf(".");
    }
}
        system("cls");

}

void exibe_arquivo(char *nome){
        FILE *a;
        char texto_str[30];
        a = fopen(nome,"r");
        while(fgets(texto_str, 20, a) != NULL)
            printf("%s", texto_str);
        fclose(a);
}
char *concatenar(char *frase1,char *frase2){
    return strcat(frase1,frase2);
}

int gerar_numero_cadastro(){
    FILE *arq;
    arq = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\congressistas.txt","r");
    char caracter;
    int linhas=0;
    while (caracter!=EOF) {
      caracter = fgetc(arq);
      if (caracter=='\n') {
             linhas++;
             }
    }
    fclose(arq);
    return linhas/LINHAS_PESSOA;
}

int gerar_codigo_evento(){
    FILE *arq;
    arq = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt","r");
    char caracter;
    int linhas=0;
    while (caracter!=EOF) {
      caracter = fgetc(arq);
      if (caracter=='\n') {
             linhas++;
             }
    }
    fclose(arq);
    return linhas/LINHAS_EVENTO *100;
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

int pesquisa_no_arquivo(char *arquivo,char *string){
    FILE *arqv;
    arqv = fopen(arquivo,"r");
    if(arqv == NULL)
        return 0;
    char caracter;
    int iguais=0,i=0;
    while (caracter!=EOF) {
      caracter = fgetc(arqv);
      if (caracter==string[i]) {
             iguais++;
             i++;
             }
    }
      fclose(arqv);
      if(iguais==strlen(string))
        return 1;
    return 0;

}


//FUNCAO PRA RETORNAR O LIMITE DO EVENTO: recebe o codigo, abre arquivo, procura palavra palestra ou n sei q ou n sei q e retorna limite


void inscricao1(char *cong_nome,char *cpf){
    FILE *eventos;
    char texto_str[30];
    eventos = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt","r");
    while(fgets(texto_str, 20, eventos) != NULL)
        printf("%s", texto_str);
    fclose(eventos);
    char codigo[5];
    printf("\n DIGITE O CODIGO DO EVENTO:");
    setbuf(stdin,NULL);
    gets(codigo);
    strcat(codigo,".txt");
    char nome[100] = "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\";
    strcat(nome,codigo);
    inscricao2(nome,cong_nome,cpf,10);
}

void inscricao2(char *arquivo_evento,char *nome,char *cpf,int limite_evento){
        /*
        checa a situação do evento no qual querem se inscrever;
        criar arquivo para inscricao em eventos ou fazer no mesmo dos cong;
        */
        FILE *evento;
        int linhas = conta_linhas(arquivo_evento);
        if(linhas/4>limite_evento){
            printf("EVENTO LOTADO!");
        }
        else{
        evento = fopen(arquivo_evento,"a");
        if(arquivo_evento == NULL || conta_linhas(arquivo_evento)==0){
            printf("EVENTO NAO ENCONTRADO");
            inscricao1(nome,cpf);
        }
        fprintf(evento,"%s","NOME: ");
        fprintf(evento,"%s",nome);
        fprintf(evento,"%s","CPF: ");
        fprintf(evento,"%s",cpf);
        fprintf(evento,"%c",'\n');
        fclose(evento);
        }

}




void cadastrar_palestrante(){
}

int cadastrar_congressista(){

      FILE *c;

      for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
        Sleep(100);
        printf(".");
    }
}
        system("cls");

        congressista cong;
        cong.num_cadastro = gerar_numero_cadastro();
        if(cong.num_cadastro>300)
            printf(">>>> CONGRESSO LOTADO <<<<");
        else{
        c = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\congressistas.txt","w"); //POR ENQUANTO DEIXA W
        if(c==NULL)
            printf("erro");
        printf("NOME: ");
        setbuf(stdin,NULL);
        gets(cong.nome);
        printf("CPF: ");
        setbuf(stdin,NULL);
        scanf("%s",cong.cpf);
        printf("EMAIL: ");
        setbuf(stdin,NULL);
        gets(cong.email);

        strupr(cong.nome);
        strupr(cong.email);
        fprintf(c,"%s","NUMERO DE CADASTRO: ");
        fprintf(c,"%d",cong.num_cadastro);
        fprintf(c,"%c",'\n');
        fprintf(c,"%s","NOME: ");
        fprintf(c,"%s",cong.nome);
        fprintf(c,"%c",'\n');
        fprintf(c,"%s","CPF: ");
        fprintf(c,"%s",cong.cpf);
        if(pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\congressistas.txt",cong.cpf)){
            printf("ja cadastrado");
            return 0;
        }
        fprintf(c,"%c",'\n');
        fprintf(c,"%s","EMAIL: ");
        fprintf(c,"%s",cong.email);
        fprintf(c,"%c",'\n');
        fprintf(c,"%s","EVENTOS: ");
        fprintf(c,"%c",'\n');
        fprintf(c,"%c",'\n');

        fclose(c);
        char texto_str[30];
        c = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\congressistas.txt","r");
        while(fgets(texto_str, 20, c) != NULL)
            printf("%s", texto_str);
        fclose(c);

        printf("\nCADASTRO REALIZADO.\n");



        int linhas_eventos = conta_linhas("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt");
        if(linhas_eventos){
            char op;
            do{
            printf("DESEJA CADASTRAR-SE EM EVENTO ALGUM EVENTO?(S/N)");
            scanf(" %c",&op);
            op = toupper(op);
            }while(op!='S'&&op!='N');
            if(op=='S'){


        printf("\nCADASTRO REALIZADO.\n");
            }
        }else{
            printf("\nAINDA NAO HA EVENTOS PARA SE INSCREVER");
        }



        }
        return 1;
}

void cria_arquivo_evento(char *caminho,evento ev){
    FILE *ev1;
    ev1 = fopen(caminho,"w");
    if(ev1==NULL)
        printf("\n wtf");
    fprintf(ev1,"%s","TEMA: ");
    fprintf(ev1,"%s",ev.nome);
    fprintf(ev1,"%c",'\n');
    fprintf(ev1,"%s","PALESTRANTE: ");
    fprintf(ev1,"%s",ev.palestrante);
    fprintf(ev1,"%c",'\n');
    fprintf(ev1,"%s","LOCAL: ");
    fprintf(ev1,"%s",ev.local);
    fprintf(ev1,"%c",'\n');
    fprintf(ev1,"%s","HORA: ");
    fprintf(ev1,"%s",ev.horario);
    fprintf(ev1,"%c",'\n');
    fprintf(ev1,"%s","CARGA HORARIA: ");
    fprintf(ev1,"%s",ev.carga_horaria);
    fprintf(ev1,"%c",'\n');
    fprintf(ev1,"%s","CODIGO DO EVENTO: ");
    fprintf(ev1,"%s",ev.codigo);
    fprintf(ev1,"%c",'\n');
    fclose(ev1);


}
int cadastrar_evento(){
    FILE *e;
    limpa_tela();
    e = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt","w"); //POR ENQUANTO DEIXA W
    if(e==NULL)
        printf("erro");

    evento ev;

    char caminho[100] = "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\" ;
    printf("TIPO DO EVENTO(PALESTRA/GRUPO/CURSO/OFICINA): ");
    setbuf(stdin,NULL);
    gets(ev.tipo);
    strupr(ev.tipo);
    while(strcmp(ev.tipo, "PALESTRA")&&strcmp(ev.tipo, "GRUPO")&&strcmp(ev.tipo, "CURSO")&&strcmp(ev.tipo, "OFICINA")){
        printf("TIPO INVALIDO. DIGITE PALESTRA, GRUPO, CURSO OU OFICINA: ");
        setbuf(stdin,NULL);
        gets(ev.tipo);
        strupr(ev.tipo);
    }

    printf("CODIGO: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.codigo);
    strupr(ev.codigo);
    if(pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt",ev.codigo)){
        printf("EVENTO JA CADASTRADO.");
        return 0;
    }
    printf("TEMA: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.nome);
    strupr(ev.nome);
    printf("PALESTRANTE(s): ");
    setbuf(stdin,NULL);
    scanf("%s",ev.palestrante);
    strupr(ev.palestrante);
    printf("CARGA HORARIA: ");
    setbuf(stdin,NULL);
    gets(ev.carga_horaria);
    printf("LOCAL: ");
    setbuf(stdin,NULL);
    gets(ev.local);
    strupr(ev.local);
    printf("HORARIO: ");
    setbuf(stdin,NULL);
    gets(ev.horario);
    if(pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt",ev.horario) && pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt",ev.local)){
        printf("IMPOSSIVEL CADASTRAR. LOCAL OCUPADO NESSE HORARIO.");
        return 0;
    }

    fprintf(e,"%s","TEMA: ");
    fprintf(e,"%s",ev.nome);
    fprintf(e,"%c",'\n');
    fprintf(e,"%s","PALESTRANTE: ");
    fprintf(e,"%s",ev.palestrante);
    fprintf(e,"%c",'\n');
    fprintf(e,"%s","LOCAL: ");
    fprintf(e,"%s",ev.local);
    fprintf(e,"%c",'\n');
    fprintf(e,"%s","HORA: ");
    fprintf(e,"%s",ev.horario);
    fprintf(e,"%c",'\n');
    fprintf(e,"%s","CARGA HORARIA: ");
    fprintf(e,"%s",ev.carga_horaria);
    fprintf(e,"%c",'\n');
    fprintf(e,"%s","CODIGO DO EVENTO: ");
    fprintf(e,"%s",ev.codigo);
    fprintf(e,"%c",'\n');
    fclose(e);
    exibe_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt");

    char cod[10];
    strcpy(cod,ev.codigo);
    strcat(cod,".txt");
    strcat(caminho,cod);
    printf("\n%s",caminho);


    cria_arquivo_evento(caminho,ev);


    return 1;


}
void cadastrar_organizador(){
}
