#include <stdio.h>

int main(){
    int a=10;
    int *b;
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",*b);
    printf(*(*(&b)));
    return 0;
}

