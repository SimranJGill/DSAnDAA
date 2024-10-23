// C program to all natural numbers in reverse from n to 1


#include <stdio.h>

int main()
{
    int i, start;

    printf("Enter starting value: ");
    scanf("%d", &start);

    for(i=start; i>=1; i--)
    {
        printf("%d\n", i);
    }

    return 0;
}