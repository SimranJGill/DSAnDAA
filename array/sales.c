#include <stdio.h>

int main(){
    int sm, p;
    printf("Enter the name of the salesman and the product: ");
    scanf("%d\t%d",&sm,&p);
    int S[sm][p];
    for (int i=0 ; i<sm ; i++){
        printf("Enter salesman %d: \n",i+1);
        for (int j=0 ; j<p ; j++){
            printf("Enter the product value: ");
            scanf("%d",&S[i][j]);
        }
    }

    for (int i=0 ; i<sm ; i++){
        for (int j=0 ; j<p ; j++){
            printf("%d\t",S[i][j]);
        }
        printf("\n");
    }

    

    for (int i=0 ; i<sm ; i++){
        int sum=0;
        for (int j=0 ; j<p ; j++){
            sum+=S[i][j];
        }
        printf("The sum of the total sales by salesman %d = %d\n",i+1,sum);
    }

    for (int i=0 ; i<p ; i++){
        int total=0;
        for (int j=0 ; j<sm ; j++){
            total+=S[i][j];
        }
        printf("The total sales of product %d = %d\n",i+1,total);
    }
    return 0;
}