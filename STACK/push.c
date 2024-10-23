
#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int top = -1, array[MAX];
void push();
int pop();
int peek();
void print();

int main()
{
    int choice;
    int data;

    while (1)
    {
        printf("\nPerform operations on the stack:");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Print all the elements\n5. Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be Pushed: ");
            scanf("%d\n",&data);
            push(data);
            break;
        case 2:
            data=pop();
            printf("Deleted element = %d\n",data);
            break;
        case 3:
            printf("The topmost element is %d\n",peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);
        default:
            printf("\nInvalid choice");
        }
        
    }
    return 0;
}

void push()
{
    int x;

    if (top == MAX - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        array[top] = x;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow");
        exit(1);
    }
    int value;
    value=array[top];
    top=top-1;
    return value;
}
int peek(){
    if (top == -1){
        printf("Stack Underflow\n");
        return;
    }
    return array[top];
}
void print(){
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    for (int i = top ; i>=0 ; i--){
        printf("%d\n",array[i]);
    }
    printf("\n");
}