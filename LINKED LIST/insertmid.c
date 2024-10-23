#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertInMiddle(struct Node **head, int value, int position) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;

    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    for (int i = 1; i < position - 1; i++) {
        if (current->next == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    struct Node *head = NULL;
    insertInMiddle(&head, 20, 1);
    insertInMiddle(&head, 10, 2);
    insertInMiddle(&head, 30, 3);

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");

    return 0;
}