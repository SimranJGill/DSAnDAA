#include <stdio.h>
int main(){
    int arr1[5];
    int i,sum=0;
    for(i=0 ; i<5 ; ++i){
        scanf("%d",&arr1[i]);
    }
    for(i=0 ; i<5 ; ++i){
        printf("%d\t",arr1[i]);
    }
    int l,sl;
    if (arr1[0]>arr1[1]){
        l=arr1[0];
    }
    else{
        l=arr1[0];
    }
    for(i=2 ; i<5 ; ++i){
        if (arr1[i]>l){
            l=sl;
            l=arr1[i];
        }
        else if (arr1[i]<l){
            if (arr1[i]>sl){
                sl=arr1[i];
            }
        }
    }
    
    printf("\n%d",sl);
    return 0;
}