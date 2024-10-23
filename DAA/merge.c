#include <stdio.h>

void Merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = A[q + 1 + j];
    }

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        A[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        A[k] = R[j];
        ++j;
        ++k;
    }
}

void MergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main() {
    int A[] = {12, 11, 30, 25, 13, 5, 6, 7, 10, 20, 0, -2, -100};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Given array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");

    MergeSort(A, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}