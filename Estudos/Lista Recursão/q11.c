#include <stdio.h>
#include <stdlib.h>

int multip_Rec(int n1, int n2) {
    if(n2 == 0) {
        return 0;
    }

    return n1 + multip_Rec(n1, n2-1);
}

int main(){
    printf("%d", multip_Rec(5, 10));
}