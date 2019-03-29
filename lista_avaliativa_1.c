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

int main(){

    float i, resultado;
    printf("===========================================\n");
    printf("QUESTÃO 1\n");
    i = questao1();
    resultado = calculaSerieS(i);
    printf("Resultado: %f\n", resultado);
    printf("===========================================\n\n");

    float base, exponente, potencia;
    printf("===========================================\n");
    printf("QUESTÃO 2\n");
    base = questao2pergunta1();
    exponente = questao2pergunta2();
    potencia = calculaPotencia(base, exponente);
    
    printf("Resultado: %f\n", potencia);
    printf("===========================================\n\n");
}
