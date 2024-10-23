#include <stdio.h>
#include <stdlib.h>

//made a struct named Node
struct Node {
    int data;
    struct Node *next;
};

// make a function to update the value of first element.
void insertAtBeginning(struct Node **head, int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    struct Node *head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");

    return 0;
}