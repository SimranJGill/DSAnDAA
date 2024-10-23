#include <stdio.h>
int sum(int n){
    if(n==1)
    {
        return 1;
    }
    else 
    return n + sum(n-1);
}
int main()
{     
    int s;
    printf("Input number : ");
    scanf("%d", &s);
    printf("%d",sum(s));
    return 0;
}