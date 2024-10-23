// to count the number of non v=zero elements

#include <stdio.h>

// Function to print an array.
void print_array(int arr[], int row, int clm) {
    for (int i = 0; i < row; i++) {
        for (int j=0; j<clm ; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to take values in an array
void scan_array(int arr[], int rows, int clm){
    for (int i=0; i<rows ; i++){
        for (int j=0 ; j<clm ; j++){
            scanf("%d",arr[i][j]);
        }
    }
}

void check(int arr[], int row, int clm){
    int count=0;
    for (int i=0 ; i<row ; i++){
        for (int j=0 ; j<clm ; j++){
            if (arr[i][j]!=0){
                count+=1;
            }
        }
    }
    printf("Count of Non-Zero elements : %d",count);
}

int main(){
    int r,c;
    printf("Enter the number of rows: ");
    scanf("%d\n",&r);
    printf("Enter the number of cloumns: ");
    scanf("%d\n",&c);
    int arr[r][c];

    scan_array(arr, r, c);
    print_array(arr, r, c);
    check(arr, r, c);
    
}