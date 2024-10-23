#include <stdio.h>

int main(){
    int arr1[5];
    int i,sum=0;
    for(i=0 ; i<5 ; ++i){
        scanf("%d",&arr1[i]);
    }
    for(i=0 ; i<5 ; i++){
        sum+=arr1[i];
    }
    printf("%d",sum);
    return 0;
}