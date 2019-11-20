#include "congressista.h"
#include "palestrante.h"
#include "organizador.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
void listar_palestrante(){}
void listar_congressista(){
    FILE *c;
    char ch;
    c = fopen("C:\\Users\\Rebeca\\Documents\\CC\\ENCEC2019\\Encec2019\\congressistas.txt","r");
    if(c==NULL)
        printf("erro");

    while (!feof(c))        		/* Enquanto não se chegar no final do arquivo */
    {
     printf("%c",ch); 		/*   Imprime o caracter na tela */
     ch = getc(c);    		/* Le um novo caracter no arquivo */
    }
    fclose(c);
}
void listar_evento(){}
void listar_organizador(){}
