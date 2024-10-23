// to insert a new node before a given node

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

void insertbefore(struct node *ptr, int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=ptr->prev;
    newnode->next=ptr;
    ptr->prev=newnode;
    if (newnode->prev != NULL)
        newnode->prev->next = newnode;
}

void printList(struct node* head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // create a doubly linked list 10 <-> 20 <-> 30
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->prev = NULL;
    head->next = NULL;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    second->data = 20;
    second->prev = head;
    second->next = NULL;
    head->next = second;

    struct node *third = (struct node*)malloc(sizeof(struct node));
    third->data = 30;
    third->prev = second;
    third->next = NULL;
    second->next = third;

    //original doubly linked list
    printList(head);

    //insert a new node
    insertBefore(second, 15);

    //updated doubly linked list
    printList(head);

    return 0;
}