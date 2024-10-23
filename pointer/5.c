#include <stdio.h>
int main(){
    int a[5];
    int *p[5]=&a;
    a[5]={10,20,30,40,50};
    printf(a+3);
    printf(*(a+3));
    printf(*(a+0));
    printf(a[0]);
    return 0;
}

