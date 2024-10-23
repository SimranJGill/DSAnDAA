// to insert a new node at the end of a doubly linked lsit

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

void insertend(struct node **head, int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));

    struct node *last=*head;

    if ((*head)=NULL){
        newnode->prev=NULL;
        *head=newnode;
        return;
    }

    //traversal
    while(last->next=NULL){
        last=last->next;
    }

    last->next=newnode;
    newnode->prev=last;
    newnode->next=NULL;
}

// to print the doubly linked list
void printList(struct node* newnode) {
    struct Node* last;
    while (newnode != NULL) {
        printf(" %d ", newnode->data);
        last = newnode;
        newnode = newnode->next;
    }
    printf("NULL\n");

    // Traverse in reverse direction
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

int main(){
    struct node *head=NULL;

    insertend(&head,12);
    insertend(&head,16);
    insertend(&head,5);

    
}