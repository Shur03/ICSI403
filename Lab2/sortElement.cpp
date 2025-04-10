#include <stdio.h>

int main() {
    int N, i, j, el;
    printf("Enter array elements number: ");
    scanf("%d", &N);   
    int a[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < N; i++) {
        el = a[i];
        j = i - 1;
        for ( j >= 0 && a[j] > el; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = el;

        printf("After inserting element %d: ", el);
        for (int k = 0; k < N; k++) {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
    printf("Sorted array: ");
    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
