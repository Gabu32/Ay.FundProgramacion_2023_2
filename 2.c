#include <stdio.h>

int numeros[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void leerSudoku(int[][9]);
int esValido(int[][9]);
int contar(int[][9], int);

int main(){
    int n, i;
    int sudoku[9][9];
    
    scanf("%d", &n);
    
    for(i = 0 ; i<n ; i++){
        leerSudoku(sudoku);
        
        printf("Sudoku #%d --> ", i+1);
        
        if(esValido(sudoku)) printf("SI\n");
        
        else printf("NO\n");
        
    }
    
    return 0;
}

void leerSudoku(int sudoku[][9]){
    int i, j;
    
    for(i = 0 ; i<9 ; i++){
        for(j = 0 ; j<9 ; j++){
            scanf("%d", &(sudoku[i][j]));
        }
    }
}

int esValido(int sudoku[][9]){
    int i, cont;
    
    for(i = 0 ; i<9 ; i++){
        cont = contar(sudoku, numeros[i]);
        
        if(cont == 0) return 0;
    }
    
    return 1;
}

int contar(int sudoku[][9], int num){
    int i, j;
    int cont = 0;
    
    for(i = 0 ; i<9 ; i++){
        for(j = 0 ; j<9 ; j++){
            if(sudoku[i][j] == num) cont++;
            if(sudoku[j][i] == num) cont++;
            
            //printf("%d %d %d  ", sudoku[i][j], sudoku[j][i], cont);
            
            if(cont > 2) return 0;
        }
        cont = 0;
    }
    
    return 1;
}
