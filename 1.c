typedef struct {
    char palabra[41]; 
    int frecuencia;
} PalabraFrecuencia;

void agregarPalabra(PalabraFrecuencia **vector, int *tamano, char *palabra);
int cmp(const void*, const void*);
void escribirArchivoSalida(FILE *salida, PalabraFrecuencia *vector, int tamano);

void mostrarPalabrasFrecuencia(FILE *entrada, FILE **salida) {
    PalabraFrecuencia *vector = NULL;
    int tamano = 0;

    char palabra[41]; 

    while (fscanf(entrada, "%40s", palabra) == 1) {
        int i, noAgregar = 0;
        
        for(i = 0; palabra[i]; i++){
            if (!isalpha(palabra[i])){
                noAgregar = 1;
                break;
            }
            
            palabra[i] = tolower(palabra[i]);
        }
        
        if(noAgregar){
            noAgregar = 0;
            continue;
        }
        agregarPalabra(&vector, &tamano, palabra);
    }
    
    qsort(vector, tamano, sizeof(PalabraFrecuencia), cmp);
    escribirArchivoSalida(*salida, vector, tamano);
    free(vector);

    fclose(entrada);
    fclose(*salida);
}

void agregarPalabra(PalabraFrecuencia **vector, int *tamano, char *palabra) {
    int i;
    
    for (i = 0; i < *tamano; i++) {
        if (strcmp((*vector)[i].palabra, palabra) == 0) {
            (*vector)[i].frecuencia++;
            return;
        }
    }

    (*tamano)++;
    *vector = realloc(*vector, (*tamano) * sizeof(PalabraFrecuencia));
    if (*vector == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(EXIT_FAILURE);
    }

    strcpy((*vector)[*tamano - 1].palabra, palabra);
    (*vector)[*tamano - 1].frecuencia = 1;
}

void escribirArchivoSalida(FILE *salida, PalabraFrecuencia *vector, int tamano) {
    for (int i = 0; i < tamano; i++) {
        fprintf(salida, "%s %d\n", vector[i].palabra, vector[i].frecuencia);
    }
}

int cmp(const void *ptr1, const void *ptr2){
    PalabraFrecuencia *ele1 = (PalabraFrecuencia*)ptr1;
    PalabraFrecuencia *ele2 = (PalabraFrecuencia*)ptr2;
    
    return (strcmp(ele1->palabra, ele2->palabra));
    
}
