#include <stdio.h>
#define MAX 100

void leerDatos(int[], int);
void mostrarVector(int[], int);
int cantCimas(int[], int);

int main(){
    int tam, i = 0;
    int arr[MAX];
    
    while(1){
        scanf("%d", &tam);
        if(tam == 0) return 0;
        
        i++;
        leerDatos(arr, tam);
        
        printf("=====================\n");
        printf("CASO DE PRUEBA %d\n", i);
        printf("=====================\n");
        
        printf("Lista de Alturas Montaña Rusa = ");
        mostrarVector(arr, tam);
        
        printf("La montaña Rusa tiene %d cima(s).\n\n", cantCimas(arr, tam));
    }
}

void leerDatos(int arr[], int tam){
    int i;
    
    for(i = 0 ; i<tam ; i++){
        scanf("%d", &arr[i]);
    }
}

void mostrarVector(int arr[], int tam){
    int i;
    
    printf("[");
    for(i = 0 ; i<tam-1 ; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[tam-1]);
}

int cantCimas(int arr[], int tam){
    int cimas = 0, i;
    
    if(arr[0] > arr[1] && arr[0] > arr[tam-1]) cimas++;
    
    for(i = 1 ; i<tam-1 ; i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) cimas++;
    }
    
    if(arr[tam-1] > arr[tam-2] && arr[tam-1] > arr[0]) cimas++;
    
    return cimas;
}