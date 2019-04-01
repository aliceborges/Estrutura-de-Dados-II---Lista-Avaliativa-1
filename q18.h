#define q18_h
#include "library.h"

// QUESTÃO 18
// Usando o algoritmo visto em aula, faça linguagem C o algoritmo de ordenação 
// heapsort de modo que ele faça a ordenação em ordem decrescente 

void criaheap18(int* v, int inicio, int final){
    int aux = v[inicio];
    int filho = inicio * 2 + 1;

    while(filho <= final){
        if (filho < final){
            if (v[filho] > v[filho+1]){
                filho = filho + 1;
            }
        }

        if (aux > v[filho]){
            v[inicio] = v[filho];
            inicio = filho;
            filho = 2* inicio + 1;
        }
        else{
            filho = final + 1;
        }
    }
    v[inicio] = aux;
}

void heapSortDesc(int n, int* v){
    int i, aux, troca = 0, comparacoes = 0;

    for (i = (n-1)/2; i>=0; i--){
        criaheap18(v, i, n-1);
    }
    for (i = n-1; i>=1; i--){
        troca += 1;
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        criaheap18(v, 0, i-1);
    }
}

int q18(){
    int array_desordenadoq17[20], i17;
    printf("===========================================\n");
    printf("QUESTÃO 18\n");
    printf("Array Desordenado: \n");
    for(i17 = 0; i17 <= 19; i17++){
        array_desordenadoq17[i17] = rand() % 100;
        printf("%d  ", array_desordenadoq17[i17]);
    }

    heapSortDesc(20, array_desordenadoq17);

    int i171;
    printf("\nArray Ordenado Heap Sort Desc: \n");
    for (i171 = 0; i171 <= 19; i171++){
        printf("%d  ", array_desordenadoq17[i171]);
    }
    printf("\n");
    printf("===========================================\n");
}