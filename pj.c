#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for category types
#define SHOPPING 1
#define FOOD_DRINKS 2
#define BILLS_UTILITIES 3
#define OTHERS 4

// Define a structure for transactions
typedef struct TransactionNode {
    char date[20];
    char category[20];
    char name[50]; // Added name field
    float amount;
    struct TransactionNode *next;
} TransactionNode;

// Define a structure for the finance manager
typedef struct {
    char name[100];
    float balance;
    TransactionNode *transactions;
} FinanceManager;

// Function prototypes
void deposit(FinanceManager *manager, float amount);
void debit(FinanceManager *manager, int category, char *name, float amount, char *date);
void displayTransactions(FinanceManager *manager);

int main() {
    FinanceManager manager;
    manager.balance = 0;
    manager.transactions = NULL;

    // Get user's name
    printf("Enter your name: ");
    scanf("%s", manager.name);

    printf("\nWelcome, %s!\n", manager.name);

    int choice;
    float amount;
    int category;
    char date[20];
    char name[50];

    while (1) {
        printf("\n1. Deposit\n");
        printf("2. Debit\n");
        printf("3. View Transactions\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&manager, amount);
                break;
            case 2:
                printf("Enter category (1. Shopping, 2. Food and Drinks, 3. Bill and Utilities, 4. Others): ");
                scanf("%d", &category);
                printf("Enter name (if applicable): ");
                scanf("%s", name);
                printf("Enter amount to debit: ");
                scanf("%f", &amount);
                printf("Enter date (DD/MM/YYYY): ");
                scanf("%s", date);
                debit(&manager, category, name, amount, date);
                break;
            case 3:
                displayTransactions(&manager);
                break;
            case 4:
                printf("Exiting program. Have a nice day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void deposit(FinanceManager *manager, float amount) {
    manager->balance += amount;
    printf("Deposited %.2f. Your balance is now %.2f\n", amount, manager->balance);
}

void debit(FinanceManager *manager, int category, char *name, float amount, char *date) {
    if (manager->balance < amount) {
        printf("Insufficient funds.\n");
        return;
    }
    manager->balance -= amount;

    // Create a new transaction node
    TransactionNode *newTransaction = (TransactionNode *)malloc(sizeof(TransactionNode));
    strcpy(newTransaction->date, date);
    switch (category) {
        case SHOPPING:
            strcpy(newTransaction->category, "Shopping");
            break;
        case FOOD_DRINKS:
            strcpy(newTransaction->category, "Food and Drinks");
            break;
        case BILLS_UTILITIES:
            strcpy(newTransaction->category, "Bill and Utilities");
            break;
        case OTHERS:
            strcpy(newTransaction->category, "Others");
            break;
        default:
            strcpy(newTransaction->category, "Unknown");
    }
    strcpy(newTransaction->name, name);
    newTransaction->amount = amount;
    newTransaction->next = NULL;

    // Add the transaction node to the linked list
    if (manager->transactions == NULL) {
        manager->transactions = newTransaction;
    } else {
        TransactionNode *current = manager->transactions;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTransaction;
    }

    printf("Debited %.2f from %s category (%s) on %s. Your balance is now %.2f\n", amount, newTransaction->category, newTransaction->name, date, manager->balance);
}

void displayTransactions(FinanceManager *manager) {
    printf("\nTransactions:\n");
    TransactionNode *current = manager->transactions;
    while (current != NULL) {
        printf("%s - Category: %s, Name: %s, Amount: %.2f\n", current->date, current->category, current->name, current->amount);
        current = current->next;
    }
}
