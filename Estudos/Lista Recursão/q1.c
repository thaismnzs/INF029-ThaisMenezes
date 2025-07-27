#include <stdio.h>
#include <stdlib.h>

int fat(int n) {
    if(n == 1 || n == 0) {
        return 1;
    } else {
        return n*fat(n-1);
    }
}

