#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

#define ARQ_PALESTRANTE "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\palestrantes.txt"
#define ARQ_CONGRESSISTA "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\congressistas.txt"
#define ARQ_ORGANIZADORES "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\organizadores.txt"
#define ARQ_EVENTOS "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\eventos.txt"
#define ARQ_INSC_CONG "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\inscricoescong.txt"
#define ARQ_INSC_PALEST "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\inscricoespalest.txt"
#define CAMINHO "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\"

#define ARQ_TRANSFERIR "C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\transferindo.txt"


#define LINHAS_PESSOA 5
#define LINHAS_EVENTO 9
#define CODIGO_STR "CODIGO DO EVENTO: "



//funcoes para manipular os arquivos
void exibe_arquivo(char *arquivo);
int conta_linhas(char *arquivo);
int pesquisa_no_arquivo(char *arquivo,char *str);
void exibir_dados_pessoas(char *arquivo,char *str);
void exibir_dados_evento(char *str);
int linha_selecionada(char *arquivo, char *str);
void editar_dados_pessoas(char *arquivo, int linha,char *novo_dado);
int remover_dados(char *arquivo,int linha,int seguintes);
int limpar_caracteres(char *arquivo);
int busca_cpf(char *arquivo,char *cpf);
int busca_cpf_palest(char *arquivo,char *cpf);
void exibe_arquivo2(char *arquivo);
int checa_existencia_evento(char *cod);

void borda();

#endif // ARQUIVO_H_INCLUDED
