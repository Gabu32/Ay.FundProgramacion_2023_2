#include <stdio.h>
#include <math.h>

int numeroTriangulo(int);
void calcularAlturaMaxima(int);
void imprimirPiramide(int, int);

int main(){
    int cantFichas;
    
    scanf("%d", &cantFichas);
    
    calcularAlturaMaxima(cantFichas);
    
    return 0;
}

int numeroTriangulo(int num){
    int suma = 0, i = 0;
    
    while(suma < num){
        suma += i;
        i++;
    }
    
    if(suma == num) return i-1;
    return 0;
}

void calcularAlturaMaxima(int cantFichas) {
    int acum = 0;
    int base = 0, tope = 1;
    int altura = numeroTriangulo(cantFichas);

    if(altura){
        printf("La altura de la pirámide NO TRUNCADA ");
        base = altura;
    }
    
    else{
        printf("La altura de la pirámide TRUNCADA ");
        while(1){
            acum += base + 1;
            base++;
            altura++;
            
            if(acum == cantFichas) break;
            
            if(acum > cantFichas){
                base = tope++;
                altura = 0;
                acum = 0;
            }
        }
    }

    printf("más alta que se puede construir con %d piezas es %d\n", cantFichas, altura);
    
    if(tope == base){
        printf("El piso inferior & superior de la pirámide tiene %d ", tope);
        tope == 1 ? printf("ficha\n") : printf("fichas\n");
    } 

    else{
        printf("El piso superior de la pirámide tiene %d ", tope);
        tope == 1 ? printf("ficha\n") : printf("fichas\n");
        printf("El piso inferior de la pirámide tiene %d fichas\n", base);
    }
    
    imprimirPiramide(altura, base);
}

void imprimirPiramide(int altura, int base){
    int i, j;
    
    printf("\nDIBUJO PIRÁMIDE\n");
    for(i = altura ; i > 0 ; i--){
        
        for(j = 0 ; j < i-1 ; j++) printf(" ");
        
        for(j = base - i + 1 ; j > 0 ; j--) printf("= ");
        
        printf("\n");
    }
}