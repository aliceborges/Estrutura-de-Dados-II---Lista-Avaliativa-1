#define q20_h
#include "library.h"

// QUESTÃO 20
// Usando o algoritmo visto em aula, faça linguagem C as modificações na função de 
// ordenação MergeSort, de modo que ele faça a ordenação na ordem decrescente. 

void mergeDesc(int* v, int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = v[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = v[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    
    while (i < n1 && j < n2){ 
        if (L[i] >= R[j]){ 
            v[k] = L[i];
            i++; 
        } 
        else{ 
            v[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1){ 
        v[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2){ 
        v[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSortDesc(int* v, int l, int r){ 
    if (l < r){ 
        int m = l+(r-l)/2; 
        mergeSortDesc(v, l, m); 
        mergeSortDesc(v, m+1, r); 
        mergeDesc(v, l, m, r); 
    }
} 

int q20(){
    int array_desordenadoq20[20], i20;
    printf("===========================================\n");
    printf("QUESTÃO 20\n");
    printf("Array Desordenado: \n");
    for(i20 = 0; i20 <= 19; i20++){
        array_desordenadoq20[i20] = rand() % 100;
        printf("%d  ", array_desordenadoq20[i20]);
    }

    mergeSortDesc(array_desordenadoq20, 0, 19);

    int i201;
    printf("\nArray Ordenado Merge Sort Desc: \n");
    for (i201 = 0; i201 <= 19; i201++){
        printf("%d  ", array_desordenadoq20[i201]);
    }
    printf("\n");
    printf("===========================================\n");
}