#include <stdio.h>

void transpose(int matrix[][3], int trans[3][]){
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<3 ; j++){
            trans[j][i]=matrix[i][j];
        }
    }
}

int main(){
    int arr[3][3], tarr[3][3];
    int i,j;

    for (i=0 ; i<3 ; i++){
        for (j=0 ; j<3 ; j++){
            printf("Enter the element [%d][%d]: ",i,j);
            scanf("%d\t",&arr[i][j]);
        }
    }

    transpose(arr,tarr);

    printf("Original matrix");
    for (i=0 ; i<3 ; i++){
        for (j=0 ; j<3 ; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    printf("Transpose of the matrix");
    for (i=0 ; i<3 ; i++){
        for (j=0 ; j<3 ; j++){
            printf("%d\t",tarr[i][j]);
        }
        printf("\n");
    }

    return 0;
}