#include <stdio.h>

/// Converte um dado IMC em um conceito, a partir de uma tabela especifica;
/// Printa o conceito gerado.
void conversor_conceitos(float imc);

void conversor_conceitos(float imc) {
    if (imc > 40.0) {
        printf("A Classificacao eh: Obesidade Grau III!\n");
    } else if (imc < 39.9 && imc > 35.0) {
        printf("A Classificacao eh: Obesidade Grau II!\n");
    } else if (imc < 34.9 && imc > 30.0) {
        printf("A Classificacao eh: Obesidade Grau I!\n");
    } else if (imc < 29.9 && imc > 25.0) {
        printf("A Classificacao eh: Sobrepeso!\n");
    } else if (imc < 24.9 && imc > 18.6) {
        printf("A Classificacao eh: Normal!\n");
    } else {
        printf("A Classificacao eh: Abaixo do Normal!\n");
    }
}

/// Recebe peso e altura e retorna o IMC e classificação deste.
void main() {
    float peso, alt, imc;
    scanf("%f%f", &alt, &peso);
    imc = (float)peso / (alt*alt);
    printf("Seu IMC eh: %.2f\n", imc);
    conversor_conceitos(imc);
}