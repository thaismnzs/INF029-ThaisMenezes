#include <stdio.h>
#include <stdlib.h>

int mdc(int x, int y) {
    if(y == 0) {
        return x;
    }
        return mdc(y, x%y);
}

int main(){
    printf("%d", mdc(9, 18));
}