// C program to find sum of its digits of a number
 

#include <stdio.h>

int main()
{
    int num, sum=0;

    
    printf("Enter any number to find sum of its digit: ");
    scanf("%d", &num);

    
    while(num!=0)
    {
        
        sum += num % 10;

        num = num / 10;
    }

    printf("Sum of digits = %d", sum);

    return 0;
}