#include <stdio.h>

void leerDatos(int[], int);
void mostrarVector(int [], int);
int tendencia(int[], int);

int main(){
    int dias, trend;
    
    scanf("%d", &dias);
    
    int ventas[dias];
    
    leerDatos(ventas, dias);
    printf("Ventas de unidades diarias del producto en el\n");
    printf("período de %d días = ", dias);
    mostrarVector(ventas, dias);
    
    trend = tendencia(ventas, dias);
    printf("La tendencia de ventas en el período fue %d.", trend);
    
    return 0;
}

void leerDatos(int arr[], int tam){
    int i;
    
    for(i = 0 ; i<tam ; i++){
        scanf("%d", &arr[i]);
    }
}

void mostrarVector(int arr[], int tam){
    int i;
    
    printf("[%d", arr[0]);
    for(i = 1 ; i<tam ; i++){
        printf(", %d", arr[i]);
    }
    printf("]\n");
}

int estado(int arr[], int tam){
    int i;
    int creciente, decreciente, estable;
    
    for(i = 0 ; i<tam-1 ; i++){
        if(arr[i] > arr[i+1]) creciente = 1;
        if(arr[i] < arr[i+1]) decreciente = 1;
        if(arr[i] == arr[i+1]) estable = 1;
    }
    
    if(creciente){
        if(decreciente || estable) return 0;
        return 1;
    }
    
    if(decreciente){
        if(creciente || estable) return 0;
        return -1;
    }
    
    if(estable) return 2;
}