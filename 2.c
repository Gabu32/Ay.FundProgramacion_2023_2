#include <stdio.h>
#define MAX 1000

void leerDatos(int[], int);
void calcularRecorrido(int[], int[], int);
int sumarVector(int[], int);
void mostrarVector(int[], int);
void imprimir(int[], int[], int, int);

int main(){
    int i = 1, tam;
    
    while(1){
        scanf("%d", &tam);
        
        if(tam == 0) return 0;
        
        int distanciasInicial[tam];
        int distanciasRecorrer[tam];
        
        leerDatos(distanciasInicial, tam);
        calcularRecorrido(distanciasInicial, distanciasRecorrer, tam);
        
        imprimir(distanciasInicial, distanciasRecorrer, tam, i);
        i++;
    }
}

void leerDatos(int arr[], int tam){
    int i;
    
    for(i = 0 ; i<tam ; i++){
        scanf("%d", &arr[i]);
    }
}

void calcularRecorrido(int arr[], int arr2[], int tam){
    int i, suma;
    
    suma = sumarVector(arr, tam);
    
    arr2[0] = suma;
    
    for(i = 1 ; i<tam ; i++){
        arr2[i] = arr2[i-1] - arr[i-1];
    }
}

int sumarVector(int arr[], int tam){
    int i, suma = 0;
    
    for(i = 0 ; i<tam ; i++){
        suma += arr[i];
    }
    return suma;
}

void mostrarVector(int arr[], int tam){
    int i;
    printf("[%d", arr[0]);
    for(i = 1 ; i<tam ; i++){
        printf(", %d", arr[i]);
    }
    printf("]\n");
}

void imprimir(int arr[], int arr2[], int tam, int i){
    printf("=====================\n");
    printf("CASO DE PRUEBA %d\n", i);
    printf("=====================\n");

    printf("Lista de distancias de c/etapa de la ruta = ");
    mostrarVector(arr, tam);
    
    printf("Lista de distancias por recorrer desde el comienzo\n");
    printf("de c/etapa hasta el final de la ruta = ");
    mostrarVector(arr2, tam);
    printf("\n");
}