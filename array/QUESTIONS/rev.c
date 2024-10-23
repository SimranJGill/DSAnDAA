// to reverse an array

#include <stdio.h>

// Function to reverse an array.
void reverse_array(int arr[], int len) {
    int start = 0;
    int end = len - 1;

    while (start < end) {
        // Swap the elements at the start and end indices.
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move the start index to the right.
        start++;

        // Move the end index to the left.
        end--;
    }
}

// Function to print an array.
void print_array(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to take values in an array
void scan_array(int arr[], int len){
    for (int i=0; i<len ; i++){
        scanf("%d",arr[i]);
    }
}

int main() {
    int i;
    printf("Enter the number of elements in array: ");
    scanf("%d\n",&i);
    int arr[i];

    scan_array(arr, i);

    print_array(arr, i);

    reverse_array(arr, i);

    print_array(arr, i);

    return 0;
}