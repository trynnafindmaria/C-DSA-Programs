#include <stdio.h>
#define N 20

struct cqueuetype {
    int q[N];
    int front, rear;
}; typedef struct cqueuetype cqueue;

int isEmpty(int front);
int isFull(int front, int rear);
void cqinsert(cqueue *cq, int item);
int cqdelete(cqueue *cq);
void traverse(cqueue *cq);

int main() {
    cqueue cq;
    cq.front = cq.rear = -1;
    int choice, item;
    do {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter item to insert: ");
            scanf("%d", &item);
            cqinsert(&cq, item);
            break;
        case 2: {
            int deleted = cqdelete(&cq);
            if (deleted != -1)
                printf("Item deleted = %d\n", deleted);
            break;}
        case 3:
            traverse(&cq);
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
int isFull(int front, int rear) {
    return ((front == 0 && rear == N - 1) || (front == rear + 1));
}
void cqinsert(cqueue *cq, int item) {
    if (isFull(cq->front, cq->rear)) {
        printf("Queue Overflow! The circle is full.\n");
        return;
    }
    if (cq->rear == -1)
        cq->rear = cq->front = 0;
    else if (cq->rear == N - 1)
        cq->rear = 0;
    else
        cq->rear++;
    cq->q[cq->rear] = item;
    printf("Inserted %d into the circular queue.\n", item);
}
int cqdelete(cqueue *cq) {
    if (isEmpty(cq->front)) {
        printf("Queue Underflow! Nothing to delete.\n");
        return -1;
    }
    int item = cq->q[cq->front];
    if (cq->front == cq->rear)
        cq->front = cq->rear = -1;
    else if (cq->front == N - 1)
        cq->front = 0;
    else
        cq->front++;
    return item;
}
void traverse(cqueue *cq) {
    if (isEmpty(cq->front)) {
        printf("Queue is empty! Nothing to traverse.\n");
        return;
    }
    printf("\nContents of circular queue:\n");
    if (cq->front <= cq->rear) {
        for (int i = cq->front; i <= cq->rear; i++)
            printf("%d ", cq->q[i]);
    }
    else {
        for (int i = cq->front; i < N; i++)
            printf("%d ", cq->q[i]);
        for (int i = 0; i <= cq->rear; i++)
            printf("%d ", cq->q[i]);
    }
    printf("\n");
}