#include <stdio.h>

int main(){
    int inteiro, *ponteiro_inteiro = &inteiro;
    char caractere, *ponteiro_caractere = &caractere;
    char string[10], *ponteiro_string = string;
    float flutuante, *ponteiro_flutuante = &flutuante;
    double duplo, *ponteiro_duplo = &duplo;

    printf("Informe um inteiro:\n");
    scanf("%d", &inteiro);
    printf("Informe um caractere:\n");
    scanf(" %c", &caractere);
    printf("Informe uma string:\n");
    scanf(" %s", string);
    printf("Informe um float:\n");
    scanf("%f", &flutuante);
    printf("Informe um double:\n");
    scanf("%lf", &duplo);

    printf("Inteiro: %d - Ponteiro: %d\n", inteiro, *ponteiro_inteiro);
    printf("Caractere: %c - Ponteiro: %c\n", caractere, *ponteiro_caractere);
    printf("String: %s - Ponteiro: %s\n", string, ponteiro_string);
    printf("Float: %f - Ponteiro: %f\n", flutuante, *ponteiro_flutuante);
    printf("Double: %lf - Ponteiro: %lf\n", duplo, *ponteiro_duplo);


}