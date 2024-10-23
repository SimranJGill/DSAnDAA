#include <stdio.h>

int main() {
    int *p;
    int (*ptr)[5];
    int arr[5];
    p=arr;
    ptr=&arr;
    printf("p = %u , ptr = %u\n",p,ptr);
    p++;
    ptr++;
    printf("p=%u,ptr=%u\n",p,ptr);
    return 0;
}