// to print all the unique elements.
/*
#include <stdio.h>

// Function to print all the distinct elements from an array.
void print_distinct_elements(int arr[], int len) {
    int visited[len] = {0};

    for (int i = 0; i < len; i++) {
        if (!visited[i]) {
            printf("%d ", arr[i]);

            // Mark the element as visited.
            for (int j = i + 1; j < len; j++) {
                if (arr[i] == arr[j]) {
                    visited[j] = 1;
                }
            }
        }
    }
}

// Function to print an array.
void print_array(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage:
int main() {
    int arr[] = {1, 2, 3, 2, 4, 5, 4, 6, 7, 6, 8, 9, 8};

    print_array(arr, 13);

    print_distinct_elements(arr, 13);

    return 0;
}
*/

#include <stdio.h>

int main()
{
    int arr1[100], n, ctr = 0;
    int i, j, k;
    
    
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);
    
    printf("Input %d elements in the array :\n", n);
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr1[i]);
    }
    
    printf("\nThe unique elements found in the array are: \n");
    for (i = 0; i < n; i++)
    {
        ctr = 0;
        for (j = 0, k = n; j < k + 1; j++)
        {
            
            if (i != j)
            {
                if (arr1[i] == arr1[j])
                {
                    ctr++;
                }
            }
        }
        if (ctr == 0)
        {
            printf("%d ", arr1[i]);
        }
    }
    printf("\n\n");
    return 0;
}
