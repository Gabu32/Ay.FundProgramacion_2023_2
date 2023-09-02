#include <stdio.h>
#include <math.h>

int largo(long);
int esAutomorfico(long);
void reporte(int, int);

int main(){
    long num;
    int total = 0, automorficos = 0;
    
    while(1){
        scanf("%ld", &num);
        
        if(num == 0){
            reporte(total, automorficos);
            return 0;
        }
        
        total++;
        
        if(esAutomorfico(num)){
            printf("%ld SI es realmente AUTOMORFICO\n", num);
            automorficos++;
        }
        
        else{
            printf("%ld NO es realmente AUTOMORFICO\n", num);
        }
    }
}

int largo(long num){
    int cont = 0;
    
    while (num > 0){
        cont++;
        num /= 10;
    }
    
    return cont;
}

int esAutomorfico(long num){
    long potencia, corte;
    int largoNum;
    
    potencia = num*num;
    largoNum = largo(num);
    corte = pow(10, largoNum);
    
    while(potencia > 0){
        if(potencia%corte == num) return 1;
        
        potencia /= 10;
    }
    return 0;
}

void reporte(int total, int automorficos){
    double porcentaje;
    
    if (total == 0){
        printf("NO SE PROCESARON DATOS.");
    }
    
    else{
        porcentaje = (automorficos / (float)total) * 100;
        printf("\nEl %.2lf%% de los números procesados eran Realmente AUTOMORFICOS.", porcentaje);
    }
}