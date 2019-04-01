#define q8_h
#include "library.h"

void bubbleSortQ8(int n, int* v){
    clock_t tInicio, tFim;
    double tDecorrido;
    int fim, i, troca = 0, comparacoes = 0, lengh = n;
    
    tInicio = clock();
    for (fim = n-1; fim > 0; fim--){
        for (i = 0; i<fim; i++){
            comparacoes+=1;
            if(v[i]>v[i+1]){
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp; 
                troca += 1;
            }
        }
    }
    tFim = clock();
    tDecorrido = (((double)(tFim - tInicio))/ (CLOCKS_PER_SEC / 1000));
    
    printf("Tempo decorrido: %lf s \n", tDecorrido);
    printf("Comparações: %d \n", comparacoes);
    printf("Trocas: %d \n", troca);
}

// INSERT SORT

void insertSortQ8(int n, int* v){
    clock_t tInicio, tFim;
    double tDecorrido;
    int i, key, j, troca = 0, comparacoes = 0;

    tInicio = clock();
    for (i = 1; i < n; i++) { 
        key = v[i]; 
        j = i - 1; 
        comparacoes += 1;
        while (j >= 0 && v[j] > key) { 
            v[j + 1] = v[j]; 
            j = j - 1; 
            troca += 1;
        } 
        v[j + 1] = key; 
    } 
    tFim = clock();
    tDecorrido = (((double)(tFim - tInicio))/ (CLOCKS_PER_SEC / 1000));

    printf("Tempo decorrido: %lf s \n", tDecorrido);
    printf("Comparações: %d \n", comparacoes);
    printf("Trocas: %d \n", troca);
} 

// QUESTÃO 8
// Comparar o número de trocas e comparações num vetor ordenado usando o algoritmo 
// InsertSort e o algoritmo e o BubbleSort

int q8(){
    int array_ordenado[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("===========================================\n");
    printf("QUESTÃO 8\n");
    printf("Bubble Sort: \n");
    bubbleSortQ8(10, array_ordenado);
    printf("\nInsert Sort: \n");
    insertSortQ8(10, array_ordenado);
    printf("\n");
    printf("===========================================\n");
}

