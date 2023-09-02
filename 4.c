#include <stdio.h>
#include <math.h>

int main(){
    int jugadores, mvp, i;
    double kills, deaths, assists;
    double puntosMvp, puntos;
    
    while(1){
        scanf("%d", &jugadores);

        if(jugadores == 0) break;

        for(i = 0 ; i<jugadores ; i++){
            scanf("%lf %lf %lf", &kills, &deaths, &assists);
            puntos = pow(kills + assists/2, kills/(deaths+1));

            if(i == 0 || puntos > puntosMvp){
                puntosMvp = puntos;
                mvp = i;
            }
        }
        printf("EL MVP DE LA PARTIDA ES EL JUGADOR %i CON %.1lf PUNTOS\n", mvp+1, puntosMvp);
    }
    printf("---FIN---");
    
    return 0;
}