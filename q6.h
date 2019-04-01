#define q6_h
#include "library.h"

//QUESTÃO 6
//Refaça os algoritmos visto em aula, colocando estruturas para medir o tempo, a 
//quantidade de comparações e a quantidade de trocas efetuadas. 

// BUBBLE SORT

int trocamerge = 0, comparamerge = 0;
int trocaheap = 0, comparaheap = 0;
int trocaquick = 0, comparaquick = 0;
clock_t tInicioHeap, tFimHeap;
double tDecorridoHeap = 0;
clock_t tInicioQuick, tFimQuick;
double tDecorridoQuick = 0;

int testaArray(int* v, int n){
    int bla;
    for (bla = 0; bla <= n; bla++){
        printf("%d\n", v[bla]);
    }
}

void bubbleSort(int n, int* v){
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

void insertSort(int n, int* v){
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

// SELECT SORT

void selectSort (int n, int* v) {
    clock_t tInicio, tFim;
    double tDecorrido;
    int i, j, min, aux, troca = 0, comparacoes = 0;
  
    tInicio = clock();
    for (i = 0; i < (n - 1); i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            comparacoes += 1;
            if (v[j] < v[min]) {
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

    printf("Tempo decorrido: %lf s \n", tDecorrido);
    printf("Comparações: %d \n", comparacoes);
    printf("Trocas: %d \n", troca);
}

// SHELL SORT

void shellSort(int n, int* v){
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

// QUICK SORT

int partition(int* v, int inicio, int fim){
    int x, i, j, auxiliar;
    x = v[inicio];
    i = inicio - 1;
    j = fim + 1;

    for(;;){
        do {j--; comparaquick+=1;} while (v[j] > x);
        do {i++; comparaquick+=1;} while (v[i] < x);

        if(i<j){
            trocaquick+=1;
            auxiliar = v[i];
            v[i] = v[j];
            v[j] = auxiliar;
        }
        else{
            return j;
        }
    }
}

void quickSort(int* v, int inicio, int fim){
    int pivot;
    if (inicio<fim){
        pivot = partition(v, inicio, fim);
        quickSort(v, inicio, pivot);
        quickSort(v, pivot+1, fim);
    }
    else
    {
        return;
    }
}

// HEAP SORT

void criaheap(int* v, int inicio, int final){
    int aux = v[inicio];
    int filho = inicio * 2 + 1;

    while(filho <= final){
        comparaheap += 1;
        if (filho < final){
            comparaheap += 1;
            if (v[filho] < v[filho+1]){
                filho = filho + 1;
            }
        }

        comparaheap += 1;
        if (aux < v[filho]){
            trocaheap+=1;
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

void heapSort(int n, int* v){
    int i, aux, troca = 0, comparacoes = 0;

    for (i = (n-1)/2; i>=0; i--){
        criaheap(v, i, n-1);
    }
    for (i = n-1; i>=1; i--){
        troca += 1;
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        criaheap(v, 0, i-1);
    }
}

// MERGE SORT

void merge(int* v, int l, int m, int r){ 
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
        comparamerge += 1;
        if (L[i] <= R[j]){ 
            v[k] = L[i];
            trocamerge += 1; 
            i++; 
        } 
        else{ 
            v[k] = R[j]; 
            trocamerge += 1;
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1){ 
        comparamerge += 1;
        v[k] = L[i]; 
        trocamerge += 1;
        i++; 
        k++; 
    } 
  
    while (j < n2){ 
        comparamerge += 1;
        v[k] = R[j]; 
        j++; 
        k++; 
        trocamerge += 1;
    } 
} 
  
void mergeSort(int* v, int l, int r){ 
    if (l < r){ 
        int m = l+(r-l)/2; 
        mergeSort(v, l, m); 
        mergeSort(v, m+1, r); 
        merge(v, l, m, r); 
    }
} 

int q6(){
    int array_desordenado61[20], array_desordenado62[20], array_desordenado63[20], array_desordenado64[20], array_desordenado65[20], array_desordenado66[20], array_desordenado67[20], i6;
    for(i6 = 0; i6 <= 19; i6++){
        array_desordenado61[i6], array_desordenado62[i6], array_desordenado63[i6], array_desordenado64[i6], array_desordenado65[i6], array_desordenado66[i6], array_desordenado67[i6] = rand() % 100;
    }
    
    printf("QUESTÃO 6\n");
    printf("Foi feito um array ramdômico de 20 posições.\n\n");
    
    printf("BUBBLE SORT\n");
    bubbleSort(20, array_desordenado61);
    printf("\n");

    printf("INSERT SORT\n");
    insertSort(20, array_desordenado62);
    printf("\n");

    printf("SELECT SORT\n");
    selectSort(20, array_desordenado63);
    printf("\n");

    printf("SHELL SORT\n");
    shellSort(20, array_desordenado64);
    printf("\n");

    printf("QUICK SORT\n");
    tInicioQuick = clock();
    quickSort(array_desordenado65, 0, 19);
    tFimQuick = clock();
    tDecorridoQuick = (((double)(tFimQuick - tInicioQuick))/ (CLOCKS_PER_SEC / 1000));
    printf("Tempo decorrido: %lf s \n", tDecorridoQuick);
    printf("Comparações: %d \n", comparaquick);
    printf("Trocas: %d \n", trocaquick);
    printf("\n");
    printf("\n");

    printf("HEAP SORT\n");
    tInicioHeap = clock();
    heapSort(20, array_desordenado66);
    tFimHeap = clock();
    tDecorridoHeap = (((double)(tFimHeap - tInicioHeap))/ (CLOCKS_PER_SEC / 1000));
    printf("Tempo decorrido: %lf s \n", tDecorridoHeap);
    printf("Comparações: %d \n", comparaheap);
    printf("Trocas: %d \n", trocaheap);
    printf("\n");
    
    printf("MERGE SORT\n");
    mergeSort(array_desordenado67, 0, 19);
    printf("Comparações: %d \n", comparamerge);
    printf("Trocas: %d \n", trocamerge);
    printf("\n");

    printf("===========================================\n\n");
}
