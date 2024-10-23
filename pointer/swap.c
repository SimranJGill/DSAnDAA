 /*#include <stdio.h>
int main() {
    int a,b;
    printf("Enter two values:\n");
    scanf("%d\n",&a);
    scanf("%d\n",&b);
    a=((*(&a))+(*(&b)));
    b=((*(&a))-(*(&b)));
    a=((*(&a))-(*(&b)));
    printf("%d %d",a,b);
    return 0;
}*/

#include <stdio.h>
int main() {
    int a=10,b=20,*p1=&a,*p2=&b;
    printf("before swap: *p1=%d, *p2=%d",*p1,*p2);
    *p1=*p1+*p2;
    *p2=*p1-*p2;
    *p1=*p1-*p2;
    printf("\nAfter swap: *p1=%d, *p2=%d",*p1,*p2);
    return 0;
}