#include <stdio.h>

void ler3Letras(char letras[3]) {
    for (int i = 0; i < 3; i++) {
        printf("Informe a 1a letra: ", i + 1);
        scanf(" %c", &letras[i]);
    }
}

main() {
    char letras[3];
    ler3Letras(letras);

    printf("\nLetras: %c %c %c\n", letras[0], letras[1], letras[2]);
    
}
