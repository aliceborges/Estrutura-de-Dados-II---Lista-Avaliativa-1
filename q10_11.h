#define q10_11_h
#include "library.h"

// QUESTÃO 10
// Usando o algoritmo visto em aula, faça linguagem C o algoritmo do Selectsort 
// lterando‐o para que funcione ao contrário (i.e., que resulte em números ordenados do 
// maior para o menor).  

void selectSortDesc (int n, int* v) {
    clock_t tInicio, tFim;
    double tDecorrido;
    int i, j, min, aux, troca = 0, comparacoes = 0;
  
    tInicio = clock();
    for (i = 0; i < (n - 1); i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            comparacoes += 1;
            if (v[j] > v[min]) {
                min = j;
            }
        }

        if (i != min) {
            troca += 1;
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }
    }
    tFim = clock();
    tDecorrido = (((double)(tFim - tInicio))/ (CLOCKS_PER_SEC / 1000));

    printf("\nTempo decorrido: %lf s \n", tDecorrido);
    printf("Comparações: %d \n", comparacoes);
    printf("Trocas: %d \n", troca);
}

int q10_11(){
    int array_desordenadoq10[20], iq10;
    printf("===========================================\n");
    printf("QUESTÃO 10\n");
    printf("Array Desordenado: \n");
    for(iq10 = 0; iq10 <= 19; iq10++){
        array_desordenadoq10[iq10] = rand() % 100;
        printf("%d  ", array_desordenadoq10[iq10]);
    }

    selectSortDesc(20, array_desordenadoq10);

    int iq102;
    printf("\nArray Ordenado Select Sort Desc: \n");
    for (iq102 = 0; iq102 <= 19; iq102++){
        printf("%d  ", array_desordenadoq10[iq102]);
    }
    printf("\n");
    printf("===========================================\n");

    // QUESTÃO 11
    // Se duplicar o tamanho do vetor, o tempo que leva ao Selectsort ordenar também 
    // duplica? 
    int array_desordenadoq11[40], iq11;
    printf("===========================================\n");
    printf("QUESTÃO 11\n");
    printf("Array Desordenado: \n");
    for(iq11 = 0; iq11 <= 39; iq11++){
        array_desordenadoq11[iq11] = rand() % 100;
        printf("%d  ", array_desordenadoq11[iq11]);
    }

    selectSortDesc(40, array_desordenadoq10);
}