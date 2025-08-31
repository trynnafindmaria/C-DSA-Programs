#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
}; typedef struct node node;
node* top = NULL;

int isEmpty();
void push(int item);
int pop();
int peek();
void traverse();

int main() {
    int choice, item;
    do {
        printf("\nMenu\n1. Push\n2. Pop\n3. Peek\n4. Traverse\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                printf("Popped item = %d\n", pop());
                break;
            case 3:
                printf("Top item = %d\n", peek());
                break;
            case 4:
                traverse();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    while (!isEmpty()) {
        pop();
    }
}
int isEmpty() {
    return top == NULL;
}
void push(int item) {
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Overflow condition.\n");
        return;
    }
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}
int pop() {
    if (isEmpty()) {
        printf("Underflow\n");
        return -1;
    }
    node *temp = top;
    int poppedItem = temp->data;
    top = top->next;
    free(temp);
    return poppedItem;
}
int peek() {
    if (isEmpty()) {
        printf("Underflow\n");
        return -1;
    }
    return top->data;
}
void traverse() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    node *current = top;
    printf("Stack elements:\n");
    while (current != NULL) {
        printf("%d", current->data);
        if (current == top) {
            printf(" <-top");
        }
        printf("\n");
        current = current->next;
    }
}
