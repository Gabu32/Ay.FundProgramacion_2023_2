//solucion recursiva

double factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}

double potencia(double x, int n){
    if(n == 0) return 1;
    return x * potencia(x, n-1);
}

double omega(double x, int n){
    if(n <= 0) return 0;
    
    if(n%2 == 0) return (potencia(x, n-1) / factorial(n-1)) + omega(x, n-1);
    
    return (potencia(x, n) / factorial(n)) + omega(x, n-2); 
}
