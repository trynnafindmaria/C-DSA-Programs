#include <stdio.h>
#define N 10

int linearSearch(int a[], int n, int index, int item);

int main() {
    int a[N], i, item, loc;
    printf("Enter %d integer values:\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("Enter integer value to be searched: ");
    scanf("%d", &item);
    loc = linearSearch(a, N, 0, item);
    if (loc == -1)
        printf("Given value does not occur in the array.\n");
    else
        printf("Given value occurs at loc: %d in the array.\n", loc);
}

int linearSearch(int a[], int n, int index, int item) {
    if (index >= n)
        return -1;
    if (a[index] == item)
        return index;
    return linearSearch(a, n, index + 1, item);
}