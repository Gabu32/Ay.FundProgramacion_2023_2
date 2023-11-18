#include <stdio.h>
#include <stdlib.h>

typedef struct{
    size_t codigo, totalReproducciones;
} tipoCancion;

void poblar(tipoCancion *vector, unsigned short totalCanciones){
    int i;
    for (i = 0; i < totalCanciones;i++){
        scanf("%zd %zd", &vector[i].codigo, &((vector + i) -> totalReproducciones));
    }
}

int cmp(const void *piv, const void *elem){
    tipoCancion *pivote = (tipoCancion *)piv;
    tipoCancion *elemento = (tipoCancion *)elem;
    
    if (pivote -> totalReproducciones < elemento -> totalReproducciones) return 1;
    if (pivote -> totalReproducciones == elemento -> totalReproducciones){
        if (pivote -> codigo > elemento -> codigo) return 1;
    }
    return 0;
    
}

void mostrar(tipoCancion *vector, unsigned short totalCanciones){
    int i;
    printf(" _______________________ ________________________\n");
    printf("|    CODIGO CANCION     |  TOTAL REPRODUCCIONES  |\n");
    printf("|_______________________|________________________|\n");
    printf("|                       |                        |\n");
    
    for (i = 0; i < totalCanciones; i++){
        printf("|%22zd |%23zd |\n", vector[i].codigo, (vector + i) -> totalReproducciones);
    }
    
    
    printf("|_______________________|________________________|\n");

    
    
}

int main(){
    unsigned short totalCanciones;
    scanf("%hu", &totalCanciones);
    tipoCancion vector[totalCanciones];
    
    poblar(vector, totalCanciones);
    qsort(vector, totalCanciones, sizeof(tipoCancion), cmp);
    mostrar(vector, totalCanciones);
    
    return 0;
}
