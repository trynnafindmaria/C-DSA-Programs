#include <stdio.h>
#define N 20

struct queuetype {
    int q[N];
    int front, rear;
}; typedef struct queuetype queue;

int isEmpty(int front);
int isFull(int rear);
void qinsert(queue *q, int item);
int qdelete(queue *q);
void traverse(queue *q);

int main() {
    queue q;
    q.front = q.rear = -1;
    int choice, item;
    do {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter item to insert: ");
            scanf("%d", &item);
            qinsert(&q, item);
            break;
        case 2: {
            int deleted = qdelete(&q);
            if (deleted != -1)
                printf("Item deleted = %d\n", deleted);
            break;}
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
int isEmpty(int front) {
    return (front == -1);
}
int isFull(int rear) {
    return (rear == N - 1);
}
void qinsert(queue *q, int item) {
    if (isFull(q->rear)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->rear == -1)
        q->rear = q->front = 0;
    else
        q->rear++;
    q->q[q->rear] = item;
    printf("Inserted %d into the linear queue.\n", item);
}
int qdelete(queue *q) {
    if (isEmpty(q->front)) {
        printf("Queue Underflow! Nothing to delete.\n");
        return -1;
    }
    int item = q->q[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}
void traverse(queue *q) {
    if (isEmpty(q->front)) {
        printf("Queue is empty! Nothing to traverse.\n");
        return;
    }
    printf("\nContents of linear queue:\n");
    if (q->front <= q->rear) {
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ", q->q[i]);
    }
    printf("\n");
}