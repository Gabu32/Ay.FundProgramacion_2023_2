#include <stdio.h>
#include <math.h>

int esOblongo(long);
void reporte(int, int);

int main(){
    long num;
    int oblongo = 0, noOblongo = 0;
    
    while(1){
        scanf("%ld", &num);
        
        if(num <= 0){
            reporte(oblongo, noOblongo);
            return 0;
        }
        
        if (esOblongo(num)) oblongo++;
        else noOblongo++;
    }
}

int esOblongo(long num){
    long i, raizTruncada;
    
    raizTruncada = trunc(sqrt(num));
    
    for(i = 1 ; i < raizTruncada + 1 ; i++){
        if(i * (i+1) == num){
            printf("%ld ES OBLONGO.\n", num);
            printf("%ld y %ld SON LOS NUMEROS QUE HACEN QUE CUMPLA LA PROPIEDAD\n\n", i, i+1);
            return 1;
        }
    }

    printf("%ld NO ES OBLONGO.\n\n", num);
    return 0;
}

void reporte(int oblongo, int noOblongo){
    printf("=======================================\n");
    printf("             REPORTE FINAL\n");
    printf("=======================================\n");
    printf("SE PROCESARON %d NUMERO(S).\n", oblongo + noOblongo);
    printf("CANTIDAD DE OBLONGOS PROCESADOS = %d\n", oblongo);
    printf("CANTIDAD DE NO OBLONGOS PROCESADOS = %d\n", noOblongo);
    
}
