

#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ptr;
    int n,i;

    printf("Number of elements: ");
    scanf("%d",&n);

    //dynamically aalocate memory
    ptr=(int*)malloc(n*sizeof(int));
    if (ptr==NULL){
        printf("MM not allocated");
        exit(0);
    }
    else{
        printf("MM has been allocated");

        //get elements
        for (i=0;i<n;++i){
            ptr[i]=i+1;
        }

        //print elemnets
        for (i=0;i<n;++i){
            printf(ptr[i]);
            ptr[i]=i+1;
        }
    }
    return 0;
}

