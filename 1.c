int seEncuentra(datosNino *arr, int tam, int codigo){
    int i;
    
    for(i = 0 ; i<tam ; i++){
        if(arr[i].codigoNino == codigo){
            return 1;
        }
    }
    
    return 0;
}


datosNino *poblar(int *tam){
    datosNino *arr = NULL;
    int codigo, comportamiento, peso;
    
    while(1){
        scanf("%d", &codigo);
        if(codigo == 0) return arr;
        
        scanf("%d %d", &comportamiento, &peso);
        
        if(!seEncuentra(arr, *tam, codigo)){
            if(*tam == 0) arr = (datosNino*) malloc(sizeof(datosNino));    
            
            else arr = (datosNino*) realloc(arr, sizeof(datosNino) * ((*tam)+1));
            
            arr[*tam].codigoNino = codigo;
            arr[*tam].comportamiento = comportamiento;
            arr[*tam].pesoRegalos = peso;
            
            *tam = *tam + 1;
        }
    }
}

void mostrar(datosNino *arr, int total){
    int i;
    
    for(i = 0 ; i<total ; i++){
        printf("| %8d | %16d | %6d |\n", arr[i].codigoNino, arr[i].comportamiento, arr[i].pesoRegalos);
    }
    printf(" --------------------------------------\n");
}

int comparar(const void *ptrA, const void *ptrB){
    datosNino *ele1 = (datosNino*)ptrA;
    datosNino *ele2 = (datosNino*)ptrB;
    
    if(ele1->comportamiento > ele2->comportamiento) return 0;
    if(ele1->comportamiento < ele2->comportamiento) return 1;
    
    return (ele1->pesoRegalos - ele2->pesoRegalos);
}
