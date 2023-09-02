#include <stdio.h>
#include <math.h>

int main(){
    char color;
    int edad;
    double peso, largoCola, largoBigotes, puntaje;
    
    scanf("%c", &color);
    scanf("%i %lf %lf %lf", &edad, &peso, &largoCola, &largoBigotes);
    
    switch(color){
        case 'a':
                puntaje = (peso*largoBigotes) / sqrt(edad);
                break;
        case 'n':
                puntaje = pow(1.0/edad, 2) * largoCola * (peso + largoBigotes);
                break;
        case 'b':
                puntaje = edad * (largoCola/100) * peso;
                break;
        case 'g':
                puntaje = largoBigotes * log2(edad);
                break;
        default:
                puntaje = 0;
                break;
    }
    
    if (puntaje == 0)
        printf("meperd0n as? el color de gato seleccionado no existe :c");
        
    else{
        printf("%.1lf puntos gato truco, ", puntaje);
        
        if (puntaje < 2.5) printf("no ha sido muy impresionante la verdad");
            
        else if (puntaje < 4.5) printf("un buen truco sinceramente");
                
        else if (puntaje < 7.5) printf("impaktado");
                
        else printf("EPIC VICTORY ROYALE");
    }
    
    return 0;
}