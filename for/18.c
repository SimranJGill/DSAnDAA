#include <stdio.h>

// prime or not

int main() {
    int num, i, ctr = 0;

    
    printf("Input a number: ");
    scanf("%d", &num);

    
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            ctr++;
            break;
        }
    }

    
    if (ctr == 0 && num != 1)
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    return 0;
}

