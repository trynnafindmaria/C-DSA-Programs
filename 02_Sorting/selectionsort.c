#include <stdio.h>
#define N 10

void sel_sort(int a[], int n);

int main() {
    int a[N], i;
    printf("\nEnter %d integer values for sorting:\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    sel_sort(a, N);
    printf("\nSorted Array:\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
}

void sel_sort(int a[], int n){
    int pass, loc_min, i, temp;
    for (pass = 1; pass < n - 1; pass++){
        loc_min = pass - 1;
        for (i = pass; i < n - 1; i++) {
            if (a[i] < a[loc_min])
                loc_min = i;
        }
        if (loc_min != (pass - 1)) {
            temp = a[pass - 1];
            a[pass - 1] = a[loc_min];
            a[loc_min] = temp;
        }
    }
}