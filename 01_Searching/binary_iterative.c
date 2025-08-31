#include <stdio.h>
#define N 10

int binary_search(int a[], int n, int item);

void main() {
    int a[N], i, item, loc;
    printf("\nEnter %d integer values in ascending order:\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the integer value to be searched: ");
    scanf("%d", &item);
    loc = binary_search(a, N, item);
    if (loc == -1)
        printf("\nGiven value does not occur in the array\n");
    else
        printf("\nGiven value occurs at loc: %d in the array", loc);
}

int binary_search(int a[], int n, int item) {
    int lb = 0, ub = n - 1, mid;
    while (lb <= ub) {
        mid = lb + (ub - lb) / 2;
        if (item == a[mid])
            return mid;
        else if (item < a[mid])
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    return -1;
}