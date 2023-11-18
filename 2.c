#include <stdio.h>
#include <stdlib.h>

// 4 = ARBOL , 1 = SOMBRA , 0 = NADA 

void agregarArboles(int**, int);
void agregarSombra(int**, int, int);
void agregarSombraAlrededor(int**, int, int, int, int);
int contarSombra(int**, int, int);

int main(){
    int col, row, arboles, i;
    int sombras;
    int **arr;
    
    while(1){
        scanf("%d %d %d", &row, &col, &arboles);
        
        if(arboles == 0){
            if(col == 0 && row == 0) return 0;
        }
        
        arr = (int**) calloc(row, sizeof(int*));
        if(arr == NULL) return EXIT_FAILURE;
        
        
        for(i = 0 ; i<row ; i++){
            arr[i] = (int *) calloc(col, sizeof(int));
            if(arr[i] == NULL) return EXIT_FAILURE;
        }
        
        agregarArboles(arr, arboles);
        agregarSombra(arr, row, col);
        
        sombras = contarSombra(arr, row, col);
        
        printf("%d tiendas de campaña disfrutarán de sombra en el camping\n", sombras);
    }
    
    return 0;
}

void agregarArboles(int **arr, int cont){
    int x, y, i;
        
    for(i = 0 ; i<cont ; i++){
        scanf("%d %d", &x, &y);
        //printf("%d %d ", x, y);
        arr[x-1][y-1] = 4;
    }
}

void agregarSombra(int **arr, int row, int col){
    int i, j;
    
    for(i = 0 ; i<row ; i++){
        for(j = 0; j<col ; j++){
            
            if(arr[i][j] == 4){
                agregarSombraAlrededor(arr, row, col, i, j);
            }
        }
    }
}

void agregarSombraAlrededor(int **arr, int row, int col, int x, int y) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int posibleX = x + i;
            int posibleY = y + j;

            if (posibleX >= 0 && posibleX < row && posibleY >= 0 && posibleY < col && arr[posibleX][posibleY] == 0) {
                arr[posibleX][posibleY] = 1;
            }
        }
    }
}

int contarSombra(int **arr, int row, int col){
    int cont = 0, i, j;
    
    for(i = 0 ; i<row ; i++){
        for(j = 0 ; j<col ; j++){
            if(arr[i][j] == 1) cont++;
        }
    }
    
    return cont;
}
