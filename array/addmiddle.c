#include <stdio.h>
int main()
{
    int array[100], n, x, pos, i;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("Input array elements are: \n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\nEnter the new element to be inserted: ");
    scanf("%d", &x);
    printf("Enter the position where element is to be inserted: ");
    scanf("%d", &pos);
    n=n+1;
    for(i = n-1; i >= pos; i--)
        array[i]=array[i-1];
    array[pos-1]=x;
    printf("\nFinal array after inserting the element: \n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    return 0;
}