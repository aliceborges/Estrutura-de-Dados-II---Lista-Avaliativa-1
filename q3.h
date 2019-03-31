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

int q3(){
    int fatorando;
    float resultado3;
    printf("===========================================\n");
    printf("QUESTÃO 3\n");
    fatorando = questao3();
    resultado3 = fatorialQuadruplo(fatorando, fatorando * 2);
    printf("Resultado: %f\n", resultado3);
    printf("===========================================\n\n");
}