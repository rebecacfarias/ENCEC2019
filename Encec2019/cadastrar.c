#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "arquivo.h"


#define AUD1 150
#define AUD2 100
#define AUD3 50
#define SALA1 50
#define SALA2 50
#define SALA3 30
#define LAB 20


typedef struct{
    char cpf[12];
    char nome[30];
    char email[30];
    int num_cadastro;
}palestrante;
typedef struct{
    char cpf[12];
    char nome[30];
    char email[30];
    int num_cadastro;
}congressista;

typedef struct{
    char nome[30];
    char cpf[15];
    char email[30];
}organizador;

typedef struct {
    char nome[30];
    char codigo[1];
    char tipo[15];
    char palestrante[50];
    char local[15];
    char carga_horaria[5];
    char horario[5];
    char data[11];
    char cpf_palestrante[15];
}evento;


void inscricao1(char *cong_nome,char *cpf);
void inscricao2(char *arquivo_evento,char *nome,char *cpf,char *tema,int limite_evento,char *codigo);


void limpa_tela(){
      for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
        Sleep(100);
        printf(".");
    }
}
        system("cls");

}


void insere_inscricoes_congs(char *nome,char*cpf,char *tema,char *tipo,char *codigo){
    char *caminho = ARQ_INSC_CONG;
    FILE *p;
    p = fopen(caminho,"a");

    fprintf(p,"%s","NOME: ");
    fprintf(p,"%s",nome);
    fprintf(p,"%c",'\n');
    fprintf(p,"%s","CPF: ");
    fprintf(p,"%s",cpf);
    fprintf(p,"%c",'\n');
    fprintf(p,"%s","TIPO DE EVENTO: ");
    fprintf(p,"%s",tipo);
    fprintf(p,"%c",'\n');

    fprintf(p,"%s","INSCRITO EM: ");
    fprintf(p,"%s",tema);
    fprintf(p,"%c",'\n');

    fprintf(p,"%s","COD: ");
    fprintf(p,"%s",codigo);
    fprintf(p,"%c",'\n');
    fprintf(p,"%c",'\n');
    fclose(p);

}

void insere_inscricoes_palest(evento ev){

    char *caminho = ARQ_INSC_PALEST;
    FILE *p;
    p = fopen(caminho,"a");

    fprintf(p,"%s","NOME: ");
    fprintf(p,"%s",ev.palestrante);
    fprintf(p,"%c",'\n');
    fprintf(p,"%s","CPF: ");
    fprintf(p,"%s",ev.cpf_palestrante);
    fprintf(p,"%c",'\n');
    fprintf(p,"%s","TIPO DE EVENTO: ");
    fprintf(p,"%s",ev.tipo);
    fprintf(p,"%c",'\n');
    fprintf(p,"%s","MINISTRANDO: ");
    fprintf(p,"%s",ev.nome);
    fprintf(p,"%c",'\n');
    fprintf(p,"%s","COD: ");
    fprintf(p,"%s",ev.codigo);
    fprintf(p,"%c",'\n');
    fprintf(p,"%c",'\n');
    fclose(p);

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
int gerar_numero_palestrante(){
    FILE *arq;
    arq = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\palestrantes.txt","r");
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

int checar_insc_palestrante(char *cpf, char *tipo){
        char busca_inscricao[50];
        int teste=0;
        strcpy(busca_inscricao,cpf);
        if(!strcmp(tipo,"CURSO") || !strcmp(tipo,"OFICINA")){
            strcat(busca_inscricao,"\nTIPO DE EVENTO: ");
            strcat(busca_inscricao,tipo);
            teste = pesquisa_no_arquivo(ARQ_INSC_PALEST,busca_inscricao);
        }
        return teste;
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

int capacidade_evento(char *arquivo){
    if(pesquisa_no_arquivo(arquivo,"AUDITORIO 1"))
        return AUD1;
    if(pesquisa_no_arquivo(arquivo,"AUDITORIO 2"))
        return AUD2;
    if(pesquisa_no_arquivo(arquivo,"AUDITORIO 3"))
        return AUD3;
    if(pesquisa_no_arquivo(arquivo,"SALA 1"))
        return SALA1;
    if(pesquisa_no_arquivo(arquivo,"SALA 2"))
        return SALA2;
    if(pesquisa_no_arquivo(arquivo,"SALA 3"))
        return SALA3;
    if(pesquisa_no_arquivo(arquivo,"LABORATORIO 1") || pesquisa_no_arquivo(arquivo,"LABORATORIO 2") )
        return LAB;
    return 0;
}


void inscricao1(char *cong_nome,char *cpf){
    FILE *eventos;
    char texto_str[30];
    eventos = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt","r");
    while(fgets(texto_str, 20, eventos) != NULL)
        printf("%s", texto_str);
    fclose(eventos);
    char codigo[5],cod[5];
    char tema[30];
    printf("\nTEMA DO EVENTO:");
    setbuf(stdin,NULL);
    gets(tema);
    printf("\nCODIGO DO EVENTO:");
    setbuf(stdin,NULL);
    gets(cod);
    strcpy(codigo,cod);
    strcat(codigo,".txt");
    char nome[100] = "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\";
    strcat(nome,codigo);
    if(pesquisa_no_arquivo(nome,cpf)){
        printf("\nCONGRESSISTA JA CADASTRADO NESSE EVENTO!");
    }else{
    int limite_evento = capacidade_evento(nome);
    inscricao2(nome,cong_nome,cpf,tema,limite_evento,cod);
    }
}

void inscricao2(char *arquivo_evento,char *nome,char *cpf,char *tema,int limite_evento,char *cod){
        /*
        checa a situa��o do evento no qual querem se inscrever;
        criar arquivo para inscricao em eventos ou fazer no mesmo dos cong;
        */
        FILE *evento;
        int linhas = conta_linhas(arquivo_evento);
        //formula pra contar quantos inscritos tem no evento atraves do numero de linhas
        if(linhas/2-7>limite_evento){
            printf("EVENTO LOTADO!");
        }
        else{
        char busca_inscricao[50];
        int teste=0;
        strcpy(busca_inscricao,cpf);
        char tipo[10];
        if(pesquisa_no_arquivo(arquivo_evento,"CURSO"))
            strcpy(tipo,"CURSO");
        else if(pesquisa_no_arquivo(arquivo_evento,"OFICINA"))
            strcpy(tipo,"OFICINA");

        if(!strcmp(tipo,"CURSO") || !strcmp(tipo,"OFICINA")){
            strcat(busca_inscricao,"\nTIPO DE EVENTO: ");
            strcat(busca_inscricao,tipo);
            teste = pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\inscricoescong.txt",busca_inscricao);
        }

        if(teste){
            printf("\n JA ESTA INSCRITO EM UMA OFICINA/CURSO. \n");
        }
        else{
        evento = fopen(arquivo_evento,"a");
        if(arquivo_evento == NULL || conta_linhas(arquivo_evento)==0){
            printf("EVENTO NAO ENCONTRADO");
            inscricao1(nome,cpf);
        }
        insere_inscricoes_congs(nome,cpf,tema,tipo,cod);
        fprintf(evento,"%s","NOME: ");
        fprintf(evento,"%s",nome);
        fprintf(evento,"%s","CPF: ");
        fprintf(evento,"%s",cpf);
        fprintf(evento,"%c",'\n');
        fclose(evento);
        }
    }

}




int cadastrar_palestrante(){
      FILE *p;

      for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
        Sleep(100);
        printf(".");
    }
}
        system("cls");

        palestrante palest;
        palest.num_cadastro = gerar_numero_palestrante();
        int num = gerar_numero_cadastro();
        if(num+palest.num_cadastro>300)
            printf(">>>> CONGRESSO LOTADO <<<<");
        else{
        p = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\palestrantes.txt","a"); //POR ENQUANTO DEIXA W
        if(p==NULL)
            printf("erro");
        printf("NOME: ");
        setbuf(stdin,NULL);
        gets(palest.nome);
        printf("CPF: ");
        setbuf(stdin,NULL);
        scanf("%s",palest.cpf);
        printf("EMAIL: ");
        setbuf(stdin,NULL);
        gets(palest.email);

        strupr(palest.nome);
        strupr(palest.email);
        fprintf(p,"%s","NUMERO DE CADASTRO: ");
        fprintf(p,"%d",palest.num_cadastro);
        fprintf(p,"%c",'\n');
        fprintf(p,"%s","NOME: ");
        fprintf(p,"%s",palest.nome);
        fprintf(p,"%c",'\n');
        fprintf(p,"%s","CPF: ");
        fprintf(p,"%s",palest.cpf);
        if(pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\palestrantes.txt",palest.cpf)){
            printf("\nja cadastrado\n");
            return 0;
        }
        fprintf(p,"%c",'\n');
        fprintf(p,"%s","EMAIL: ");
        fprintf(p,"%s",palest.email);
        fprintf(p,"%c",'\n');

        fclose(p);
        char texto_str[30];
        p = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\palestrantes.txt","r");
        while(fgets(texto_str, 20, p) != NULL)
            printf("%s", texto_str);
        fclose(p);

        printf("\nCADASTRO REALIZADO.\n");
        }
        return 1;

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
        c = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\congressistas.txt","a"); //POR ENQUANTO DEIXA W
        if(c==NULL)
            printf("erro");
        printf("NOME: ");
        setbuf(stdin,NULL);
        gets(cong.nome);
        printf("CPF: ");
        setbuf(stdin,NULL);
        scanf("%s",cong.cpf);
        if(pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\congressistas.txt",cong.cpf)){
            printf("ja cadastrado");
            return 0;
        }
        printf("EMAIL: ");
        setbuf(stdin,NULL);
        gets(cong.email);

        strupr(cong.nome);
        strupr(cong.email);
        fprintf(c,"%s","CPF: ");
        fprintf(c,"%s",cong.cpf);
        fprintf(c,"%c",'\n');
        fprintf(c,"%s","NOME: ");
        fprintf(c,"%s",cong.nome);
        fprintf(c,"%c",'\n');
        fprintf(c,"%s","EMAIL: ");
        fprintf(c,"%s",cong.email);
        fprintf(c,"%c",'\n');
        fprintf(c,"%s","NUMERO DE CADASTRO: ");
        fprintf(c,"%d",cong.num_cadastro);
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
                inscricao1(cong.nome,cong.cpf);
            }
        }else{
            printf("\nAINDA NAO HA EVENTOS PARA SE INSCREVER");
        }



        }
        return 1;
}

void cria_arquivo_evento(char *caminho,evento ev,char **membros, char **cpfs,int num){
    FILE *ev1;
    ev1 = fopen(caminho,"w");
    if(ev1==NULL)
        printf("\n wtf");
    fprintf(ev1,"%s","CODIGO DO EVENTO: ");
    fprintf(ev1,"%s",ev.codigo);
    fprintf(ev1,"%c",'\n');
    fprintf(ev1,"%s","TEMA: ");
    fprintf(ev1,"%s",ev.nome);
    fprintf(ev1,"%c",'\n');
    if(!strcmp(ev.tipo,"GRUPO")){
         fprintf(ev1,"%s","PALESTRANTES: ");
         for(int i = 0;i<num;i++){
            fprintf(ev1,"%s","PALESTRANTES: ");
            fprintf(ev1,"%s",membros[i]);
            fprintf(ev1,"%c",'(');
            fprintf(ev1,"%s",cpfs[i]);
            fprintf(ev1,"%c",')');
            fprintf(ev1,"%s"," - ");
         }
    }else{
    fprintf(ev1,"%s","PALESTRANTE: ");
    fprintf(ev1,"%s",ev.palestrante);
    fprintf(ev1,"%c",'(');
    fprintf(ev1,"%s",ev.cpf_palestrante);
    fprintf(ev1,"%c",')');
    }
    fprintf(ev1,"%c",'\n');
    fprintf(ev1,"%s","DATA: ");
    fprintf(ev1,"%s",ev.data);
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
    fprintf(ev1,"%s","INSCRITOS: ");
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
    int num;
    char **membros;
    char **cpfs;

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
    do{
    printf("CODIGO(A-Z ou a-z): ");
    setbuf(stdin,NULL);
    scanf("%s",ev.codigo);
    }while(((int)ev.codigo[0]<(int)'A' || (int)ev.codigo[0]>(int)'Z') && ((int)ev.codigo[0]<(int)'a' || (int)ev.codigo[0]>(int)'z'));

    if(pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt",ev.codigo)){
        printf("EVENTO JA CADASTRADO.");
        return 0;
    }
    printf("TEMA: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.nome);
    strupr(ev.nome);
    if(!strcmp(ev.tipo,"GRUPO")){
       do{
       printf("NUMERO DE MEMBROS DA MESA(ATE 5): ");
       scanf("%d",&num);
       }while(num<1||num>5);
       membros = (char**)malloc(num*sizeof(char*));
       cpfs = (char**)malloc(num*sizeof(char*));
       for(int i =0;i<num;i++){
         membros[i]=(char*)malloc(sizeof(char)*30);
         cpfs[i]=(char*)malloc(sizeof(char)*15);
       }
       for(int i = 0;i<num;i++){
         printf("PALESTRANTE %d: ",i);
         setbuf(stdin,NULL);
         gets(membros[i]);
         printf("CPF %d: ",i);
         setbuf(stdin,NULL);
         gets(cpfs[i]);
         if(!(pesquisa_no_arquivo(ARQ_PALESTRANTE,cpfs[i]))){
            printf("PALESTRANTE NAO CADASTRADO.");
            return 0;
         }
       }

    }else{
    printf("PALESTRANTE: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.palestrante);
    strupr(ev.palestrante);
    printf("CPF DO PALESTRANTE: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.cpf_palestrante);
    if(!(pesquisa_no_arquivo(ARQ_PALESTRANTE,ev.cpf_palestrante))){
        printf("PALESTRANTE NAO CADASTRADO.");
        return 0;
    }
    insere_inscricoes_palest(ev);
    }
    printf("CARGA HORARIA: ");
    setbuf(stdin,NULL);
    gets(ev.carga_horaria);
    printf("---------\n");
    printf("-> AUDITORIO 1\n");
    printf("-> AUDITORIO 2\n");
    printf("-> AUDITORIO 3\n");
    printf("-> SALA 1\n");
    printf("-> SALA 2\n");
    printf("-> SALA 3\n");
    printf("-> LABORATORIO 1\n");
    printf("-> LABORATORIO 2\n");
    printf("LOCAL: ");
    setbuf(stdin,NULL);
    gets(ev.local);
    strupr(ev.local);
    while(strcmp(ev.local, "AUDITORIO 1")&&strcmp(ev.local, "AUDITORIO 2")&&strcmp(ev.local, "AUDITORIO 3")&&strcmp(ev.local, "SALA 1")&&strcmp(ev.local, "SALA 2")&&strcmp(ev.local, "SALA 3")&&strcmp(ev.local, "LABORATORIO 1")&&strcmp(ev.local, "LABORATORIO 2")){
        printf("LOCAL INVALIDO. DIGITE UM DOS LOCAIS LISTADOS: ");
        setbuf(stdin,NULL);
        gets(ev.local);
        strupr(ev.local);
    }
    printf("DATA: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.data);
    printf("HORARIO: ");
    setbuf(stdin,NULL);
    gets(ev.horario);
    char teste[50] = "DATA: ";
    strcat(teste,ev.data);
    strcat(teste,"\n");
    strcat(teste,"LOCAL: ");
    strcat(teste,ev.local);
    strcat(teste,"\n");
    strcat(teste,"HORA: ");
    strcat(teste,ev.horario);
//VE SE FUNCIONA
    if(pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt",teste)){
        printf("IMPOSSIVEL CADASTRAR. LOCAL OCUPADO NESSE HORARIO.");
        return 0;
    }

    fprintf(e,"%s","CODIGO DO EVENTO: ");
    fprintf(e,"%s",ev.codigo);
    fprintf(e,"%c",'\n');
    fprintf(e,"%s","TEMA: ");
    fprintf(e,"%s",ev.nome);
    fprintf(e,"%c",'\n');
    if(!strcmp(ev.tipo,"GRUPO")){
         fprintf(e,"%s","PALESTRANTES: ");
         for(int i = 0;i<num;i++){
            fprintf(e,"%s","PALESTRANTES: ");
            fprintf(e,"%s",membros[i]);
            fprintf(e,"%c",'(');
            fprintf(e,"%s",cpfs[i]);
            fprintf(e,"%c",')');
            fprintf(e,"%s"," - ");
         }
    }else{
    fprintf(e,"%s","PALESTRANTE: ");
    fprintf(e,"%s",ev.palestrante);
    fprintf(e,"%c",'(');
    fprintf(e,"%s",ev.cpf_palestrante);
    fprintf(e,"%c",')');
    }
    if(checar_insc_palestrante(ev.cpf_palestrante,ev.tipo)){
        printf("PALESTRANTE JA MINISTRA UM CURSO/OFICINA.");
        return 0;
    }
    fprintf(e,"%c",'\n');
    fprintf(e,"%s","DATA: ");
    fprintf(e,"%s",ev.data);
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
    fprintf(e,"%c",'\n');
    fclose(e);
    exibe_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt");

    char cod[10];
    strcpy(cod,ev.codigo);
    strcat(cod,".txt");
    strcat(caminho,cod);
    printf("\n%s",caminho);


    cria_arquivo_evento(caminho,ev,membros,cpfs,num);


    return 1;


}
int cadastrar_organizador(){
      FILE *o;

      for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
        Sleep(100);
        printf(".");
    }
}
        system("cls");

        organizador org;

        o = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\organizadores.txt","w"); //POR ENQUANTO DEIXA W
        if(o==NULL)
            printf("erro");
        printf("NOME: ");
        setbuf(stdin,NULL);
        gets(org.nome);
        printf("CPF: ");
        setbuf(stdin,NULL);
        scanf("%s",org.cpf);
        printf("EMAIL: ");
        setbuf(stdin,NULL);
        gets(org.email);

        strupr(org.nome);
        strupr(org.email);
        fprintf(o,"%s","NOME: ");
        fprintf(o,"%s",org.nome);
        fprintf(o,"%c",'\n');
        fprintf(o,"%s","CPF: ");
        fprintf(o,"%s",org.cpf);
        if(pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\organizadores.txt",org.cpf)){
            printf("\nja cadastrado\n");
            return 0;
        }
        fprintf(o,"%c",'\n');
        fprintf(o,"%s","EMAIL: ");
        fprintf(o,"%s",org.email);
        fprintf(o,"%c",'\n');

        fclose(o);
        char texto_str[30];
        o = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\organizadores.txt","r");
        while(fgets(texto_str, 20, o) != NULL)
            printf("%s", texto_str);
        fclose(o);

        printf("\nCADASTRO REALIZADO.\n");

        return 1;

}


int cadastrar_evento2(char *nome, char*cpf){
    FILE *e;
    limpa_tela();
    e = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt","w"); //POR ENQUANTO DEIXA W
    if(e==NULL)
        printf("erro");

    evento ev;
    int num;
    char **membros;
    char **cpfs;

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
    if(checar_insc_palestrante(cpf,ev.tipo)){
        printf("PALESTRANTE JA MINISTRA UM CURSO/OFICINA.");
        return 0;
    }
    do{
    printf("CODIGO(A-Z ou a-z): ");
    setbuf(stdin,NULL);
    scanf("%s",ev.codigo);
    }while(((int)ev.codigo[0]<(int)'A' || (int)ev.codigo[0]>(int)'Z') && ((int)ev.codigo[0]<(int)'a' || (int)ev.codigo[0]>(int)'z'));

    if(pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt",ev.codigo)){
        printf("EVENTO JA CADASTRADO.");
        return 0;
    }
    printf("TEMA: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.nome);
    strupr(ev.nome);
    if(!strcmp(ev.tipo,"GRUPO")){
       do{
       printf("NUMERO DE MEMBROS DA MESA(ATE 5): ");
       scanf("%d",&num);
       }while(num<1||num>5);
       membros = (char**)malloc(num*sizeof(char*));
       cpfs = (char**)malloc(num*sizeof(char*));
       for(int i =0;i<num;i++){
         membros[i]=(char*)malloc(sizeof(char)*30);
         cpfs[i]=(char*)malloc(sizeof(char)*15);
       }
       for(int i = 0;i<num;i++){
         printf("PALESTRANTE %d: ",i);
         setbuf(stdin,NULL);
         gets(membros[i]);
         printf("CPF %d: ",i);
         setbuf(stdin,NULL);
         gets(cpfs[i]);
         if(!(pesquisa_no_arquivo(ARQ_PALESTRANTE,cpfs[i]))){
            printf("PALESTRANTE NAO CADASTRADO.");
            return 0;
         }
       }

    }else{
    strcpy(ev.palestrante,nome);
    strcpy(ev.cpf_palestrante,cpf);
    insere_inscricoes_palest(ev);
    }
    printf("CARGA HORARIA: ");
    setbuf(stdin,NULL);
    gets(ev.carga_horaria);
    printf("---------\n");
    printf("-> AUDITORIO 1\n");
    printf("-> AUDITORIO 2\n");
    printf("-> AUDITORIO 3\n");
    printf("-> SALA 1\n");
    printf("-> SALA 2\n");
    printf("-> SALA 3\n");
    printf("-> LABORATORIO 1\n");
    printf("-> LABORATORIO 2\n");
    printf("LOCAL: ");
    setbuf(stdin,NULL);
    gets(ev.local);
    strupr(ev.local);
    while(strcmp(ev.local, "AUDITORIO 1")&&strcmp(ev.local, "AUDITORIO 2")&&strcmp(ev.local, "AUDITORIO 3")&&strcmp(ev.local, "SALA 1")&&strcmp(ev.local, "SALA 2")&&strcmp(ev.local, "SALA 3")&&strcmp(ev.local, "LABORATORIO 1")&&strcmp(ev.local, "LABORATORIO 2")){
        printf("LOCAL INVALIDO. DIGITE UM DOS LOCAIS LISTADOS: ");
        setbuf(stdin,NULL);
        gets(ev.local);
        strupr(ev.local);
    }
    printf("DATA: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.data);
    printf("HORARIO: ");
    setbuf(stdin,NULL);
    gets(ev.horario);
    char teste[50] = "DATA: ";
    strcat(teste,ev.data);
    strcat(teste,"\n");
    strcat(teste,"LOCAL: ");
    strcat(teste,ev.local);
    strcat(teste,"\n");
    strcat(teste,"HORA: ");
    strcat(teste,ev.horario);
//VE SE FUNCIONA
    if(pesquisa_no_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt",teste)){
        printf("IMPOSSIVEL CADASTRAR. LOCAL OCUPADO NESSE HORARIO.");
        return 0;
    }

    fprintf(e,"%s","CODIGO DO EVENTO: ");
    fprintf(e,"%s",ev.codigo);
    fprintf(e,"%c",'\n');
    fprintf(e,"%s","TEMA: ");
    fprintf(e,"%s",ev.nome);
    fprintf(e,"%c",'\n');
    if(!strcmp(ev.tipo,"GRUPO")){
         fprintf(e,"%s","PALESTRANTES: ");
         for(int i = 0;i<num;i++){
            fprintf(e,"%s","PALESTRANTES: ");
            fprintf(e,"%s",membros[i]);
            fprintf(e,"%c",'(');
            fprintf(e,"%s",cpfs[i]);
            fprintf(e,"%c",')');
            fprintf(e,"%s"," - ");
         }
    }else{
    fprintf(e,"%s","PALESTRANTE: ");
    fprintf(e,"%s",ev.palestrante);
    fprintf(e,"%c",'(');
    fprintf(e,"%s",ev.cpf_palestrante);
    fprintf(e,"%c",')');
    }
    fprintf(e,"%c",'\n');
    fprintf(e,"%s","DATA: ");
    fprintf(e,"%s",ev.data);
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
    fprintf(e,"%c",'\n');
    fclose(e);
    exibe_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt");

    char cod[10];
    strcpy(cod,ev.codigo);
    strcat(cod,".txt");
    strcat(caminho,cod);
    printf("\n%s",caminho);


    cria_arquivo_evento(caminho,ev,membros,cpfs,num);


    return 1;


}
