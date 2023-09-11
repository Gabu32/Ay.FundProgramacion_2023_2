#include <stdio.h>
#include <math.h>

/* Recordar:
Formula sumatoria: n(n+1) / 2
*/

int esTriangulo(unsigned long);
int esCuadradoPerfecto(unsigned long);
void imprimirTriangulo(short);
void imprimirCuadrado(short);
int cuadradoCercano(unsigned long);

int main(){
    unsigned long fotos, fotosRestantes, lado;
    short casos = 0, cuadrados = 0;
    
    while(1){
        scanf("%lu",&fotos);
        
        if(fotos == 0){
            printf("***** FIN PROCESAMIENTO DE DATOS *****");
            return 0;
        }
        
        casos++;
        
        printf("----------------------------------------------------------------------------\n");
        printf("CASO DE PRUEBA #%u - CANTIDAD DE FOTOS %lu\n",casos,fotos);
        printf("----------------------------------------------------------------------------\n");
        
        lado = esTriangulo(fotos);
        
        if(lado){
            printf("Sophie formará un triángulo de lado %lu con %lu foto(s)\n\n", lado, fotos);
            if(fotos<=50){
                printf("Como la cantidad de fotos es menor o igual a 50, se diagrama!\n");
                imprimirTriangulo(lado);
                printf("\n\n");
            }
            continue;
        }
        
        lado = esCuadradoPerfecto(fotos);
        
        if(lado){
            printf("Sophie formará un cuadrado de lado %lu con %lu foto(s)\n\n", lado, fotos);
            if(fotos<=50){
                printf("Como la cantidad de fotos es menor o igual a 50, se diagrama!\n");
                imprimirCuadrado(lado);
                printf("\n\n");
                continue;
            }
            printf("\n");
            continue;
        }
        
        fotosRestantes = fotos;
        
        do{
            lado = cuadradoCercano(fotosRestantes);
            fotosRestantes -= lado*lado;
            cuadrados+=1;
            if(fotosRestantes == 0){
                break;
            }
        }while(sqrt(fotosRestantes) >= trunc(sqrt(fotosRestantes)));
        
        printf("Sophie formará %u cuadrados con %lu foto(s) :\n",cuadrados,fotos);
        
        fotosRestantes = fotos;
        
        do{
            lado = cuadradoCercano(fotosRestantes);
            fotosRestantes -= lado*lado;
            printf("Un cuadrado de lado %lu - (%lu fotos)\n",lado, lado*lado);
            if(fotosRestantes == 0){
                break;
            }
        }while(sqrt(fotosRestantes) >= trunc(sqrt(fotosRestantes)));
        
        cuadrados = 0;
        
        if(fotos<=50){
            printf("Como la cantidad de fotos es menor o igual a 50, se diagrama!\n");
            fotosRestantes = fotos;
            do{
                lado = cuadradoCercano(fotosRestantes);
                fotosRestantes -= lado*lado;
                imprimirCuadrado(lado);
                if(fotosRestantes == 0){
                    break;
                }
            }while(sqrt(fotosRestantes) >= trunc(sqrt(fotosRestantes)));
            
        printf("\n");
        }
        printf("\n");
    }
    return 0;
}

int esTriangulo(unsigned long n){
    unsigned long suma;
    int i=0;
    
    do{
        i++;
        suma = (i * (i+1))/2;
        if(suma==n){
            return i;
        }
        
    }while(suma<=n);
    
    return 0;
}

int esCuadradoPerfecto(unsigned long n){
    
    if(sqrt(n) == trunc(sqrt(n))){
        return sqrt(n);
    }
    
    return 0;
}

void imprimirTriangulo(short lado){
    short espacios, efes = 0;
    
    while(lado>0){
        espacios = lado;
        efes += 1;
        
        for(short i = 1; i<espacios ; i++){
            printf(" ");
        }
        
        for(short j = 1; j<=efes ; j++){
            printf("F ");
        }
        
        lado -= 1;
        printf("\n");
    }
}

void imprimirCuadrado(short lado){
    for(short i=1 ; i<=lado ; i++){
        for(short j=1 ; j<=lado ; j++){
            printf("F ");
        }
        printf("\n");
    }
}

int cuadradoCercano(unsigned long n){
    return trunc(sqrt(n));
}