#include <stdio.h>
#include <math.h>

int validarNum();
void proceso(int);
void desglose(int);

int main(){
    int cant;
    
    cant = validarNum();
    
    proceso(cant);
    
    return 0;
}

int validarNum(){
    int num;
    
    while(1){
        scanf("%i", &num);
        if(num >= 1 && num <= 100) return num;        
    }
    
}

void proceso(int cant){
    int i, costo, pago, vuelto;
    float totalRecaudado = 0;
    
    for(i = 1 ; i < cant+1 ; i++){
        scanf("%d %d", &costo, &pago);
        
        printf("---------------------------------------\n");
        printf("Cliente #%i\n",i);
        printf("Costo de la compra = $%i\n", costo);
        printf("Dinero entregado por el cliente = $%i\n", pago);
        
        
         
        if(costo > pago){
            printf("DEBE $%d\n\n", costo - pago);
            totalRecaudado += pago;
            continue;
        }
        
        totalRecaudado += costo;
        vuelto = pago - costo;
        
        printf("Vuelto = $%d\n", vuelto);
        
        if(vuelto == 0){
            printf("PAGO EXACTO.\n\n");
            continue;
        }
        
        desglose(vuelto);
        
        printf("\n");
    }
    
    printf("\nTOTAL DINERO EFECTIVO RECAUDADO = $%.2f", totalRecaudado);
    
}

void desglose(int vuelto){
    int cant500 = 0, cant100 = 0, cant50 = 0, cant10 = 0, cant5 = 0, cant1 = 0;
    
    while(vuelto > 0){
        if(vuelto >= 500){
            cant500 += 1;
            vuelto -= 500;
        }
        
        else if(vuelto >= 100){
            cant100 += 1;
            vuelto -= 100;
        }
        
        else if(vuelto >= 50){
            cant50 += 1;
            vuelto -= 50;
        }
        
        else if(vuelto >= 10){
            cant10 += 1;
            vuelto -= 10;
        }
        
        else if(vuelto >= 5){
            cant5 += 1;
            vuelto -= 5;
        }
        
        else{
            cant1 += 1;
            vuelto -= 1;
        }
    }
    
    printf("DESGLOSE\n");
    
    printf("%d Moneda(s) de $500\n", cant500);
    printf("%d Moneda(s) de $100\n", cant100);
    printf("%d Moneda(s) de $50\n", cant50);
    printf("%d Moneda(s) de $10\n", cant10);
    printf("%d Moneda(s) de $5\n", cant5);
    printf("%d Moneda(s) de $1\n",cant1);
    
}