#include <stdio.h>
#define N 10

struct stackop {
    int s[N];
    int top;
}; typedef struct stackop stack;

int isEmpty(int top);
int isFull(int top);
void push(stack *sp, int item);
int pop(stack *sp);
int peek(stack *sp);
void traverse(stack *sp);

int main() {
    int choice, item;
    stack sp;
    sp.top = -1;
    do {
        printf("Menu\n1. Push\n2. Pop\n3. Peek\n4. Traverse\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter item to insert: ");
            scanf("%d", &item);
            push(&sp, item);
            break;
        case 2:
            printf("Popped item = %d\n", pop(&sp));
            break;
        case 3:
            printf("Top item = %d\n", peek(&sp));
            break;
        case 4:
            traverse(&sp);
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}
int isEmpty(int top) {
    if (top == -1)
        return 1;
    return 0;
}
int isFull(int top) {
    if (top == N - 1)
        return 1;
    return 0;
}
void push(stack *sp, int item) {
    if (isFull(sp->top)) {
        printf("Overflow\n");
        return;
    }
    sp->top++;
    sp->s[sp->top] = item;
}
int pop(stack *sp) {
    if (isEmpty(sp->top)) {
        printf("Underflow\n");
        return -1;
    }
    int item = sp->s[sp->top];
    sp->top--;
    return item;
}
int peek(stack *sp) {
    if (isEmpty(sp->top)) {
        printf("Underflow\n");
        return -1;
    }
    return sp->s[sp->top];
}
void traverse(stack *sp) {
    if (isEmpty(sp->top)) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = 0; i <= sp->top; i++) {
        printf("%d ", sp->s[i]);
        if (i == sp->top)
            printf(" <-top");
        printf("\n");
    }
} 