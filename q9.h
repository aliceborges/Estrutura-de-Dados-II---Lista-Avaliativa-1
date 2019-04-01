#include "library.h"

// QUESTÃO 9
// Usando o algoritmo visto em aula, faça linguagem C, faça o InsertionSort para ordenar 
// em ordem decrescente

void insertSortDesc(int n, int* v){
    int i, key, j;

    for (i = 1; i < n; i++) { 
        key = v[i]; 
        j = i - 1; 
        while (j >= 0 && v[j] < key) { 
            v[j + 1] = v[j]; 
            j = j - 1; 
        } 
        v[j + 1] = key; 
    } 
}

int q9(){
    int array_desordenadoq9[20], iq9;
    printf("===========================================\n");
    printf("QUESTÃO 9\n");
    printf("Array Desordenado: \n");
    for(iq9 = 0; iq9 <= 19; iq9++){
        array_desordenadoq9[iq9] = rand() % 100;
        printf("%d  ", array_desordenadoq9[iq9]);
    }

    insertSortDesc(20, array_desordenadoq9);

    int iq92;
    printf("\nArray Ordenado InsertSort Desc: \n");
    for (iq92 = 0; iq92 <= 19; iq92++){
        printf("%d  ", array_desordenadoq9[iq92]);
    }
    printf("\n");
    printf("===========================================\n");
}
