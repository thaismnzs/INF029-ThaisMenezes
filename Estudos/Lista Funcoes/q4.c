#include <stdio.h>

int ler3Numeros(int numeros[]) {
    for(int i=0; i<3; i++) {
        printf("%do numero:\n", i+1);
        scanf("%d", &numeros[i]);
    }
}

main() {
    int numeros[3];

    ler3Numeros(numeros);
      for(int i=0; i<3; i++) {
        printf("%d ", numeros[i]);
    }
}