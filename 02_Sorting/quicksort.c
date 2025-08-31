#include <stdio.h> 
#define N 10

int partition(int a[], int lb, int ub);
void quicksort(int a[], int lb, int ub);

void main() {
    int a[N], i;
    printf("\nEnter %d integer values for sorting:\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, N - 1);
    printf("\nSorted Array:\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
}

void quicksort(int a[], int lb, int ub) {
    int j;
    if (lb < ub) {
        j = partition(a, lb, ub);
        quicksort(a, lb, j - 1);
        quicksort(a, j + 1, ub);
    }
}
int partition(int a[], int lb, int ub) {
    int i, j, key, temp;
    i = lb + 1;
    j = ub;
    key = a[lb];
    while (i <= j) {
        while (a[i] < key && i <= j)
            i++; 
        while (a[j] > key)
            j--; 
        if (i < j) {
            temp = a[i]; 
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        else
            break;
    }
    temp = a[lb]; 
    a[lb] = a[j]; 
    a[j] = temp;
    return j;
}
