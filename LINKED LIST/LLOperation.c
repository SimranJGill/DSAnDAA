#include <stdio.h>
#include <stdlib.h>

//1 create a list
typedef struct node{
    int data;
    struct node *next;
} node;

//to insert a new node
node* NewNode(int data){
    node *newnode=(node*)malloce(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

//2 to print a list
void print(node* head){
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

//3 to insert a node at the beginning
void insertbeg(struct node **head, int value){
    node *newnode=NewNode(value);
    newnode->next = *head;
    *head = newnode;
}

//4 to insert node at the end
void insertend(struct node **ref, int value){
    node *newnode=NewNode(value);
    if (*ref = NULL){
        *ref = newnode;
        return;
    }

    node *last = *ref;
    while (last->next != NULL){
        last = last->next;
    }
    last->next = newnode;
}

//5 to insert a node b4 a position
void insert_before_position(struct node** head, int position, int data) {
    if (position <= 1) {
        printf("Invalid position.\n");
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = data;

    if (*head == NULL) {
        // If the list is empty, make the new node the head of the list
        *head = new_node;
        new_node->next = NULL;
        return;
    }
    if (position == 2) {
        // If position is 2, insert at the beginning
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Traverse the list to find the node at (position - 1)
    struct node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    // Insert the new node before the node at (position - 1)
    new_node->next = temp->next;
    temp->next = new_node;
}

//6 to insert a node after a given node
void insertAfter(node *prevnode, int value) {
    node* newnode = NewNode(value);
    newnode->next = prevnode->next;
    prevnode->next = newnode;
}

//7 to dlt the last node
void deleteLastNode(node **head_ref) {
    node* temp = *head_ref, *prev;

    if (*head_ref == NULL) {
        return;
    }

    if (temp->next == NULL) {
        free(temp);
        *head_ref = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

//8 to dlt a given node
void deleteNode(node **head_ref, int key) {
    node *temp = *head_ref, *prev;
    while (temp != NULL && temp->data == key) {
        *head_ref = temp->next;  
        free(temp);               
        temp = *head_ref;         
    }

    while (temp != NULL) {
        while (temp != NULL && temp->data != key) {//to search for key
            prev = temp;
            temp = temp->next;
        }

        //if key not present
        if (temp == NULL) return;

        prev->next = temp->next;

        free(temp);  // Free memory

        temp = prev->next; //update memory
    }
}

//9 to dlt node after a given node
void deleteAfter(node *head) {
    node *temp = head->next;

    if (temp != NULL) {
        head->next = temp->next;
        free(temp);
    }
}

//10 to dlt the entire list
void deleteList(node **head) {
    node *current = *head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

//11 to swap the nodes
struct node* swap(struct node* ptr1, struct node* ptr2)
{
    int tmp = ptr2->data;
    ptr2->data = ptr1->data;
    ptr1->data = tmp;

    return ptr1;
}

//Function to sort the list
void bubbleSort(struct Node** head)
{
    struct Node* current = *head;
    int swapped;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        current = *head;

        while (current -> next != NULL) {
            if (current -> data > current -> next -> data) {
                current = swap(current, current -> next);
                swapped = 1;
            }
            current = current -> next;
        }

    } while (swapped);
}

int main(){
    struct node *head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    print(head);

    return 0;
}