/*#include <Stdio.h> 
 #include <conio.h> 
 int main() 
 { 
     int i,n,j,num,arr[10]; 
      
     printf("\nEnter the number of elements in the array:");  
     scanf("%d",&n); 
     printf("\nEnter the array elements:"); 
   for(i=0;i<n;i++) 
     { 
       scanf("%d",&arr[i]); 
     } 
     printf("\nEnter the number to be inserted: ") ; 
     scanf ("%d",&num); 
   for(i=0;i<n;i++) 
   { 
     if(arr[i] > num) 
      { 
         for(j =n-1;j>=i;j--) 
          { 
            arr[j+1] = arr[j]; 
            arr[i] = num; 
            break; 
          } 
            n++; 
      } 
   } 
       printf("\nThe array after insertion of %d is: ",  num); 
       for(i=0;i<n+1;i++) 
       { 
          printf("\t%d", arr[i]); 
       } 
       getch(); 
       return 0; 
 }*/

#include <stdio.h>
int main()
{
    int arr1[100], i, n, p, inval;
    printf("\n\nInsert New value in the sorted array:\n");
    printf("Input the size of array : ");
    scanf("%d", &n);
    printf("Input %d elements in the array in ascending order:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr1[i]);
    }
    printf("Input the value to be inserted : ");
    scanf("%d", &inval);
    printf("The existing array list is :\n");
    for (i = 0; i < n; i++)
        printf("%d", arr1[i]);
    for (i = 0; i < n; i++)
    {
        if (inval < arr1[i])
        {
            p = i;
            break;
        }
        else
        {
            p = i + 1;
        }
    }
    for (i = n + 1; i >= p; i--)
        arr1[i] = arr1[i - 1];

    arr1[p] = inval;
    printf("\n\nAfter Insert the list is :\n");
    for (i = 0; i <= n; i++){
        printf("element %d is :",i);
        printf("%d\n", arr1[i]);
    }
    printf("\n");
    return 0;
}