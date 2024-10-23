#include <stdio.h>

void print_matrix(int mat[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int i,j,k,l;
    printf("Enter number of rows for Matrix I : ");
    scanf("%d\n",&i);
    printf("Enter the number of columns for Matrix I : ");
    scanf("%d\n",&j); 
    int m1[i][j];

    printf("Enter the number of rows for Matrix II : ");
    scanf("%D\n",&k);
    printf("Enter the number of columns for Matrix II : ");
    scanf("%d\n",&l);
    int m2[k][l];

    if (j==k){
        print_matrix(m1, i, j);
        print_matrix(m2, k, l);

        int res[i][l];
       for (int c ; c<i ; c++){
            for (int d ; d<l ; d++){
                res[c][d]=0;
                for ( int e ; e<j ; e++){
                    res[c][d]+=m1[c][e]*m2[e][d];
                }
            }
        }
        printf("\nProduct");
        print_matrix(res, i, l);
    }
    return 0;    
}