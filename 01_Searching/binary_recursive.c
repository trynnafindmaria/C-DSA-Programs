#include <stdio.h>
#define N 10

int rec_binary_search(int a[], int lb, int ub, int item);

void main() {
    int a[N], i, item, loc;
    printf("\nEnter %d integer values in ascending order:\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the integer value to be searched: ");
    scanf("%d", &item);
    loc = rec_binary_search(a, 0, N - 1, item);
    if (loc == -1)
        printf("\nGiven value does not occur in the array\n");
    else
        printf("\nGiven value occurs at loc: %d in the array", loc);
}

int rec_binary_search(int a[], int lb, int ub, int item) {
    if (lb > ub)
        return -1;
    int mid = lb + (ub - lb) / 2;
    if (item == a[mid])
        return mid;
    else if (item < a[mid])
        return rec_binary_search(a, lb, mid - 1, item);
    else
        return rec_binary_search(a, mid + 1, ub, item);
}