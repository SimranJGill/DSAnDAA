#include <stdio.h>

int main(){
    int arr[5];
    int i,p;
    for ( i=0 ; i<5 ; ++i){
        scanf("%d",&arr[i]);
    }
    int m=arr[0];
    for ( i=0 ; i<5 ; ++i){
        if ( arr[i]<m ){
            m=arr[i];
            p=i+1;
        }
    }
    printf("Smallest element : %d\n",m);
    printf("Position of smallest element : %d\n",p);
    return 0;
}