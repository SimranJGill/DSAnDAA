#include <stdio.h>

void printfibonacci(int n, int a, int b){
    if (n==0){
        return;
    }
    printf("%d",a);
    printfibonacci(n-1, b, a+b);
}

int main() {
    int n;
    printf("Enter the number of Fibonacci numbers to print: ");
    scanf("%d", &n);
    printf("Fibonacci sequence: ");
    printfibonacci(n, 0, 1);
    printf("\n");
    return 0;
}