#include "library.h"
#define q4_q5_h

// QUESTÃO 4
// Usando o algoritmo visto em aula, faça linguagem C o Bubble Sort invertido – Faça o 
// algoritmo do bubblesort lterando‐o para que funcione ao contrário (i.e., que resulte 
// em números ordenados do maior para o menor). 

void bolha(int n, int* v){
    int fim, i, lengh = n;
    for (fim = n-1; fim > 0; fim--){
        int troca = 0;
        for (i = 0; i<fim; i++){
            if(v[i]>v[i+1]){
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp; 
                //troca = 1;
            }
            //if (troca == 0) return;
        }
    }
    
    printf("Array Ordenado ASC: \n");
    for (i = 0; i<n; i++){
        printf("%d\n", v[i]);
    }
}

void bolha_desc(int n, int* v){
    clock_t tInicio, tFim;
    double tDecorrido;
    int fim, i, lengh = n;
    tInicio = clock();
    for (fim = n-1; fim > 0; fim--){
        int troca = 0;
        for (i = 0; i<fim; i++){
            if(v[i]<v[i+1]){ // Só é invertido o sinal aqui
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp; 
                //troca = 1;
            }
            //if (troca == 0) return;
        }
    }
    tFim = clock();

    printf("Array Ordenado DESC: \n\n");
    for (i = 0; i<n; i++){
        printf("Elemento %d: %d\n", i, v[i]);
    }

    tDecorrido = (((double)(tFim - tInicio))/ (CLOCKS_PER_SEC / 1000));
    printf("Tempo decorrido: %lf s\n", tDecorrido);
}

int q4_q5(){
    int i4, array_desordenado4[10];
    printf("QUESTÃO 4 - Bubble Sort DESC\n\n");
    printf("Array randômico:\n\n");
    for(i4 = 0; i4 <= 9; i4++){
        array_desordenado4[i4] = rand() % 100;
        printf ("Elemento %d: %d\n", i4, array_desordenado4[i4]);
    }
    printf("\n");
    bolha_desc(10, array_desordenado4);
    printf("===========================================\n\n");

    int i5, array_desordenado5[20];
    printf("QUESTÃO 5\n\n");
    printf("Array randômico:\n\n");
    for(i5 = 0; i5 <= 19; i5++){
        array_desordenado5[i5] = rand() % 100;
        printf ("Elemento %d: %d\n", i5, array_desordenado5[i5]);
    }
    printf("\n");
    bolha_desc(20, array_desordenado5);
    printf("===========================================\n\n");
}