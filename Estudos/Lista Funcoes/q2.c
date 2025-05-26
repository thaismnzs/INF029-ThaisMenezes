#include <stdio.h>

int subtrai(int a, int b, int c) {
    return a-b-c;
}

main(){
    int a, b, c;

    printf("Informe um valor:\n");
    scanf("%d", &a);
    printf("Informe outro valor:\n");
    scanf("%d", &b);
    printf("Informe mais um valor:\n");
    scanf("%d", &c);

    printf("%d", subtrai(a,b,c));
}