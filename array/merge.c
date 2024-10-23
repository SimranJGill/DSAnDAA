// merge 2 arrays
#include <stdio.h>

int main()
{
    int array1[100], array2[100], array[100], n1, n2, i, j, k;

    printf("Enter the number of elements in the first array\n");
    scanf("%d", &n1);

    printf("Enter the elements of the first array\n");
    for (i = 0; i < n1; i++)
        scanf("%d", &array1[i]);

    printf("Enter the number of elements in the second array\n");
    scanf("%d", &n2);

    printf("Enter the elements of the second array\n");
    for (i = 0; i < n2; i++)
        scanf("%d", &array2[i]);

    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2)
    {
        if (array1[i] < array2[j])
            array[k++] = array1[i++];
        else
            array[k++] = array2[j++];
    }
    while (i < n1)
        array[k++] = array1[i++];

    while (j < n2)
        array[k++] = array2[j++];

    printf("\nMerged array is: \n");
    for (i = 0; i < n1 + n2; i++)
        printf("%d ", array[i]);

    return 0;
}