#define q16_h
#include "library.h"

// QUESTÃO 16
// Usando o algoritmo visto em aula, faça linguagem C o algoritmo de ordenação 
// quicksort de modo que ele faça a ordenação em ordem decrescente. 

int partition16(int* v, int inicio, int fim){
    int x, i, j, auxiliar;
    x = v[inicio];
    i = inicio - 1;
    j = fim + 1;

    for(;;){
        do {j--;} while (v[j] < x);
        do {i++;} while (v[i] > x);

        if(i<j){
            auxiliar = v[i];
            v[i] = v[j];
            v[j] = auxiliar;
        }
        else{
            return j;
        }
    }
}

void quickSortDesc(int* v, int inicio, int fim){
    int pivot;
    if (inicio<fim){
        pivot = partition16(v, inicio, fim);
        quickSortDesc(v, inicio, pivot);
        quickSortDesc(v, pivot+1, fim);
    }
    else
    {
        return;
    }
}

int q16(){
    int array_desordenadoq16[20], i16;
    printf("===========================================\n");
    printf("QUESTÃO 16\n");
    printf("Array Desordenado: \n");
    for(i16 = 0; i16 <= 19; i16++){
        array_desordenadoq16[i16] = rand() % 100;
        printf("%d  ", array_desordenadoq16[i16]);
    }

    quickSortDesc(array_desordenadoq16, 0, 19);

    int i161;
    printf("\nArray Ordenado Quick Sort Desc: \n");
    for (i161 = 0; i161 <= 19; i161++){
        printf("%d  ", array_desordenadoq16[i161]);
    }
    printf("\n");
    printf("===========================================\n");
}