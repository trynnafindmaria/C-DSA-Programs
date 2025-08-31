#include <stdio.h>
#define N 10

void bubble_sort(int a[], int n) {
    int pass, i, xchgs, temp;
    for (pass = 1; pass <= n - 1; pass++) {
        xchgs = 0;
        for (i = 0; i <= (n - 1 - pass); i++) {
            if (a[i] > a[i + 1]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                xchgs = 1;
            }
        }
        if (xchgs == 0)
            break;
    }
}
void main() {
    int a[N], i;
    printf("\nEnter %d integer values for sorting:\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    bubble_sort(a, N);
    printf("\nSorted Array:\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
}