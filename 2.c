#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXNUMCARTON 6
#define MAXNUMEROSLOTO 41

typedef struct
{
    unsigned short numSorteoCorr; //Nº Sorteo Correlativo
    unsigned short numerosSorteados[MAXNUMCARTON]; //Números sorteados en ese sorteo
} tipoSorteo;

typedef struct
{
    unsigned short numero; //almacena cada uno de los posible 41 números
    unsigned short frecuencia; //almacena su frecuencia de sorteo
} tipoNumSort;

int cmp(const void *pivote, const void *elemento){
    unsigned short *piv = (unsigned short *)pivote;
    unsigned short *elem = (unsigned short *)elemento;
    if ((*piv) > (*elem)) return 1;
    return 0;
}

tipoSorteo extraerNumeros(int numSorteo){
    tipoSorteo temporal;

    temporal.numSorteoCorr = numSorteo;
    int i;
    
    for (i = 0; i < MAXNUMCARTON; i++){
        scanf("%hu", &temporal.numerosSorteados[i]);
    }
    qsort(temporal.numerosSorteados, 6, sizeof(unsigned short), cmp);

    return temporal;
}

void poblarSorteo(tipoSorteo *sorteos, unsigned short totalSorteos){
    int i;
    for (i = 0; i < totalSorteos; i++){
        sorteos[i] = extraerNumeros(i + 1);
    }
    
}

void mostrarSorteo(tipoSorteo sorteo){
    int i;
    printf("Sorteo #%hu --> Números Extraídos Tómbola = [", sorteo.numSorteoCorr);
    for (i = 0; i < MAXNUMCARTON; i++){
        printf(" %hu ", sorteo.numerosSorteados[i]);
        if (i != MAXNUMCARTON - 1) printf(",");
        else printf("]\n");
    }
}

void realizarSorteo(tipoSorteo *sorteos, unsigned short totalSorteos){
    int i;
    printf("Se procesarán los datos de %hu sorteo(s).\n\n", totalSorteos);
    printf("SORTEOS Y NÚMEROS EXTRAÍDOS\n");
    printf("===========================\n");
    for (i = 0; i < totalSorteos; i++){
        mostrarSorteo(sorteos[i]);
    }
}

void inicializar(tipoNumSort vectorNumeros[], unsigned short MAX){
    unsigned short i;
    
    for(i = 0 ; i<MAX ; i++){
        vectorNumeros[i].numero = i+1;
        vectorNumeros[i].frecuencia = 0;
    }
}

int seEncuentra(unsigned short numeros[], unsigned short MAX, unsigned short numBuscado){
    unsigned short i;
    
    for(i = 0 ; i<MAX ; i++){
        if(numeros[i] == numBuscado) return 1;
    }
    return 0;
}

void contarFrecuencia(tipoNumSort vectorNumeros[], unsigned short MAX, tipoSorteo sorteos[], unsigned short cantSorteos){
    unsigned short i, k;
    
    for(i = 0 ; i < MAX ; i++){
        for(k = 0 ; k < cantSorteos ; k++){
        
            if(seEncuentra(sorteos[k].numerosSorteados, MAXNUMCARTON, vectorNumeros[i].numero)){
                vectorNumeros[i].frecuencia += 1;
            }
        }
    }
}

unsigned short mostrarNumerosSorteados(tipoNumSort vector[], unsigned short talla)
{
    printf("\nNÚMEROS SORTEADOS EN EL PERÍODO SIN REPETICIONES & ORDENADOS DE MENOR A MAYOR\n");
    printf("=============================================================================\n");
    unsigned short contador = 0;
    for (unsigned short k = 0 ; k < talla ; k++)
        if (vector[k].frecuencia != 0)
        {
            contador++;
            if (vector[k].frecuencia > 1)
                printf("El Nº %hu fue sorteado %hu veces.\n", vector[k].numero, vector[k].frecuencia);
            else
                printf("El Nº %hu fue sorteado %hu vez.\n", vector[k].numero, vector[k].frecuencia);
        }

    printf("\nEn total se sortearon %hu números diferentes.\n", contador);
    return contador;
}

void mostrarNumerosNOSorteados(tipoNumSort vector[], unsigned short talla, unsigned short cuantos)
{
    printf("\nNÚMEROS NO SORTEADOS EN EL PERÍODO ORDENADOS DE MENOR A MAYOR\n");
    printf("=============================================================\n");
    if (cuantos == MAXNUMEROSLOTO)
    {
        printf("TODOS LOS NÚMEROS ENTRE 1..41 FUERON SORTEADOS.");
        return;
    } 
    unsigned short contador = 0;
    for (unsigned short k = 0 ; k < talla ; k++)
        if (vector[k].frecuencia == 0)
        {
            if  (contador == 0) printf("%hu", vector[k].numero);
            else printf(" , %hu", vector[k].numero);
            contador++;
        }    
    
    printf("\n\nEn total NO se sortearon %hu números.\n", contador);

} 


int main()
{
    unsigned short totalSorteos, cantNumSorteados;
    tipoNumSort vectorNumeros[MAXNUMEROSLOTO];
    
    scanf("%hu", &totalSorteos);
    tipoSorteo sorteos[totalSorteos];
    
    poblarSorteo(sorteos, totalSorteos);
    realizarSorteo(sorteos, totalSorteos);
    
    inicializar(vectorNumeros, MAXNUMEROSLOTO);
    contarFrecuencia(vectorNumeros, MAXNUMEROSLOTO, sorteos, totalSorteos);
    
    cantNumSorteados = mostrarNumerosSorteados(vectorNumeros, MAXNUMEROSLOTO);
    mostrarNumerosNOSorteados(vectorNumeros, MAXNUMEROSLOTO, cantNumSorteados);
    
    return 0;
}
