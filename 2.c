#include <stdio.h>
#include <math.h>

int main(){
    int year;
    double poderPelea, fuerza, voluntad, debilidad;
    double agilidad, espiritu;
    
    scanf("%d", &year);
    scanf("%lf %lf %lf %lf", &poderPelea, &fuerza, &voluntad, &debilidad);
    
    espiritu = exp(voluntad/debilidad);
    
    agilidad = 4*(pow(poderPelea/pow(year,2),2) - fuerza/2 - espiritu);
    
    printf("La agilidad que Koku debe alcanzar para enfrentar a los zayayines es %.2lf", agilidad);
    
    return 0;
}