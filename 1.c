#include <stdio.h>
#include <stdlib.h>

void proceso(int);
void poblarVector(int*, int);
void mostrarVector(int*, int);
int cmp(const void*, const void*);
int cantidadVictorias(int*, int*, int);

int main(){
    int n;
    
    scanf("%d", &n);
    
    proceso(n);
    
    return 0;
}

void poblarVector(int *arr, int n){
    int i;
    
    for(i = 0 ; i<n ; i++){
        scanf("%d", &arr[i]);
    }
}

void mostrarVector(int *arr, int n){
    int i;
    
    printf(" [%d", arr[0]);
    for(i = 1 ; i<n-1 ; i++){
        printf(", %d", arr[i]);
    }
    printf(", %d]\n", arr[n-1]);
}

int cmp(const void *p1, const void *p2){
    int *ele1 = (int*)p1;
    int *ele2 = (int*)p2;
    
    return (*ele1 - *ele2);
}

int cantidadVictorias(int *vecEnemigos, int *vecDefensa, int cant){
    int victorias = 0;
    int i, j = 0;
    
    qsort(vecEnemigos, cant, sizeof(int), cmp);
    qsort(vecDefensa, cant, sizeof(int), cmp);
    
    for(i = 0 ; i<cant ; i++){
        if(vecDefensa[i] >= vecEnemigos[j]){
            victorias++;
            j++;
        }
    }
    
    return victorias;
}

void proceso(int n){
    int i, cantCiudades;
    int *vecEnemigos, *vecDefensa;
    int victorias;
    
    for(i = 0 ; i<n ; i++){
        scanf("%d", &cantCiudades);
        
        vecEnemigos = (int*) malloc(cantCiudades * sizeof(int)); 
        vecDefensa = (int*) malloc(cantCiudades * sizeof(int));
        
        poblarVector(vecEnemigos, cantCiudades);
        poblarVector(vecDefensa, cantCiudades);
        
        printf("-----------------------------------------------------------------\n");
        printf("CASO DE PRUEBA %d\n", i+1);
        printf("-----------------------------------------------------------------\n");
        
        printf("No. de Ciudades Invadidas = %d\n", cantCiudades);
        
        printf("VECTOR No. DE ENEMIGOS = ");
        mostrarVector(vecEnemigos, cantCiudades);
        
        printf("VECTOR No. DE DEFENSAS = ");
        mostrarVector(vecDefensa, cantCiudades);
        
        victorias = cantidadVictorias(vecEnemigos, vecDefensa, cantCiudades);
        printf("El No. Máx. de Ciudades en que se puede garantizar la Victoria es %d\n\n", victorias);
        
        free(vecEnemigos);
        free(vecDefensa);
    }
    
}
