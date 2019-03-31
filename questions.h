#define questions_h

// QUESTÃO 1

float questao1(){
    float i;
    printf("Digite um número maior que 0 para exibir a somatória: ");
    scanf("%f", &i);

    return i;
}

// QUESTÃO 2

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

int questao3(){
    int resultado, valida;
    printf("Digite um número natural positivo para fazer o fatorial quádruplo: ");
    scanf("%d", &resultado);
    valida = validaNaturais(resultado);

    if(valida == 0){
        return resultado;
    }else{
        printf("O dado informado %d não é um número natural. Tente novamente.\n", resultado);
        questao3();
    }
}