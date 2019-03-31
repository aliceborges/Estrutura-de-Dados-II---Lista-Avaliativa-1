#define q1_h
#include "library.h"

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

int q1(){
    float i1, resultado1;
    printf("===========================================\n");
    printf("QUESTÃO 1\n");
    printf("Digite um número maior que 0 para exibir a somatória: ");
    scanf("%f", &i1);
    resultado1 = calculaSerieS(i1);
    printf("Resultado: %f\n", resultado1);
    printf("===========================================\n\n");
}
