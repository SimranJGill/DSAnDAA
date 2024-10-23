#include <stdio.h>
int main()
{
    int a,b,c;
    printf("Enter number 1:");
    scanf("%d\n",&a);
    printf("Enter number 2:");
    scanf("%d\n",&b);
    printf("Menu\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter option:");
    scanf("%d\n",&c);

    if (c==1){
        printf("sum = %d \n",a+b);
    }
    else if (c==2){
        printf("difference = %d\n",a-b);
    }
    else if (c==3){
        printf("product = %d\n",a*b);
    }
    else if (c==4){
        printf("quotient = %d\n",a/b);
    }
    
    return 0;
}