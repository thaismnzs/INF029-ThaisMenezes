#include <stdio.h>

typedef struct {
    int a, b, c, d;
} Numeros;

void ler4Numeros(Numeros *numeros) {
    printf("Informe um numero:\n");
    scanf("%d", &numeros->a);
    printf("Informe outro numero:\n");
    scanf("%d", &numeros->b);
    printf("Informe outro numero:\n");
    scanf("%d", &numeros->c);
    printf("Informe outro numero:\n");
    scanf("%d", &numeros->d);
    }

    main(){
        Numeros numeros;
        ler4Numeros(&numeros);

        printf("\nNumeros: %d, %d, %d, %d\n", 
        numeros.a, numeros.b, numeros.c, numeros.d);
    }
