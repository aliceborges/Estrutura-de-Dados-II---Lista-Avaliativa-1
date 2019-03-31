#define q2_h

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

float questao2pergunta1(){
    float base; 
    int valida;

    printf("Digite um número natural para a base: ");
    scanf("%f", &base);
    valida = validaNaturais(base);

    if(valida == 0){
        return base;
    }else{
        printf("O dado informado %f não é um número natural. Tente novamente.\n", base);
        questao2pergunta1();
    }
}

float questao2pergunta2(){
    float exponente; 
    int valida;

    printf("Digite um número natural para o exponente: ");
    scanf("%f", &exponente);
    valida = validaNaturais(exponente);

    if(valida == 0){
        return exponente;
    }else{
        printf("O dado informado %f não é um número natural. Tente novamente.\n", exponente);
        questao2pergunta2();
    }
}

int q2(){
    float base, exponente, potencia;
    printf("===========================================\n");
    printf("QUESTÃO 2\n");
    base = questao2pergunta1();
    exponente = questao2pergunta2();
    potencia = calculaPotencia(base, exponente);
    printf("Resultado: %f\n", potencia);
    printf("===========================================\n\n");
}