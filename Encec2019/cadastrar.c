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
    char instituicao[30];
    int num_cadastro;
}palestrante;
typedef struct{
    char cpf[12];
    char nome[30];
    char email[30];
    char instituicao[30];
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
int inscricao2(char *arquivo_evento,char *nome,char *cpf,char *tema,int limite_evento,char *codigo);


void limpa_tela(){
        putchar('\t');
        putchar('\t');
      for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
        Sleep(30);
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




int gerar_numero_cadastro(){
    FILE *arq;
    arq = fopen(ARQ_CONGRESSISTA,"r");
    char caracter;
    int linhas=0;
    while (caracter!=EOF) {
      caracter = fgetc(arq);
      if (caracter=='\n') {
             linhas++;
             }
    }
    fclose(arq);
    return (linhas/LINHAS_PESSOA)+1;
}
int gerar_numero_palestrante(){
    FILE *arq;
    arq = fopen(ARQ_PALESTRANTE,"r");
    char caracter;
    int linhas=0;
    while (caracter!=EOF) {
      caracter = fgetc(arq);
      if (caracter=='\n') {
             linhas++;
             }
    }
    fclose(arq);
    return (linhas/LINHAS_PESSOA)+1;
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


void inscricao1(char cong_nome[30],char cpf[15]){
    FILE *eventos;
    char texto_str[30];
    eventos = fopen(ARQ_EVENTOS,"r");
    while(fgets(texto_str, 20, eventos) != NULL)
        printf("%s", texto_str);
    fclose(eventos);
    char cod[15];
    char tema[30];
    printf("\n\t\t\tTEMA DO EVENTO: ");
    setbuf(stdin,NULL);
    gets(tema);
    printf("\n\t\t\tCODIGO DO EVENTO: ");
    setbuf(stdin,NULL);
    gets(cod);


    char nome[100] = CAMINHO;
    strcat(nome,cod);
    strcat(nome,".txt");
    if(!checa_existencia_evento(cod)){
        printf("\n\t\t\tEVENTO NAO CADASTRADO.");
    }
    else{
    if(pesquisa_no_arquivo(nome,cpf)){
        printf("\n\t\t\tCONGRESSISTA JA CADASTRADO NESSE EVENTO!");
        printf("\n\t\t\t>pressione qualquer tecla para voltar<");
        setbuf(stdin,NULL);
        getchar();
    }else{
    int limite_evento = capacidade_evento(nome);
    inscricao2(nome,cong_nome,cpf,tema,limite_evento,cod);
    }
    }
}

int inscricao2(char *arquivo_evento,char nome[30],char cpf[15],char *tema,int limite_evento,char *cod){
        /*
        checa a situação do evento no qual querem se inscrever;
        criar arquivo para inscricao em eventos ou fazer no mesmo dos cong;
        */
        FILE *evento;
        int linhas = conta_linhas(arquivo_evento);
        //formula pra contar quantos inscritos tem no evento atraves do numero de linhas
        if(linhas/2-8>limite_evento){
            printf("\n\t\t\tEVENTO LOTADO!");
            printf("\n\t\t\t>pressione qualquer tecla para voltar<");
            setbuf(stdin,NULL);
            getchar();
            return 0;
        }
        char busca_inscricao[100];
        strcpy(busca_inscricao,cpf);
        char tipo[10];
        if(pesquisa_no_arquivo(arquivo_evento,"CURSO"))
            strcpy(tipo,"CURSO");
        else if(pesquisa_no_arquivo(arquivo_evento,"OFICINA"))
            strcpy(tipo,"OFICINA");

        if(!strcmp(tipo,"CURSO") || !strcmp(tipo,"OFICINA")){
            strcat(busca_inscricao,"\nTIPO DE EVENTO: ");
            strcat(busca_inscricao,tipo);
            if(pesquisa_no_arquivo(ARQ_INSC_CONG,busca_inscricao)){
                printf("\n\t\t\t JA ESTA INSCRITO EM UMA OFICINA/CURSO. \n");
                printf("\n\t\t\t>pressione qualquer tecla para voltar<");
                setbuf(stdin,NULL);
                getchar();
            return 0;
            }
        }
        insere_inscricoes_congs(nome,cpf,tema,tipo,cod);
        evento = fopen(arquivo_evento,"a");
        if(arquivo_evento == NULL){
            printf("\n\t\t\tEVENTO NAO ENCONTRADO");
            return 0;
        }
        fprintf(evento,"%s","NOME: ");
        fprintf(evento,"%s",nome);
        fprintf(evento,"%c",'\n');
        fprintf(evento,"%s","CPF: ");
        fprintf(evento,"%s",cpf);
        fprintf(evento,"%c",'\n');
        fprintf(evento,"%c",'\n');
        fclose(evento);

        printf("\n\t\t\t INSCRICAO REALIZADA COM SUCESSO \n");
        printf("\n\t\t\t>pressione qualquer tecla para voltar<");
        setbuf(stdin,NULL);
        getchar();
    return 1;

}




int cadastrar_palestrante(){
      FILE *p;

        limpa_tela();


        palestrante palest;
        palest.num_cadastro = gerar_numero_palestrante();
        int num = gerar_numero_cadastro();
        if(num+palest.num_cadastro>300)
            printf("\n\t\t\t>>>> CONGRESSO LOTADO <<<<");
        else{
        p = fopen(ARQ_PALESTRANTE,"a");
        if(p==NULL)
            printf("erro");
        printf("\n\t\t\tNOME: ");
        setbuf(stdin,NULL);
        gets(palest.nome);
        printf("\t\t\tCPF: ");
        setbuf(stdin,NULL);
        scanf("%s",palest.cpf);
        if(pesquisa_no_arquivo(ARQ_PALESTRANTE,palest.cpf)){
            printf("\n\t\t\t PALESTRANTE JA CADASTRADO\n");
            return 0;
        }
        printf("\t\t\tEMAIL: ");
        setbuf(stdin,NULL);
        gets(palest.email);
        printf("\t\t\tINSTITUICAO: ");
        setbuf(stdin,NULL);
        gets(palest.instituicao);

        strupr(palest.nome);
        strupr(palest.email);
        strupr(palest.instituicao);


        fprintf(p,"%s","NOME: ");
        fprintf(p,"%s",palest.nome);
        fprintf(p,"%c",'\n');
        fprintf(p,"%s","CPF: ");
        fprintf(p,"%s",palest.cpf);

        fprintf(p,"%c",'\n');
        fprintf(p,"%s","EMAIL: ");
        fprintf(p,"%s",palest.email);
        fprintf(p,"%c",'\n');
        fprintf(p,"%s","INSTITUICAO: ");
        fprintf(p,"%s",palest.instituicao);
        fprintf(p,"%c",'\n');
        fprintf(p,"%c",'\n');

        fclose(p);
        char texto_str[30];
        p = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\palestrantes.txt","r");
        while(fgets(texto_str, 20, p) != NULL)
            printf("%s", texto_str);
        fclose(p);

        printf("\n\t\t\tCADASTRO REALIZADO.\n");
        }
        return 1;

}

int cadastrar_congressista(){

      FILE *c;



        limpa_tela();

        congressista cong;
        cong.num_cadastro = gerar_numero_cadastro();
        if(cong.num_cadastro+gerar_numero_palestrante()>300)
            printf("\t\t\t>>>> CONGRESSO LOTADO <<<<");
        else{
        c = fopen(ARQ_CONGRESSISTA,"a");
        if(c==NULL)
            printf("erro");
        printf("\n\t\t\tNOME: ");
        setbuf(stdin,NULL);
        gets(cong.nome);
        printf("\t\t\tCPF: ");
        setbuf(stdin,NULL);
        scanf("%s",cong.cpf);
        if(pesquisa_no_arquivo(ARQ_CONGRESSISTA,cong.cpf)){
            printf("\n\t\t\tCONGRESSISTA JA CADASTRADO");
            return 0;
        }
        printf("\t\t\tEMAIL: ");
        setbuf(stdin,NULL);
        gets(cong.email);
        printf("\t\t\tINSTITUICAO: ");
        setbuf(stdin,NULL);
        gets(cong.instituicao);

        strupr(cong.nome);
        strupr(cong.email);
        strupr(cong.instituicao);
        fprintf(c,"%s","CPF: ");
        fprintf(c,"%s",cong.cpf);
        fprintf(c,"%c",'\n');
        fprintf(c,"%s","NOME: ");
        fprintf(c,"%s",cong.nome);
        fprintf(c,"%c",'\n');
        fprintf(c,"%s","EMAIL: ");
        fprintf(c,"%s",cong.email);
        fprintf(c,"%c",'\n');
        fprintf(c,"%s","INSTITUICAO: ");
        fprintf(c,"%s",cong.instituicao);
        fprintf(c,"%c",'\n');
        fprintf(c,"%c",'\n');

        fclose(c);


        printf("\n\t\t\tCADASTRO REALIZADO.\n");




        if(conta_linhas(ARQ_EVENTOS)){
            char op;
            do{
            printf("\n\t\t\tDESEJA CADASTRAR-SE EM EVENTO ALGUM EVENTO?(S/N)");
            scanf(" %c",&op);
            op = toupper(op);
            }while(op!='S'&&op!='N');
            if(op=='S'){
                inscricao1(cong.nome,cong.cpf);
            }
        }else{
            printf("\n\t\t\tAINDA NAO HA EVENTOS PARA SE INSCREVER");
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
    fprintf(ev1,"%s","TIPO DE EVENTO: ");
    fprintf(ev1,"%s",ev.tipo);
    fprintf(ev1,"%c",'\n');
    fprintf(ev1,"%s","INSCRITOS: ");
    fprintf(ev1,"%c",'\n');
    fclose(ev1);


}
int cadastrar_evento(){
    FILE *e;
    limpa_tela();
    e = fopen(ARQ_EVENTOS,"a");
    if(e==NULL)
        printf("erro");

    evento ev;
    int num;
    char **membros;
    char **cpfs;
    char tipo[20];
    char caminho[100] = "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\" ;
    printf("\n\t\t\tTIPO DO EVENTO(PALESTRA/GRUPO/CURSO/OFICINA): ");
    setbuf(stdin,NULL);
    scanf("%s",tipo);
    strupr(tipo);
    while(strcmp(tipo, "PALESTRA")&&strcmp(tipo, "GRUPO")&&strcmp(tipo, "CURSO")&&strcmp(tipo, "OFICINA")){
        printf("\t\t\tTIPO INVALIDO. DIGITE PALESTRA, GRUPO, CURSO OU OFICINA: ");
        setbuf(stdin,NULL);
        scanf("%s",tipo);
        strupr(tipo);
    }
        strcpy(ev.tipo,tipo);

    do{
    printf("\t\t\t>CODIGO(A-Z ou a-z): ");
    setbuf(stdin,NULL);
    scanf("%s",ev.codigo);
    }while(((int)ev.codigo[0]<(int)'A' || (int)ev.codigo[0]>(int)'Z') && ((int)ev.codigo[0]<(int)'a' || (int)ev.codigo[0]>(int)'z'));

    char pesquisa[100];

    strcpy(pesquisa,CODIGO_STR);
    strcat(pesquisa,ev.codigo);
    if(pesquisa_no_arquivo(ARQ_EVENTOS,pesquisa)){
        printf("\n\t\t\tEVENTO JA CADASTRADO.");
        return 0;
    }
    printf("\t\t\t>TEMA: ");
    setbuf(stdin,NULL);
    gets(ev.nome);
    strupr(ev.nome);

    char testa_cpf1[25];
    if(!strcmp(tipo,"GRUPO")){
       do{
       printf("\n\t\t\t>NUMERO DE MEMBROS DA MESA(ATE 5): ");
       scanf("%d",&num);
       }while(num<1||num>5);
       membros = (char**)malloc(num*sizeof(char*));
       cpfs = (char**)malloc(num*sizeof(char*));
       for(int i =0;i<num;i++){
         membros[i]=(char*)malloc(sizeof(char)*30);
         cpfs[i]=(char*)malloc(sizeof(char)*15);
       }
       for(int i = 0;i<num;i++){
         printf("\t\t\t>PALESTRANTE %d: ",i);
         setbuf(stdin,NULL);
         gets(membros[i]);
         printf("\t\t\t>CPF %d: ",i);
         setbuf(stdin,NULL);
         gets(cpfs[i]);
         strcpy(testa_cpf1,"\nCPF: ");
         strcat(testa_cpf1,cpfs[i]);
         if(!(pesquisa_no_arquivo(ARQ_PALESTRANTE,testa_cpf1))){
            printf("\t\t\tPALESTRANTE NAO CADASTRADO.");
            return 0;
         }
       }

    }else{
    printf("\t\t\t>PALESTRANTE: ");
    setbuf(stdin,NULL);
    gets(ev.palestrante);
    strupr(ev.palestrante);
    printf("\t\t\t>CPF DO PALESTRANTE: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.cpf_palestrante);
    printf("%s",ev.cpf_palestrante);
    char testa_cpf[25];
    strcpy(testa_cpf,"\nCPF: ");
    strcat(testa_cpf,ev.cpf_palestrante);
    if(!(pesquisa_no_arquivo(ARQ_PALESTRANTE,ev.cpf_palestrante))){
        printf("\t\t\tPALESTRANTE NAO CADASTRADO.");
        return 0;
    }

    /*
    char teste_palestrante[100];
    if(strcmp(tipo,"GRUPO") && strcmp(tipo,"PALESTRA")){

        strcpy(teste_palestrante,"CPF: ");
        strcat(teste_palestrante,ev.cpf_palestrante);
        strcat(teste_palestrante,"\nTIPO DE EVENTO: ");
        strcat(teste_palestrante,tipo);

        if(pesquisa_no_arquivo(ARQ_INSC_PALEST,teste_palestrante)){
            printf("\n\t\t\t PALESTRANTE JA MINISTRA %s",tipo);
            return 0;
        }
    }
    */
    if(checar_insc_palestrante(ev.cpf_palestrante,tipo)){
        printf("\t\t\tPALESTRANTE JA MINISTRA %s",tipo);
        return 0;
    }
    strcpy(ev.tipo,tipo);
    insere_inscricoes_palest(ev);
    }
    printf("\t\t\t>CARGA HORARIA: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.carga_horaria);
    char local[20];
    printf("\t\t\t----------------\n");
    printf("\t\t\t-> AUDITORIO 1\n");
    printf("\t\t\t-> AUDITORIO 2\n");
    printf("\t\t\t-> AUDITORIO 3\n");
    printf("\t\t\t-> SALA 1\n");
    printf("\t\t\t-> SALA 2\n");
    printf("\t\t\t-> SALA 3\n");
    printf("\t\t\t-> LABORATORIO 1\n");
    printf("\t\t\t-> LABORATORIO 2\n");
    printf("\t\t\t----------------\n");
    printf("\t\t\t>LOCAL: ");
    setbuf(stdin,NULL);
    gets(local);
    strupr(local);

    while(strcmp(local, "AUDITORIO 1")&&strcmp(local, "AUDITORIO 2")&&strcmp(local, "AUDITORIO 3")&&strcmp(local, "SALA 1")&&strcmp(local, "SALA 2")&&strcmp(local, "SALA 3")&&strcmp(local, "LABORATORIO 1")&&strcmp(local, "LABORATORIO 2")){
        printf("\t\t\tLOCAL INVALIDO. DIGITE UM DOS LOCAIS LISTADOS: ");
        setbuf(stdin,NULL);
        gets(local);
        strupr(local);
    }
    strcpy(ev.local,local);
    char data[12];
    printf("\t\t\t>DATA: ");
    setbuf(stdin,NULL);
    scanf("%s",data);
    printf("\t\t\t>HORARIO: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.horario);
    char teste[100] = "DATA: ";
    strcat(teste,data);
    strcat(teste,"\n");
    strcat(teste,"LOCAL: ");
    strcat(teste,ev.local);
    strcat(teste,"\n");
    strcat(teste,"HORA: ");
    strcat(teste,ev.horario);

    if(pesquisa_no_arquivo(ARQ_EVENTOS,teste)){
        printf("\t\t\tIMPOSSIVEL CADASTRAR. LOCAL OCUPADO NESSE HORARIO.");
        return 0;
    }

    fprintf(e,"%s","CODIGO DO EVENTO: ");
    fprintf(e,"%s",ev.codigo);
    fprintf(e,"%s"," ");
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
    fprintf(e,"%s",data);
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
    fprintf(e,"%s","TIPO DE EVENTO: ");
    fprintf(e,"%s",ev.tipo);
    fprintf(e,"%c",'\n');
    fprintf(e,"%c",'\n');
    fclose(e);
    //exibe_arquivo("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt");

    char cod[10];
    strcpy(cod,ev.codigo);
    strcat(cod,".txt");
    strcat(caminho,cod);
    //printf("\n%s",caminho);


    cria_arquivo_evento(caminho,ev,membros,cpfs,num);


    return 1;


}
int cadastrar_organizador(){
      FILE *o;

        limpa_tela();

        organizador org;

        o = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\organizadores.txt","a");
        if(o==NULL)
            printf("erro");
        printf("\t\t\tNOME: ");
        setbuf(stdin,NULL);
        gets(org.nome);
        printf("\t\t\tCPF: ");
        setbuf(stdin,NULL);
        scanf("%s",org.cpf);
        if(busca_cpf(ARQ_ORGANIZADORES,org.cpf)){
            printf("\nJA CADASTRADO\n");
            Sleep(400);
            return 0;
        }
        printf("\t\t\tEMAIL: ");
        setbuf(stdin,NULL);
        gets(org.email);

        strupr(org.nome);
        strupr(org.email);
        fprintf(o,"%s","NOME: ");
        fprintf(o,"%s",org.nome);
        fprintf(o,"%c",'\n');
        fprintf(o,"%s","CPF: ");
        fprintf(o,"%s",org.cpf);
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
    char tipo[20];
    char caminho[100] = "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\" ;
    printf("\t\t\tTIPO DO EVENTO(PALESTRA/GRUPO/CURSO/OFICINA): ");
    setbuf(stdin,NULL);
    scanf("%s",tipo);
    strupr(tipo);
    while(strcmp(tipo, "PALESTRA")&&strcmp(tipo, "GRUPO")&&strcmp(tipo, "CURSO")&&strcmp(tipo, "OFICINA")){
        printf("\t\t\tTIPO INVALIDO. DIGITE PALESTRA, GRUPO, CURSO OU OFICINA: ");
        setbuf(stdin,NULL);
        gets(tipo);
        strupr(tipo);
    }
    if(checar_insc_palestrante(cpf,tipo)){
        printf("\t\t\tPALESTRANTE JA MINISTRA UM CURSO/OFICINA.");
        return 0;
    }
    do{
    printf("CODIGO(A-Z ou a-z): ");
    setbuf(stdin,NULL);
    scanf("%s",ev.codigo);
    }while(((int)ev.codigo[0]<(int)'A' || (int)ev.codigo[0]>(int)'Z') && ((int)ev.codigo[0]<(int)'a' || (int)ev.codigo[0]>(int)'z'));

    char pesquisa[100];
    strcpy(pesquisa,CODIGO_STR);
    strcat(pesquisa,ev.codigo);
    if(pesquisa_no_arquivo(ARQ_EVENTOS,pesquisa)){
        printf("\n\t\t\tEVENTO JA CADASTRADO.");
        return 0;
    }

    printf("\t\t\tTEMA: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.nome);
    strupr(ev.nome);
    if(!strcmp(ev.tipo,"GRUPO")){
       do{
       printf("\t\t\tNUMERO DE MEMBROS DA MESA(ATE 5): ");
       scanf("%d",&num);
       }while(num<1||num>5);
       membros = (char**)malloc(num*sizeof(char*));
       cpfs = (char**)malloc(num*sizeof(char*));
       for(int i =0;i<num;i++){
         membros[i]=(char*)malloc(sizeof(char)*30);
         cpfs[i]=(char*)malloc(sizeof(char)*15);
       }
       for(int i = 0;i<num;i++){
         printf("\t\t\tPALESTRANTE %d: ",i);
         setbuf(stdin,NULL);
         gets(membros[i]);
         printf("\t\t\tCPF %d: ",i);
         setbuf(stdin,NULL);
         gets(cpfs[i]);
         char testa_cpf1[25];
        strcpy(testa_cpf1,"\nCPF: ");
        strcat(testa_cpf1,cpfs[i]);
         if(!(pesquisa_no_arquivo(ARQ_PALESTRANTE,cpfs[i]))){
            printf("\t\t\tPALESTRANTE NAO CADASTRADO.");
            return 0;
         }
       }

    }else{
    strcpy(ev.palestrante,nome);
    strcpy(ev.cpf_palestrante,cpf);
    strcpy(ev.tipo,tipo);
    insere_inscricoes_palest(ev);
    }
    printf("\t\t\tCARGA HORARIA: ");
    setbuf(stdin,NULL);
    gets(ev.carga_horaria);
    printf("\t\t\t----------------\n");
    printf("\t\t\t-> AUDITORIO 1\n");
    printf("\t\t\t-> AUDITORIO 2\n");
    printf("\t\t\t-> AUDITORIO 3\n");
    printf("\t\t\t-> SALA 1\n");
    printf("\t\t\t-> SALA 2\n");
    printf("\t\t\t-> SALA 3\n");
    printf("\t\t\t-> LABORATORIO 1\n");
    printf("\t\t\t-> LABORATORIO 2\n");
    printf("\t\t\t----------------\n");
    printf("\t\t\tLOCAL: ");
    setbuf(stdin,NULL);
    gets(ev.local);
    strupr(ev.local);
    while(strcmp(ev.local, "AUDITORIO 1")&&strcmp(ev.local, "AUDITORIO 2")&&strcmp(ev.local, "AUDITORIO 3")&&strcmp(ev.local, "SALA 1")&&strcmp(ev.local, "SALA 2")&&strcmp(ev.local, "SALA 3")&&strcmp(ev.local, "LABORATORIO 1")&&strcmp(ev.local, "LABORATORIO 2")){
        printf("\t\t\tLOCAL INVALIDO. DIGITE UM DOS LOCAIS LISTADOS: ");
        setbuf(stdin,NULL);
        gets(ev.local);
        strupr(ev.local);
    }
    printf("\t\t\tDATA: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.data);
    printf("\t\t\tHORARIO: ");
    setbuf(stdin,NULL);
    scanf("%s",ev.horario);
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
        printf("\t\t\tIMPOSSIVEL CADASTRAR. LOCAL OCUPADO NESSE HORARIO.");
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
