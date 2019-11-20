#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}data;
typedef struct{
    int horas;
    int minutos;
    int segundos;
}hora;

struct data_hora{
    hora h;
    data dia;
};

typedef struct data_hora data_hora;
/*
void exibe_hora(hora *h){
    printf("%d:%d",h->horas,h->minutos);
}
void exibe_data(data *d){
    printf("%d/%d/%d",d->dia,d->mes,d->ano);
}
void exibe_data_hora(data_hora *dh){
printf("%d:%d ",dh->h.horas,dh->h.minutos);
printf(" %d/%d/%d",dh->dia.dia,dh->dia.mes,dh->dia.ano);
}
*/
