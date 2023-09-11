#include <stdio.h>
#include <math.h>

int esPrimo(unsigned long long);
int esPalindromo(unsigned long long);
unsigned long long invertirNum(unsigned long long);
int proceso(unsigned long long, int);

int main(){
    unsigned long long num;
    int i = 0, omirp = 0;
    
    while(1){
        scanf("%llu", &num);
        if(num == 0) break;
        
        omirp += proceso(num, i + 1);
        i++;
    }
    
    if(i == 0){
        printf("NO SE INGRESARON DATOS PARA PROCESAR.");
        return 0;
    }
    
    if(omirp == 0){
        printf("NO SE INGRESO NINGUN NUMERO OMIR.");
        return 0;
    }
    
    printf("EL %.2lf%% DE LOS NÚMEROS INGRESADOS ERAN OMIRP.", (omirp/(i/1.0))*100);
    
    return 0;
}

int esPrimo(unsigned long long num){
    unsigned long long raizTruncada = trunc(sqrt(num));
    
    if(num == 1 || num == 0) return 0;
    
    for(int i = 2 ; i<raizTruncada+1 ; i++){
        if(num%i == 0) return 0;
    }
    
    return 1;
}

unsigned long long invertirNum(unsigned long long num){
    unsigned long long inverso = 0;
    
    while(num > 0){
        inverso = inverso*10 + num % 10;
        num /= 10;
    }
    
    return inverso;
}

int esPalindromo(unsigned long long num){
    unsigned long long inverso = invertirNum(num);
    
    return inverso == num;
}

int proceso(unsigned long long num, int i){
    unsigned long long numReves;
    
    printf("CASO DE PRUEBA #%d\n", i);
    printf("========================\n");
    
    if(esPrimo(num)){
        printf("%llu ES PRIMO.\n", num);
        
        if(!esPalindromo(num)){
            printf("%llu NO ES PALINDROMO.\n", num);
            
            numReves = invertirNum(num);
            printf("EL NUMERO ESCRITO AL REVES ES %llu.\n", numReves);
            
            if(esPrimo(numReves)){
                printf("%llu TAMBIEN ES PRIMO.\n", numReves);
                printf("EN CONSECUENCIA %llu ES OMIRP.\n\n", num);
                
                return 1;
            } 
            
            else{
                printf("%llu NO ES PRIMO.\n", numReves);
                printf("EN CONSECUENCIA %llu NO ES OMIRP.\n\n", num);
                
                return 0;
            } 
            
        } else printf("%llu ES PALINDROMO.\n", num);
        
    } else printf("%llu NO ES PRIMO.\n", num);
    
    
    printf("EN CONSECUENCIA NO ES OMIRP.\n\n");
    return 0;
    
}