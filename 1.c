#include <stdio.h>
#define MAX 155

int leerVotos(int[]);
void mostrarVector(int[], int);
void contarVotos(int[], int);
void decision(int, int, int);

int main(){
    int total = 0;
    int votos[MAX];
    
    total = leerVotos(votos);
    printf("En total votaron %d convencionales en el pleno.\n", total);
    printf("La lista de votos fue = ");
    mostrarVector(votos, total);
    
    contarVotos(votos, total);
    
    return 0;
}

int leerVotos(int arr[]){
    int i = 0;
    int voto; 
    
    while(1){
        scanf("%d", &voto);
        if(voto != 1 && voto != 0) return i;
        
        arr[i] = voto;
        i++;
    }
}

void mostrarVector(int arr[], int tam){
    int i;
    
    printf("[");
    for(i = 0 ; i<tam-1 ; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d].\n", arr[tam-1]);
}

void contarVotos(int arr[], int tam){
    int apruebo = 0, rechazo = 0;
    int i;
    
    for(i = 0 ; i<tam ; i++){
        if(arr[i] == 1) apruebo += 1;
        else rechazo += 1;
    }
    
    printf("\nTotal de votos APRUEBO = %d.\n", apruebo);
    printf("Total de votos RECHAZO = %d.\n\n", rechazo);
    
    decision(apruebo, rechazo, tam);
}

void decision(int apruebo, int rechazo, int total){
    if(apruebo >= 2*total / 3){
        printf("La norma es aprobada con %d de %d votos.", apruebo, total);
        
        if(apruebo == total) printf("\nLA APROBACIÓN FUE UNÁNIME!.");
    }
    
    else if(apruebo > rechazo) 
        printf("La norma regresa a la comisión de origen para ser reformulada.");
    
    else{
        printf("La norma es rechazada definitivamente.");
        
        if(rechazo == total) printf("\nEL RECHAZO FUE UNÁNIME!.");
    }
}