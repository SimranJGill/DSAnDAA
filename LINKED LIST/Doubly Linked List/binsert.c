//to insert a new node at the beginning of a doubly linked list


#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

int main(){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node **head=NULL;
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=(*head);
    if (*head != NULL){
        (*head)->prev=newnode;
    }
    (*head)=newnode;
}
