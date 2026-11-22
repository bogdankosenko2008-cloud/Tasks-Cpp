#include <stdio.h>
#define MAX_DIM 100
int main() {
    int N, M, k;
    double A[MAX_DIM][MAX_DIM];
    printf("Enter the dimensions of the matrix N and M (1 <= N, M < 100): ");
    scanf("%d %d", &N, &M);
    if (N < 1 || N >= MAX_DIM || M < 1 || M >= MAX_DIM) {
        printf("Error: N and M must be in the range 1..99.\n");
        return 1;
    }
    printf("Enter the elements of matrix A[%d][%d]:\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Enter an integer k: ");
    scanf("%d", &k);
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        int j = i - k;
        if (j >= 0 && j < M) {
            sum += A[i][j];
        }
    }
    printf("Sum of elements for which i - j = %d: %.4f\n", k, sum);
    return 0;
}