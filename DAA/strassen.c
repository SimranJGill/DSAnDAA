#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int size) {
	int i;
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }
    return matrix;
}

// Function to free memory of a matrix
void freeMatrix(int** matrix, int size) {
	int i;
    for (i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to fill a matrix with random values
void fillMatrix(int** matrix, int size) {
	int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }
}

// Traditional matrix multiplication
void traditionalMultiply(int** A, int** B, int** C, int size) {
	int i, j, k;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            C[i][j] = 0;
            for (k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to add two matrices
void addMatrices(int** A, int** B, int** C, int size) {
	int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int** A, int** B, int** C, int size) {
	int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Strassen's matrix multiplication function
void strassen(int** A, int** B, int** C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int** A11 = allocateMatrix(newSize);
    int** A12 = allocateMatrix(newSize);
    int** A21 = allocateMatrix(newSize);
    int** A22 = allocateMatrix(newSize);

    int** B11 = allocateMatrix(newSize);
    int** B12 = allocateMatrix(newSize);
    int** B21 = allocateMatrix(newSize);
    int** B22 = allocateMatrix(newSize);

    int** C11 = allocateMatrix(newSize);
    int** C12 = allocateMatrix(newSize);
    int** C21 = allocateMatrix(newSize);
    int** C22 = allocateMatrix(newSize);

    int** M1 = allocateMatrix(newSize);
    int** M2 = allocateMatrix(newSize);
    int** M3 = allocateMatrix(newSize);
    int** M4 = allocateMatrix(newSize);
    int** M5 = allocateMatrix(newSize);
    int** M6 = allocateMatrix(newSize);
    int** M7 = allocateMatrix(newSize);

    int** temp1 = allocateMatrix(newSize);
    int** temp2 = allocateMatrix(newSize);

    // Dividing matrices into quadrants
    int i, j;
    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Strassen's formula
    addMatrices(A11, A22, temp1, newSize);
    addMatrices(B11, B22, temp2, newSize);
    strassen(temp1, temp2, M1, newSize); // M1 = (A11 + A22) * (B11 + B22)

    addMatrices(A21, A22, temp1, newSize);
    strassen(temp1, B11, M2, newSize); // M2 = (A21 + A22) * B11

    subtractMatrices(B12, B22, temp1, newSize);
    strassen(A11, temp1, M3, newSize); // M3 = A11 * (B12 - B22)

    subtractMatrices(B21, B11, temp1, newSize);
    strassen(A22, temp1, M4, newSize); // M4 = A22 * (B21 - B11)

    addMatrices(A11, A12, temp1, newSize);
    strassen(temp1, B22, M5, newSize); // M5 = (A11 + A12) * B22

    subtractMatrices(A21, A11, temp1, newSize);
    addMatrices(B11, B12, temp2, newSize);
    strassen(temp1, temp2, M6, newSize); // M6 = (A21 - A11) * (B11 + B12)

    subtractMatrices(A12, A22, temp1, newSize);
    addMatrices(B21, B22, temp2, newSize);
    strassen(temp1, temp2, M7, newSize); // M7 = (A12 - A22) * (B21 + B22)

    // Calculating final quadrants of C
    addMatrices(M1, M4, temp1, newSize);
    subtractMatrices(temp1, M5, temp2, newSize);
    addMatrices(temp2, M7, C11, newSize); // C11 = M1 + M4 - M5 + M7

    addMatrices(M3, M5, C12, newSize);    // C12 = M3 + M5
    addMatrices(M2, M4, C21, newSize);    // C21 = M2 + M4
    addMatrices(M1, M3, temp1, newSize);
    subtractMatrices(temp1, M2, temp2, newSize);
    addMatrices(temp2, M6, C22, newSize); // C22 = M1 - M2 + M3 + M6

    // Combining into result matrix C
    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    // Free memory for temporary matrices
    freeMatrix(A11, newSize); freeMatrix(A12, newSize); freeMatrix(A21, newSize); freeMatrix(A22, newSize);
    freeMatrix(B11, newSize); freeMatrix(B12, newSize); freeMatrix(B21, newSize); freeMatrix(B22, newSize);
    freeMatrix(C11, newSize); freeMatrix(C12, newSize); freeMatrix(C21, newSize); freeMatrix(C22, newSize);
    freeMatrix(M1, newSize); freeMatrix(M2, newSize); freeMatrix(M3, newSize); freeMatrix(M4, newSize);
    freeMatrix(M5, newSize); freeMatrix(M6, newSize); freeMatrix(M7, newSize);
    freeMatrix(temp1, newSize); freeMatrix(temp2, newSize);
}

int main() {
    int size = 512;
    
    // Allocate and fill matrices A, B, and C
    int** A = allocateMatrix(size);
    int** B = allocateMatrix(size);
    int** C_traditional = allocateMatrix(size);
    int** C_strassen = allocateMatrix(size);

    fillMatrix(A, size);
    fillMatrix(B, size);

    // Measure time for traditional multiplication
    clock_t start = clock();
    traditionalMultiply(A, B, C_traditional, size);
    clock_t end = clock();
    double time_traditional = (double)(end - start) / CLOCKS_PER_SEC;

    // Measure time for Strassen multiplication
    start = clock();
    strassen(A, B, C_strassen, size);
    end = clock();
    double time_strassen = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken by traditional method: %.6f seconds\n", time_traditional);
    printf("Time taken by Strassen's method: %.6f seconds\n", time_strassen);

    // Free memory
    freeMatrix(A, size);
    freeMatrix(B, size);
    freeMatrix(C_traditional, size);
    freeMatrix(C_strassen, size);

    return 0;
}
