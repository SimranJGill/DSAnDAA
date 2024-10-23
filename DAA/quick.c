#include <stdio.h>

int Partition(int A[], int l, int h) {
    int pivot = A[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (A[j] <= pivot) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i + 1];
    A[i + 1] = A[h];
    A[h] = temp;

    return i + 1;
}

void QuickSort(int A[], int l, int h) {
    if (l < h) {
        int mid = Partition(A, l, h);
        QuickSort(A, l, mid - 1);
        QuickSort(A, mid + 1, h);
    }
}

int main() {
    int A[] = {12, 11, 30, 25, 13, 5, 6, 7, 10, 20, 0, -2, -100};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Given array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    QuickSort(A, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}