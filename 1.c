#include <stdio.h>
#define MAXTALLA 10000

int leerDatos(unsigned long []);
void mostrarVector(unsigned long[], int);
unsigned long buscarMenor(unsigned long[], int);
unsigned long buscarMayor(unsigned long[], int);
int contarVeces(unsigned long[], int, unsigned long);

int main(){
    int n, i, tam, veces;
    unsigned long vector[MAXTALLA];
    unsigned long menor, mayor;
    
    scanf("%d", &n);
    
    for(i = 0 ; i < n ; i++){
        
        printf("******* CASO PRUEBA Nº %d *******\n\n", i+1);
        tam = leerDatos(vector);
        mostrarVector(vector, tam);
        
        menor = buscarMenor(vector, tam);
        veces = contarVeces(vector, tam, menor);
        if(veces == 1) printf("La menor temperatura fue %lu y aparece 1 vez.\n", menor);
        else printf("La menor temperatura fue %lu y aparece %d veces.\n", menor, veces);

        mayor = buscarMayor(vector, tam);
        veces = contarVeces(vector, tam, mayor);
        
        if(veces == 1) printf("La mayor temperatura fue %lu y aparece 1 vez.\n\n", mayor);
        else printf("La mayor temperatura fue %lu y aparece %d veces.\n\n", mayor, veces);
    }
    
    return 0;
}

int leerDatos(unsigned long arr[]){
    int ind = 0;
    
    while(1){
        scanf("%lu", &arr[ind]);
        if(arr[ind] == 0) return ind;
        ind++;
    }
}

void mostrarVector(unsigned long arr[], int tam){
    int i;
    
    printf("Temperaturas Leídas = [%lu", arr[0]);
    
    for(i = 1 ; i < tam ; i++){
        printf(", %lu", arr[i]);
    }
    
    printf("]\n");
}

unsigned long buscarMenor(unsigned long arr[], int tam){
    int i;
    unsigned long menor;
    
    for(i = 0 ; i < tam ; i++){
        if(i == 0) menor = arr[0];
    
        if(arr[i] < menor) menor = arr[i];
    }
    
    return menor;
}

unsigned long buscarMayor(unsigned long arr[], int tam){
    int i;
    unsigned long mayor;
    
    for(i = 0 ; i < tam ; i++){
        if(i == 0) mayor = arr[0];
    
        if(arr[i] > mayor) mayor = arr[i];
    }
    
    return mayor;
}

int contarVeces(unsigned long arr[], int tam, unsigned long num){
    int i, cont = 0;
    
    for(i = 0 ; i<tam ; i++){
        if(arr[i] == num) cont++;
    }
    
    return cont;
}