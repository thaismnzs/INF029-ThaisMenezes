#include <stdio.h>
#include <stdlib.h>

int fat(int n) {
    if(n == 1 || n == 0) {
        return 1;
    } else {
        return n*fat(n-1);
    }
}

int superFatorial(int n) {
    if(n == 1 || n == 0){
        return 1;
    }
    return fat(n) * superFatorial(n-1);
}
int main(){
    int n;
    printf("Informe n:\n");
    scanf("%d", &n);
    printf("%d!!!! = %d", n, superFatorial(n));
}
