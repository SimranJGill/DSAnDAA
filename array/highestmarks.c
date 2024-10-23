#include <stdio.h>
int main(){
    int stu, sub;
    printf("Enter number of students: ");
    scanf("%d\n",&stu);
    printf("Enter number of subjects: ");
    scanf("%d\n",&sub);
    
    int marks[stu][sub];

    for (int i=0 ; i<stu ; i++){
        for (int j=0 ; j<sub ; j++){
            printf("Enter marks of subject %d\n",i+1);
            scanf("%d\n",&marks[i][j]);
        }
    }

    int x=marks[0][0];

    for (int i=0 ; i<sub ; i++){
        for (int j=0 ; j<stu ; j++){
            if (x<=marks[i][j]){
                x=marks[i][j];
            }
        }
        printf("Highest marks of subject %d = %d\n",i+1,x);
    }
    return 0;
}