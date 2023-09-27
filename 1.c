#include stdio.h

void leerEdades(int[], int);
void mostrarVector(int[], int);
void guardarDiferentes(int[], int[], int, int);
int noEsta(int[], int, int);
int contarFrecuencias(int[], int[], int[], int, int);
int contar(int[], int, int);

int main(){
    int edades[1000];
    int tam = 0, tam2 = 0, max, totalModas;
    int i;
    
    leerEdades(edades, &tam);
    
    mostrarVector(edades, tam);
    
    int edadesDiferentes[tam];
    
    guardarDiferentes(edades, edadesDiferentes, tam, &tam2);
    
    int frecuencias[tam2];
    
    max = contarFrecuencias(edades, edadesDiferentes, frecuencias, tam, tam2);
    
    totalModas = contar(frecuencias, max, tam2);
    
    if(max == 1){
        printf(En este conjunto de edades NO existe una moda !);
    }
    
    else{
        printf(La moda de este conjunto de edades es  );
        
        for(i = 0 ; itam2 ; i++){
            if(frecuencias[i] == max){
                totalModas--;
                if(totalModas  0) printf(%d , , edadesDiferentes[i]);
                else printf(%d, edadesDiferentes[i]);
            }
        }
    }
    
    return 0;
}

void leerEdades(int arr[], int i){
    while(1){
        scanf(%d, &arr[i]);
        if(arr[i] == 0) return;
        
        i += 1;
    }
}

void mostrarVector(int arr[], int n){
    int i;
    printf(Vector Edades =[);
    
    for(i = 0 ; in-1 ; i++){
        printf(%d, , arr[i]);
    }
    printf(%d]n, arr[n-1]);
}

void guardarDiferentes(int arrEdades[], int arrEdadesDif[], int tam, int tam2){
    int i;
    
    for(i = 0 ; itam ; i++){
        if(noEsta(arrEdadesDif, arrEdades[i], tam2)){
            arrEdadesDif[tam2] = arrEdades[i];
            tam2 += 1;
        }
    }
}

int noEsta(int arr[], int num, int tam){
    int i;
    
    for(i = 0 ; itam ; i++){
        if(arr[i] == num) return 0;
    }
    
    return 1;
}

int contarFrecuencias(int arrEdades[], int arrEdadesDif[], int frecuencias[], int tamEdades, int tam){
    int i, max;
    
    for(i = 0 ; itam; i++){
        frecuencias[i] = contar(arrEdades, arrEdadesDif[i], tamEdades);
        
        if(i == 0) max = frecuencias[i];
        
        if(frecuencias[i]  max) max = frecuencias[i];
    }
    
    return max;
}

int contar(int arr[], int num, int tam){
    int i, cont = 0;
    
    for(i = 0 ; itam ; i++){
        if(arr[i] == num) cont++;
    }
    
    return cont;
}