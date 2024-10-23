// to find the largest 3 distinct elements in an array.

#include <stdio.h>

void scan_array(int arr[], int len){
    for (int x=0 ; x<len ; x++){
        scanf("%d",&arr[x]);
    }
}
void print_array(int arr[], int len){
    for (int j=0 ; j<len ; j++){
        printf("%d",arr[j]);
    }
}

int main(){
    int i;
    printf("Enter the number of elements in a array: ");
    scanf("%d\n",&i);
    int arr[i];
    
    scan_array(arr, i);

    print_array(arr, i);

    int l,sl,tl;

    if (arr[0]>arr[1]){
        l=arr[0];
    }
    else{
        l=arr[0];
    }
    for(int x=2 ; x<i ; x++){
        if (arr[i]>l){
            l=sl;
            l=arr[i];
        }
        else if (arr[i]<l){
            if (arr[i]>sl){
                sl=arr[i];
            }
        }
    }
    
    printf("The largest number is %d.\n",l);
    printf("The Second largest number is %d.\n",sl);


}