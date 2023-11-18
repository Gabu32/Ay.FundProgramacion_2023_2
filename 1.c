#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define POSNULA -1
#define MAX 10000

typedef struct{
    unsigned short dia;
    unsigned short mes;
    unsigned short anyo;
} tipoFecha;

typedef struct{
    size_t codigoPelicula;
    tipoFecha estreno;
    size_t audiencia;
} tipoPelicula;

int poblarVector(tipoPelicula[]);
void mostrarVector(tipoPelicula[], int);
int cmp(const void*, const void*);
void proceso(tipoPelicula[], int);

int main(){
    int largo;
    tipoPelicula arr[10000];
    
    largo = poblarVector(arr);
    
    qsort(arr, largo, sizeof(tipoPelicula), cmp);
    
    mostrarVector(arr, largo);
    proceso(arr, largo);
    
    return 0;
}

int poblarVector(tipoPelicula arr[]){
    int i = 0;
    size_t cod, audiencia;
    unsigned short d, m, a;
    
    while(1){
        scanf("%zd", &cod);
        
        if(!cod) return i;
        
        scanf("%hu %hu %hu", &d, &m, &a);
        scanf("%zd", &audiencia);
        
        arr[i].codigoPelicula = cod;
        arr[i].audiencia = audiencia;
        arr[i].estreno.dia = d;
        arr[i].estreno.mes = m;
        arr[i].estreno.anyo = a;
        
        i++;
    }
}

void mostrarVector(tipoPelicula arr[], int n){
    int i;
    
    printf(" =============================================================\n");
    printf("|  CODIGO PELICULA    | FECHA ESTRENO  |        AUDIENCIA     |\n");
    printf(" =============================================================\n");
    for(i = 0 ; i<n ; i++){
        printf("| %19zd | %2hu - %2hu - %2hu | %20zd |\n", arr[i].codigoPelicula, arr[i].estreno.dia, arr[i].estreno.mes, 
                                                        arr[i].estreno.anyo, arr[i].audiencia);
        
    }
    printf(" =============================================================\n\n");
}

int cmp(const void *ptrA, const void *ptrB){
    tipoPelicula *a = (tipoPelicula*)ptrA;
    tipoPelicula *b = (tipoPelicula*)ptrB;
    
    if(a->estreno.anyo > b->estreno.anyo) return 1;
    if(a->estreno.anyo < b->estreno.anyo) return 0;
    
    if(a->estreno.mes > b->estreno.mes) return 1;
    if(a->estreno.mes < b->estreno.mes) return 0;
    
    if(a->estreno.dia > b->estreno.dia) return 1;
    if(a->estreno.dia < b->estreno.dia) return 0;
    
    return (a->codigoPelicula - b->codigoPelicula);
    
    return 0;
}

void proceso(tipoPelicula arr[], int n){
    int i, j;
    size_t audienciaMayor;
    
    tipoFecha fechaMayor, fechaActual;
    tipoPelicula peliculaMayor;
    
    for(i = 0 ; i < n ; i++){
        
        printf("Código Película = %zd\n", arr[i].codigoPelicula);
        printf("Fecha Estreno = %hu-%hu-%hu\n", arr[i].estreno.dia, arr[i].estreno.mes, arr[i].estreno.anyo);
        printf("Audiencia = %zd\n", arr[i].audiencia);
        
        audienciaMayor = arr[i].audiencia;
        fechaActual = arr[i].estreno;
        
        for(j = i-1 ; j >= 0 ; j--){
            if(arr[j].audiencia > arr[i].audiencia){
                fechaMayor = arr[j].estreno;
                peliculaMayor = arr[j];
                audienciaMayor = arr[j].audiencia;
                break;
            }
        }
        
        if(audienciaMayor == arr[i].audiencia || (fechaMayor.anyo == fechaActual.anyo && fechaMayor.mes == fechaActual.mes && fechaActual.dia == fechaMayor.dia)){
            printf("NO EXISTE UNA PELÍCULA QUE SE HAYA ESTRENADO ANTES Y QUE TENGA MAYOR AUDIENCIA QUE LA PROCESADA.\n\n");
            continue;
        }
        
        printf("DATOS PELÍCULA PREVIAMENTE ESTRENADA QUE TUVO MÁS AUDIENCIA QUE LA PROCESADA.\n");
        printf("Código Película = %zd\n", peliculaMayor.codigoPelicula);
        printf("Fecha Estreno = %hu-%hu-%hu\n", fechaMayor.dia, fechaMayor.mes, fechaMayor.anyo);
        printf("Audiencia = %zd\n\n", peliculaMayor.audiencia);
    }
}
