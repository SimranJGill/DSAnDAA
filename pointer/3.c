#include <stdio.h>

int main(){
    int *p,c,d;
    c=5;
    d=-15;
    p=&c;printf("%d",*p);
    p=&d;printf("%d",*p);
}