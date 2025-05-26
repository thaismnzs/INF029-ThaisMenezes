#include <stdio.h>

int fatorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    } else {
    return n*fatorial(n-1);
    }
}

main() {
    int n;
    printf("Informe um valor:\n");
    scanf("%d", &n);

    printf("%d", fatorial(n));
    
}