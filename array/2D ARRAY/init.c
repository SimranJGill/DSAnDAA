#include <stdio.h>

int main(){
    int m,n,arr[m][n];
    int i,j;

    for (i=0 ; i<m ; i++){
        for(j=0 ; j<n ; j++){
            printf("Enter element at [%d][%d]:",i,j);
            scanf("%d",arr[i][j]);
        }
        printf("\n");
    }

    for (i=0 ; i<m ; i++){
        for (j=0 ; j<n ; j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}