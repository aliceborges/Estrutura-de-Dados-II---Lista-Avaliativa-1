#include "library.h"
#include "utils.h"
#include "questions.h"

// 1ª LISTA PRÁTICA
// Aluno(s): Alice Borges

// QUESTÃO 1
// Faça, utilizando linguagem C, uma função recursiva que calcule o valor da série S
// descrita a seguir para um valor n > 0 a ser fornecido como parâmetro para a mesma.

// S = 2 + 5/2 + 10/3 + [...] + (1+n²)/n

float calculaSerieS(float n){
    if(n>0){
        return ((1 + n*n) / n) + calculaSerieS(n - 1);
    }  
    else{
        return 0;
    }
}

// QUESTÃO 2
// Faça, utilizando a linguagem C, uma função recursiva que eleve qualquer número x
// a uma potência inteira N, sendo x e n pertencentes obrigatoriamente aos naturais.

float calculaPotencia(float x, float n){

    float resultado, temp;

    if(n >= 0 && x >= 0){
        if (n == 0){
            resultado = 1;
        }
        else{
            temp = n - 1;
            if (temp == 0){
                resultado = x;
            }else{
                resultado = x * calculaPotencia (x, n - 1);
            }            
        }
    }

    return resultado;
}

// QUESTÃO 3
// Faça, usando linguagem C, uma função recursiva que receba um número inteiro 
// positivo N e retorne o fatorial quádruplo desse número. O fatorial quádruplo de um 
// número N é dado por (2n)!/n!

int fatorialQuadruplo(int denominador, int numerador) {
    if(denominador + 1 >= numerador){
        return denominador + 1;
    }else{
        return (denominador + 1) * fatorialQuadruplo(denominador + 1, numerador);
    }
}

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

//QUESTÃO 5
//Se duplicar o tamanho do vetor, o tempo que leva ao Bubble sort ordenar também 
//duplica? 

int main(){

    // float i1, resultado1;
    // printf("===========================================\n");
    // printf("QUESTÃO 1\n");
    // i1 = questao1();
    // resultado1 = calculaSerieS(i1);
    // printf("Resultado: %f\n", resultado1);
    // printf("===========================================\n\n");

    // float base, exponente, potencia;
    // printf("===========================================\n");
    // printf("QUESTÃO 2\n");
    // base = questao2pergunta1();
    // exponente = questao2pergunta2();
    // potencia = calculaPotencia(base, exponente);
    // printf("Resultado: %f\n", potencia);
    // printf("===========================================\n\n");

    // int fatorando;
    // float resultado3;
    // printf("===========================================\n");
    // printf("QUESTÃO 3\n");
    // fatorando = questao3();
    // resultado3 = fatorialQuadruplo(fatorando, fatorando * 2);
    // printf("Resultado: %f\n", resultado3);
    // printf("===========================================\n\n");

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
