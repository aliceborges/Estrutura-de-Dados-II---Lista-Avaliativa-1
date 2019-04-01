#define q7_h
#include "library.h"

// QUESTÃO 7
// Refaça o algoritmo Bubblesort excluindo do resultado final os elementos repetidos do 
// vetor. 

void bubbleSortSemRepeticao(int n, int* v){
    int fim, i;
    int novoVetor[15];

    for (fim = n-1; fim > 0; fim--){
        for (i = 0; i<fim; i++){
            if(v[i]>v[i+1]){
                if (v[i-1] == v[i])
                    v[i]--;
                else{
                    int temp = v[i];
                    v[i] = v[i+1];
                    v[i+1] = temp; 
                }
            }
        }
    }
}

int q7(){
    int array_com_repeticoes[15] = {6, 10, 9, 10, 6, 25, 90, 8, 3, 15, 54, 12, 13, 29, 44};
    int i;
    printf("===========================================\n");
    printf("QUESTÃO 7\n");
    printf("Já utilizei um array pré-definido, pois preciso ter números repetidos a fim de validação.\n");
    printf("Array sem ordenação: \n");
    for(i = 0; i <= 14; i++){
        printf("%d  ", array_com_repeticoes[i]);
    }
    bubbleSortSemRepeticao(15, array_com_repeticoes);
    
    printf("\nArray com ordenação Bubble Sort e sem repetições: \n");
    for (i = 0; i <= 14; i++){
        printf("%d  ", array_com_repeticoes[i]);
    }
    printf("\n");
    printf("===========================================\n");
}