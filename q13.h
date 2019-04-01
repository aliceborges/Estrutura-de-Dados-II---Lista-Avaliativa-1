#define q13_h
#include "library.h"

//QUESTÃO 13
// Utilizando o algoritmo shellsort visto em aula, implemente‐o em C para que ordene 
// em ordem crescente e obtenha o número de comparações e movimentações para o 
// seguinte vetor: 45,56,12,43,95,19,8,67 

// Utilizada a mesma da questão 6
void shellSortQ13(int n, int* v){
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
            while (v[j-h] > aux){
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

int q13(){
    int i, array_desordenadoq9[8] = {45,56,12,43,95,19,8,67};
    printf("===========================================\n");
    printf("QUESTÃO 13\n");
    
    shellSortQ13(8, array_desordenadoq9);
    printf("Array Ordenado: \n");
    for (i = 0; i < 8; i++){
        printf("%d  ", array_desordenadoq9[i]);
    }
    printf("\n");
    printf("===========================================\n");
}