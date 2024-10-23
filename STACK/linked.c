#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* link;
} *top=NULL;

void push(int val)
{
    struct node *newnode;
    newnode=malloc(sizeof(newnode));

    if(newnode==NULL){
        printf("Stack Overflow\n");
        exit(1);
    }

    newnode->data = val;
    newnode->link=NULL;
    newnode->link=top;
    top=newnode;
}

int isempty(){
    if(top=NULL){
        return 1;
    }
    else{
        return 0;
    }
}


int pop()
{
    struct node *temp;
    int val;
    if(isempty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    temp=top;
    val=temp->data;
    top=top->link;
    free(temp);
    temp=NULL;
    return val;
}

int peek(){
    if(isempty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return top->data;
}

void print(){
    struct node *temp;
    temp=top;
    printf("Stack elements are as follows: \n");
    while(temp){
        printf("%d",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main()
{
    int choice, data;
    while(1){
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the Top element\n");
        printf("4. Print all the elements in the stack\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the element to be pushed into the stack: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                data=pop();
                printf("Deleted element is %d.",data);
                break;
            case 3:
                printf("The top element of the stack is %d",peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
            default:
                printf("Wrong Choice.\n");
        }
    }
    return 0;
}






