//find sum of all array elements using recursion

#include <stdio.h>

int sum_matrix(int matrix[][10], int rows, int cols, int cur_row, int cur_col) {
    if (cur_row == rows || cur_col == cols) {
        return 0;
    }

    return matrix[cur_row][cur_col] + sum_matrix(matrix, rows, cols, cur_row, cur_col + 1);
}

// initialize using random values
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

// ex
int main() {
    int matrix[10][10] = {0};
    int rows = 3, cols = 4;

    init_matrix(matrix, rows, cols);  // Initialize a matrix with random values.
    print_matrix(matrix, rows, cols);  // Print the matrix.

    int sum = sum_matrix(matrix, rows, cols, 0, 0);  // Find the sum of all the elements of the matrix.
    printf("Sum of all the elements of the matrix: %d\n", sum);

    return 0;
}