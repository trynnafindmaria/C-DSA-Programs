#include <stdio.h>
#include <stdlib.h>

struct nodetype {
    int INFO;
    struct nodetype *NEXT;
    struct nodetype *PREV;
};

typedef struct nodetype node;
int isEmpty(node *START);
node *insertatbegin(node *START, int item);
node *insertatend(node *START, int item);
node *search(node *START, int value);
void insaftervalue(node *START, int item, int value);
void traversal(node *START);
node *delbeg(node *START);
node *delend(node *START);
node *delhavingvalue(node *START, int value);

void main() {
    node *START = NULL, *loc;
    int choice, item, value;
    do{
        printf("\nMenu (Doubly linked list operations):\n");
        printf("1. Insert node at beginning\n");
        printf("2. Insert node at end\n");
        printf("3. Insert node after the node with given value\n");
        printf("4. Search node\n");
        printf("5. Traverse Linked List\n");
        printf("6. Deletion at beginning\n");
        printf("7. Deletion at end\n");
        printf("8. Deletion of node having given value\n");
        printf("9. Exit\n");

        printf("\nEnterChoice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be stored at the new node: ");
            scanf("%d", &item);
            START = insertatbegin(START, item);
            break;
        case 2:
            printf("Enter the value to be stored at the new node: ");
            scanf("%d",&item);
            START = insertatend(START, item);
            break;
        case 3:
            printf("Enter the value to be stored at the new node: ");
            scanf("%d", &item);
            printf("Enter value of node after which new node to be inserted: ");
            scanf("%d", &value);
            insaftervalue(START, item, value);
            break;
        case 4:
            printf("Enter the value to be searched: ");
            scanf("%d", &value);
            loc = search(START, value);
            if (loc == NULL)
                printf("No such node\n");
            else
                printf("Node found at address %p\n", loc);
            break;
        case 5:
            traversal(START);
            break;
        case 6:
            START = delbeg(START);
            break;
        case 7:
            START = delend(START);
            break;
        case 8:
            printf("Enter value of the node to be deleted: ");
            scanf("%d", &value);
            START = delhavingvalue(START, value);
            break;
        case 9:
            while (START != NULL) {
                node* temp = START;
                START = START->NEXT;
                free(temp);
            }
        }
    } while (choice != 9);
}

int isEmpty(node *START) {
    if (START == NULL)
        return 1;
    return 0;
}

node *insertatbegin(node *START, int item) {
    node *pnew = (node *)malloc(sizeof(node));
    pnew->INFO = item;
    pnew->NEXT = START;
    pnew->PREV = NULL;
    if (START != NULL)
        START->PREV = pnew;
    return pnew;
}

node *insertatend(node *START, int item) {
    node *pnew = (node *)malloc(sizeof(node));
    pnew->INFO = item;
    pnew->NEXT = NULL;

    if (isEmpty(START)) {
        pnew->PREV = NULL;
        return pnew;
    }

    node *p = START;
    while (p->NEXT != NULL)
        p = p->NEXT;
    p->NEXT = pnew;
    pnew->PREV = p;
    return START;
}

node *search(node *START, int value) { 
    node *p = START;
    while (p != NULL) {
        if (p->INFO == value)
            return p;
        else
            p = p->NEXT;
    }
    return NULL;
}

void insaftervalue(node *START, int item, int value) {
    node *loc = search(START, value);
    if (loc == NULL) {
        printf("Node not found - item not inserted\n");
        return;
    }

    node *pnew = (node *)malloc(sizeof(node));
    pnew->INFO = item;
    pnew->NEXT = loc->NEXT;
    pnew->PREV = loc;

    if (loc->NEXT != NULL)
        loc->NEXT->PREV = pnew;

    loc->NEXT = pnew;
}

void traversal(node *START) { 
    node *p = START;
    if (isEmpty(START)) {
        printf("List empty.\n");
        return;
    }

    printf("Contents of doubly linked list:\nSTART<->");
    while (p != NULL) {
        printf("%d ", p->INFO);
        p = p->NEXT;
    }
    printf("\n");
}

node *delbeg(node *START) {
    if (isEmpty(START)) {
        printf("List empty - deletion not possible\n");
        return START;
    }

    node *pdel = START;
    START = START->NEXT;
    if (START != NULL)
        START->PREV = NULL;
    free(pdel);
    printf("Node deleted.\n");
    return START;
}

node *delend(node *START) {
    if (isEmpty(START)) {
        printf("List empty - deletion not possible\n");
        return START;
    }

    if (START->NEXT == NULL)
        return delbeg(START);

    node *p = START;
    while (p->NEXT != NULL)
        p = p->NEXT;

    p->PREV->NEXT = NULL;
    free(p);
    printf("Node deleted.\n");
    return START;
}

node *delhavingvalue(node *START, int value) {
    node *p = search(START, value);
    if (p == NULL) {
        printf("Item not found (No deletion)\n");
        return START;
    }

    if (p->PREV != NULL)
        p->PREV->NEXT = p->NEXT;
    else
        START = p->NEXT;

    if (p->NEXT != NULL)
        p->NEXT->PREV = p->PREV;

    free(p);
    printf("Node deleted.\n");
    return START;
}
