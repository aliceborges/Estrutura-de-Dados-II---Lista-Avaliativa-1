#define q14_h
#include "library.h"

// QUESTÃO 14
// Utilizando o algoritmo shellsort visto em aula, implemente‐o em C para que ordene 
// em ordem decrescente e obtenha o número de comparações e movimentações para o 
// seguinte vetor: 8,12,19,43,45,56,67,95 

void shellSortDesc(int n, int* v){
    clock_t tInicio, tFim;
    double tDecorrido;
    int i, j, h = 1, aux, troca = 0, comparacoes = 0;

    tInicio = clock();
    do{
        h = h * 3 + 1;
    }while (h < n);

    do{
        h = (h - 1) / 3;
        for (i = h; i < n; i++){
            aux = v[i];
            j = i;
            comparacoes += 1;
            while (v[j-h] < aux){
                troca += 1;
                v[j] = v[j-h];
                j-=h;
                if (j<h)
                    break;
            }
            v[j] = aux;
        }
    }while(h>0);
    tFim = clock();
    tDecorrido = (((double)(tFim - tInicio))/ (CLOCKS_PER_SEC / 1000));

    printf("Tempo decorrido: %lf s \n", tDecorrido);
    printf("Comparações: %d \n", comparacoes);
    printf("Trocas: %d \n", troca);
}

int q14(){
    int i14, array_desordenadoq14[8] = {8,12,19,43,45,56,67,95};
    printf("===========================================\n");
    printf("QUESTÃO 14\n");
    
    shellSortDesc(8, array_desordenadoq14);
    printf("Array Ordenado: \n");
    for (i14 = 0; i14 < 8; i14++){
        printf("%d  ", array_desordenadoq14[i14]);
    }
    printf("\n");
    printf("===========================================\n");
}