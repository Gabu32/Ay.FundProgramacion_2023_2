#include <stdio.h>
#include <math.h>

long validar();
void proceso(int, int);
int esPrimo(int);

int main(){
    char tipo;
    int distancia;
    long n;
    
    scanf("%c", &tipo);
    
    n = validar();
    
    if(tipo == 'G'){
        printf("LOS PRIMEROS %ld PRIMOS GEMELOS SON :\n\n", n);
        distancia = 2;
    } 
    
    if(tipo == 'P'){
        printf("LOS PRIMEROS %ld PRIMOS PARIENTES SON :\n\n", n);
        distancia = 4;
    } 
    
    if(tipo == 'S'){
        printf("LOS PRIMEROS %ld PRIMOS SEXI SON :\n\n", n);
        distancia = 6;
    } 
    
    proceso(n, distancia);
    
    return 0;
}

long validar(){
    long n;
    
    while(1){
        scanf("%ld", &n);
        if(n > 0 && n < 1000) return n;
    }
}

void proceso(int n, int dist){
    int i = 2, cont = 0;
    
    while(1){
        if(cont == n) return;
        
        if(esPrimo(i) && esPrimo(i+dist)){
            if(cont%5 == 0 && cont != 0) printf("\n");
            printf("(%d,%d) ",i, i+dist);
            cont++;
        }
        i++;
    }
}

int esPrimo(int num){
    int i, raizTrunc;
    
    raizTrunc = trunc(sqrt(num));
    
    for(i = 2 ; i<raizTrunc+1 ; i++){
        if(num%i == 0) return 0;
    }
    return 1;
}