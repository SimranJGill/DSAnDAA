/*#include <stdio.h>
int main(){
    int n,arr[n],p,i;
    printf("Enter number of elements: ");
    scanf("%d\n",&n);

    for (i=0 ; i<n ; ++i){
        scanf("%d",&arr[i]);
    }

    printf("Enter postion of element:");
    scanf("%d\n",&p);

    if (p>= (n+1)){
        printf("Deletion not possible.");
    }
    else{
        for (i=p-1 ; i<n-1 ; i++){
            arr[i]=arr[i+1];
        }
        printf("Resultant array is: ");
        for (i=0 ; i<n ; ++i){
            printf("%d\t",arr[i]);
        }
        return 0;
    }
}
*/

#include <stdio.h>
int main()
{
    int array[100], n, i, pos, flag = 0;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    printf("Enter the elements\n");

    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("Input array elements are: \n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\nEnter the value to be deleted: ");
    scanf("%d", &pos);

    for (i = 0; i < n; i++)
    {
        if (array[i] == pos)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        for (i = pos; i < n; i++)
            array[i-1] = array[i];

        printf("\nArray after deleting the element: \n");
        for (i = 0; i < n-1; i++)
            printf("%d ", array[i]);
    }
    else
        printf("\nElement not found in the array");
    return 0;
}