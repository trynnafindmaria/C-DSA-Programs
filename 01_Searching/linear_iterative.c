#include <stdio.h>
#define N 10

int linearSearch(int a[], int n, int item);

int main() {
    int a[N], i, item, loc;
    printf("Enter %d integer values:\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("Enter integer value to be searched: ");
    scanf("%d", &item);
    loc = linearSearch(a, N, item);
    if (loc == -1)
        printf("Given value does not occur in the array.\n");
    else
        printf("Given value occurs at loc: %d in the array.\n", loc);
}

int linearSearch(int a[], int n, int item) {
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == item)
            return i;
return -1;
}