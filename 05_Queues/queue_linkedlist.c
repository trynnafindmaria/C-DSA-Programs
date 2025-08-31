#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}; typedef struct node Node;

struct queuetype {
    Node *front, *rear;
};
typedef struct queuetype queue;

int isEmpty(queue *q);
void insert(queue *q, int item);
int delete(queue *q);
void traverse(queue *q);

int main() {
    queue q;
    q.front = q.rear = NULL;
    int choice, item;
    do {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item to insert: ");
            scanf("%d", &item);
            insert(&q, item);
            break;
        case 2: {
            int deleted = delete(&q);
            if (deleted != -1)
                printf("Item deleted = %d\n", deleted);
            break;
        }
        case 3:
            traverse(&q);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Try again!\n");
            break;
        }
    } while (choice != 4);
}
int isEmpty(queue *q) {
    return (q->front == NULL);
}
void insert(queue *q, int item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Overflow! Cannot insert.\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Inserted %d into the queue.\n", item);
}
int delete(queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Nothing to delete.\n");
        return -1;
    }
    Node *temp = q->front;
    int item = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return item;
}
void traverse(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to traverse.\n");
        return;
    }
    printf("\nContents of the queue:\n");
    Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
