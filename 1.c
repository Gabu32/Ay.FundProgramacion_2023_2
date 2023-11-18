#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

struct Envio{
    short veredicto;
    short nEnvio;
};

struct Estudiante{
    int rut;
    struct Envio problema1;
    struct Envio problema2;
};

void leerDatos(struct Estudiante [], int*);
int buscarRut(struct Estudiante [], int, int);
void agregarEstudiante(struct Estudiante [], int, int);
void mostrarEstudiantes(struct Estudiante [], int);
int cmp(const void*, const void*);
void imprimirRuts(struct Estudiante [], int);

int main(){
    int largo;
    struct Estudiante arrEstudiantes[MAX];
    
    leerDatos(arrEstudiantes, &largo);
    
    qsort(arrEstudiantes, largo, sizeof(struct Estudiante), cmp);    
    
    mostrarEstudiantes(arrEstudiantes, largo);
    
    return 0;
}

void leerDatos(struct Estudiante arr[], int *tam){
    int rut, indice;
    short nEnvio, veredicto;
    short cambio = 0;
    
    while(1){
        scanf("%d", &rut);
        
        if(rut == -1){
            if(cambio == 0){
                cambio = 1;
                continue;
            }
            break;
        }
        
        scanf("%hi", &nEnvio);
        scanf("%hi", &veredicto);
        
        indice = buscarRut(arr, *tam, rut);
        
        if(indice < 0){
            agregarEstudiante(arr, *tam, rut);

            if(cambio == 0){
                arr[*tam].problema1.nEnvio = nEnvio;
                arr[*tam].problema1.veredicto = veredicto;
            }
            
            else{
                arr[*tam].problema2.nEnvio = nEnvio;
                arr[*tam].problema2.veredicto = veredicto;
            }
            
            *tam += 1;
        }
        
        else{
            if(cambio == 0){
                if(arr[indice].problema1.veredicto == 0 || arr[indice].problema1.veredicto == -1){
                    arr[indice].problema1.nEnvio = nEnvio;
                    arr[indice].problema1.veredicto = veredicto;    
                }
            }
            
            else{
                if(arr[indice].problema2.veredicto == 0 || arr[indice].problema2.veredicto == -1){
                    arr[indice].problema2.nEnvio = nEnvio;
                    arr[indice].problema2.veredicto = veredicto;    
                }
            }  
        }
    }
}

int buscarRut(struct Estudiante arr[], int tam, int rut){
    int i;
    
    for(i = 0 ; i<tam ; i++){
        if(arr[i].rut == rut) return i;
    }
    return -1;
}

void agregarEstudiante(struct Estudiante arr[], int tam, int rut){
    arr[tam].rut = rut;
            
    arr[tam].problema1.nEnvio = -1;
    arr[tam].problema1.veredicto = -1;

    arr[tam].problema2.nEnvio = -1;
    arr[tam].problema2.veredicto = -1;
    
}

void mostrarEstudiantes(struct Estudiante arr[], int tam){
    int i, hay = 0;
    
    for(i = 0 ; i<tam ; i++){
        if(arr[i].problema1.nEnvio != -1){
            if(hay == 0){
                printf("ESTUDIANTES QUE ENVIARON SOLUCIONES AL PROBLEMA #1 ORDENADOS POR RUT\n");
                printf("RUT         No.ENVIO    VEREDICTO JUEZ\n");
                hay = 1;
            }
            printf("%d%12d%12d\n", arr[i].rut, arr[i].problema1.nEnvio, arr[i].problema1.veredicto);

        }    
    }
    
    if(hay == 0) printf("----- NO SE RECIBIERON ENVIOS DEL PROBLEMA 1 -----\n");
    hay = 0;
    
    for(i = 0 ; i<tam ; i++){
        if(arr[i].problema2.nEnvio != -1){
            if(hay == 0){
                printf("\nESTUDIANTES QUE ENVIARON SOLUCIONES AL PROBLEMA #2 ORDENADOS POR RUT\n");
                printf("RUT         No.ENVIO    VEREDICTO JUEZ\n");
                hay = 1;
            }
            printf("%d%12d%12d\n", arr[i].rut, arr[i].problema2.nEnvio, arr[i].problema2.veredicto);

        }    
    }
    
    if(hay == 0) printf("\n----- NO SE RECIBIERON ENVIOS DEL PROBLEMA 2 -----\n");
        
    imprimirRuts(arr, tam);
}

void imprimirRuts(struct Estudiante arr[], int tam){
    int i, cont = 0;
    
    printf("\nRUT ESTUDIANTES QUE ENVIARON SOLUCIONES AL PROBLEMA 1 Y NO AL 2\n");
    
    for(i = 0 ; i<tam ; i++)
        if(arr[i].problema1.nEnvio != -1 && arr[i].problema2.nEnvio == -1){
            printf("%d\n", arr[i].rut);
            cont++;
        }
    
    if(cont == 0) printf("----- LISTA DE RUT VACIA -----\n") ;   
    cont = 0;
    
    printf("\nRUT ESTUDIANTES QUE ENVIARON SOLUCIONES AL PROBLEMA 2 Y NO AL 1\n");
    
    for(i = 0 ; i<tam ; i++)
        if(arr[i].problema1.nEnvio == -1 && arr[i].problema2.nEnvio != -1){
            printf("%d\n", arr[i].rut);
            cont++;
        }
        
    if(cont == 0) printf("----- LISTA DE RUT VACIA -----\n");
    cont = 0;
    
    printf("\nRUT ESTUDIANTES QUE ENVIARON SOLUCIONES CORRECTAS EN AMBOS PROBLEMAS\n");
    
    for(i = 0 ; i<tam ; i++)
        if(arr[i].problema1.veredicto == 1 && arr[i].problema2.veredicto == 1){
            printf("%d\n", arr[i].rut);
            cont++;
        }
        
    if(cont == 0) printf("----- LISTA DE RUT VACIA -----\n");
}

int cmp(const void *ptr1, const void *ptr2){
    struct Estudiante *ele1 = (struct Estudiante *) ptr1;
    struct Estudiante *ele2 = (struct Estudiante *) ptr2;
    
    return ele1->rut - ele2->rut;
}
