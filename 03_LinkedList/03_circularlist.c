#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;
node *last = NULL;

void create(int data);
void insertAtBeginning(int data);
void insertAtPosition(int data, int pos);
void insertAtEnd(int data);
void traverse(void);
void deleteNode(int key);
void freelist(void);

int main() {
    int choice, data, pos;
    do {
        printf("\nMenu:\n1. Create\n2. Insert at beginning\n3. Insert at position\n4. Insert at End\n5. Delete\n6. Traverse\n7. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (last != NULL) {
                printf("List already created. Use insert option.\n");
            } else {
                printf("Enter data to create list: ");
                scanf("%i", &data);
                create(data);
            }
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%i", &data);
            insertAtBeginning(data);
            break;
        case 3:
            printf("Enter data and position to insert: ");
            scanf("%i %d", &data, &pos);
            insertAtPosition(data, pos);
            break;
        case 4:
            printf("Enter data to insert: ");
            scanf("%i", &data);
            insertAtEnd(data);
            break;
        case 5:
            printf("Enter data to delete: ");
            scanf("%i", &data);
            deleteNode(data);
            break;
        case 6:
            traverse();
            break;
        case 7:
            freelist();
            break;
        }
    } while (choice != 7);
}

void create(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = newNode;
    last = newNode;
}

void insertAtBeginning(int data) {
    if (last == NULL) {
        create(data);
        return;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
}

void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    node *temp = last->next;  // Start from the first node

    int count = 1;
    while (count < position - 1 && temp != last) {
        temp = temp->next;
        count++;
    }

    if (count != position - 1) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == last) { 
        last = newNode;
    }
}

void insertAtEnd(int data) {
    if (last == NULL) {
        create(data);
        return;
    }
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

void traverse(void) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = last->next;
    printf("Circular Linked List:\n");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
     } while (temp != last->next);
     printf("\n");
}

void deleteNode(int key) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *curr = last->next, *prev = last;

    if (curr == last && curr->data == key) { // If the list has only one node
        free(curr);
        last = NULL;
        return;
    }
    
    if (curr->data == key) { // If the first node is to be deleted
        last->next = curr->next;
        free(curr);
        return;
    }

    while (curr != last) { // traversing the list to find the node to be deleted
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    
    if (curr->data == key) { // If the last node is to be deleted
        prev->next = curr->next;
        last = prev;
        free(curr);
        return;
    }

    printf("Node with value %d is not found.\n", key);   
}

void freelist(void) {
    if (last == NULL) return;
    node *curr = last->next, *temp;
    while (curr != last) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(last);
    last = NULL;
}