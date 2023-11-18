#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void proceso(int);
void contarLetras(char*, int*);

int main(){
    int n;
    
    scanf("%d", &n);
    
    proceso(n);
    
    return 0;
}

void proceso(int n){
    int i;
    char string[26];
    int letras[4] = {0, 0, 0, 0}; //{A, C, G, T}
        
    printf("         CADENA ADN        #A   #C   #G   #T\n");
    printf("=============================================\n");
    for(i = 0 ; i<n ; i++){
        scanf("%s", string);
        
        contarLetras(string, letras);
        
        printf("%25s %3d %4d %4d %4d\n", string, letras[0], letras[1], letras[2], letras[3]);
        
        letras[0] = 0;
        letras[1] = 0;
        letras[2] = 0;
        letras[3] = 0;
    }
    
}

void contarLetras(char *string, int *arr){
    int i = 0;
    
    while(string[i] != '\0'){
        if(string[i] == 'A' || string[i] == 'a'){
            arr[0] += 1;
        }
        
        if(string[i] == 'C' || string[i] == 'c'){
            arr[1] += 1;
        }
        
        if(string[i] == 'G' || string[i] == 'g'){
            arr[2] += 1;
        }
        
        if(string[i] == 'T' || string[i] == 't'){
            arr[3] += 1;
        }
        
        i++;
    }
}
