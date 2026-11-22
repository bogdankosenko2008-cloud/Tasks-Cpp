#include <stdio.h>
#include <stdlib.h>
double* input_vector(int n) {
    if (n < 1) return NULL;
    double *vec = (double*)malloc(n * sizeof(double));
    if (vec == NULL) return NULL;
    for (int i = 0; i < n; i++) {
        printf("element [%d] = ", i);
        scanf("%lf", &vec[i]);
    }
    return vec;
}
void free_vector(double *vec) {
    free(vec);
}
double* subtract_vectors(const double *v1, int n1, const double *v2, int n2) {
    if (v1 == NULL || v2 == NULL || n1 != n2 || n1 < 1) {
        return NULL;
    }
    double *diff = (double*)malloc(n1 * sizeof(double));
    if (diff == NULL) return NULL;
    for (int i = 0; i < n1; i++) {
        diff[i] = v1[i] - v2[i];
    }
    return diff;
}
int main() {
    int n1, n2;
    printf("Enter the dimensionality of the first vector n1: ");
    scanf("%d", &n1);
    double *v1 = input_vector(n1);
    if (v1 == NULL) {
        printf("Error creating the first vector.\n");
        return 1;
    }

    printf("Enter the dimensionality of the second vector n2: ");
    scanf("%d", &n2);
    double *v2 = input_vector(n2);
    if (v2 == NULL) {
        printf("Error creating the second vector.\n");
        free_vector(v1); // Очищуємо v1 перед виходом!
        return 1;
    }

    double *diff = subtract_vectors(v1, n1, v2, n2);
    if (diff == NULL) {
        printf("\nError calculating the difference: vector dimensions do not match (%d != %d).\n", n1, n2);
    } else {
        printf("\nDifference of vectors: (");
        for (int i = 0; i < n1; i++) {
            printf("%.2f%s", diff[i], (i < n1 - 1) ? ", " : "");
        }
        printf(")\n");
        free_vector(diff);
    }
    free_vector(v1);
    free_vector(v2);
    return 0;
}