#include <stdio.h>
#include <string.h>
#define TAM_STR 250

void ler3Palavras(char palavra1[], char palavra2[], char palavra3[]) {
    printf("Informe uma palavra:\n");
    fgets(palavra1, TAM_STR, stdin);
    palavra1[strcspn(palavra1, "\n")] = '\0';

    printf("Informe mais uma palavra:\n");
    fgets(palavra2, TAM_STR, stdin); 
    palavra2[strcspn(palavra2, "\n")] = '\0';

    printf("Informe mais uma palavra:\n");
   fgets(palavra3, TAM_STR, stdin);
   palavra3[strcspn(palavra3, "\n")] = '\0';

} 

int main(){
    char palavra1[TAM_STR], palavra2[TAM_STR], palavra3[TAM_STR];
    ler3Palavras(palavra1, palavra2, palavra3);

    printf("%s\n%s\n%s", palavra1, palavra2, palavra3);
}