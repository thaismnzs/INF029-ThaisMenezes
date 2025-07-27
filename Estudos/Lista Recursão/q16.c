#include <stdio.h>
#include <stdlib.h>

int fatorialDuplo(int n) {
    if(n == 1) {
        return 1;
    }
    return n * fatorialDuplo(n-2);
    
}

int main(){
    int n;
    printf("Informe n:\n");
    scanf("%d", &n);
    printf("%d", fatorialDuplo(n));
}