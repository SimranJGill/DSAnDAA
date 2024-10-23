// find the sum of rows and coloumns of matrix of given order

#include <stdio.h>

void sum_rows_cols(int matrix[][10], int rows, int cols) {
    int row_sums[rows] = {0};  // Array to store the sums of the rows.
    int col_sums[cols] = {0};  // Array to store the sums of the columns.

    // Iterate through the matrix and accumulate the sums of the elements in each row and each column.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            row_sums[i] += matrix[i][j];
            col_sums[j] += matrix[i][j];
        }
    }

    printf("Row sums: ");
    for (int i = 0; i < rows; i++) {
        printf("%d ", row_sums[i]);
    }
    printf("\n");

    printf("Col sums: ");
    for (int i = 0; i < cols; i++) {
        printf("%d ", col_sums[i]);
    }
    printf("\n");
}

void init_matrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[4][5] = {0};

    init_matrix(matrix, 4, 5);
    print_matrix(matrix, 4, 5);

    sum_rows_cols(matrix, 4, 5);

    return 0;
}