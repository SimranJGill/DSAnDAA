/*#include <stdio.h>
int main()
{
    int i,n,p,d,flag=0;

    printf("Enter the size of the array:\n");
    scanf("%d\n",&n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the element to be deleted :\n");
    scanf("%d\n",&d);

    for (i=0 ; i<n ; i++){
        if (d = arr[i]){
            flag=1;
            break;
        }
    }

    if (flag=1){
        for (i=i ; i<n-1 ; i++){
            arr[i]=arr[i+1];
        }
        n--;
    }
    else{
        printf("\nEntered value is not present");
    }

    printf("\nThe new array is :");
    for (i=0 ; i<n-1 ; i++){
        printf("%d",arr[i]);
    }
    return 0;
}*/

#include <stdio.h>
int main()
{
    int arr1[100], i, n, delval, flag = 0;
    printf("\n\nDelete a value from the sorted array:\n");
    printf("Input the size of array : ");
    scanf("%d", &n);
    printf("Input %d elements in the array in ascending order:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr1[i]);
    }
    printf("Input the value to be deleted : ");
    scanf("%d", &delval);
    printf("The existing array list is :\n");
    for (i = 0; i < n; i++)
        printf("% 5d", arr1[i]);

    for (i = 0; i < n; i++)
    {
        if (delval == arr1[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        for (i = i; i < n - 1; i++)
            arr1[i] = arr1[i + 1];

        n--;
    }
    else
    {
        printf("\n\nThe value to be deleted is not found in the array.\n");
    }
    printf("\n\nAfter Delete the list is :\n");
    for (i = 0; i < n; i++)
        printf("% 5d", arr1[i]);
    printf("\n");
    return 0;
}