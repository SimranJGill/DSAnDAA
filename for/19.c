#include <stdio.h>

int main() {
    int prv = 0, pre = 1, trm, i, n;

    
    printf("Input number of terms to display: ");
    scanf("%d", &n);

    
    printf("Here is the Fibonacci series up to %d terms:\n", n);

    printf("%5d %5d", prv, pre);

    for (i = 3; i <= n; i++) {
        trm = prv + pre;
        printf("%5d", trm);
        prv = pre;
        pre = trm;
    }

    printf("\n");

    return 0;
}

