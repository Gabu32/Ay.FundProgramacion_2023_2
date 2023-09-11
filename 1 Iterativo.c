//solucion iterativa

double factorial(int n){
    int i;
    double fact = 1;
    
    for(i = 1; i <= n ; i++){
        fact *= i;
    }
    
    return fact;
}

double potencia(double x, int n){
    int i;
    double resultado = 1;
    
    for(i = 0 ; i < n ; i++){
        resultado *= x;
    }
    
    return resultado;
}

double omega(double x, int n){
    int i;
    double suma = 0;
    
    for(i = 1 ; i<=n ; i+=2){
        suma += potencia(x, i)/factorial(i);
    }
    return suma;
}
