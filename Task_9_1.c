#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter a natural number n: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("The number n must be a natural number (n >= 1).\n");
        return 1;
    }
    double *arr = (double *)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }
    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%lf", &arr[i]);
    }
    double sum_sq = 0.0;
    for (int i = 0; i < n; i++) {
        sum_sq += arr[i] * arr[i];
    }
    printf("Sum of squares of array elements: %.4f\n", sum_sq);
    free(arr);
    return 0;
}