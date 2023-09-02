#include <stdio.h>

int main(){
    double densidad;
    double volumen;
    double masa;
    
    scanf("%lf", &densidad);
    scanf("%lf", &volumen);
    
    masa = densidad*volumen*0.001;
    
    printf("La masa en Kgs de %.2lf litros de la sustancia con densidad %.2lf [kg/m^3] es %.2lf", volumen, densidad, masa);
    
    return 0;
}