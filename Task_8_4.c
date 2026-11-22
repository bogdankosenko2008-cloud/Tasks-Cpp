#include <stdio.h>
#define MAX_DIM 25
void input_matrix_rows(double mat[MAX_DIM][MAX_DIM], int m, int n) {
    for (int i = 0; i < m; i++) {
        printf("Row %d (enter %d numbers separated by spaces): ", i, n);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }
}
int main() {
    int m, n;
    double mat[MAX_DIM][MAX_DIM];
    printf("Enter the dimensions of the matrix m and n (1 <= m, n < 25): ");
    scanf("%d %d", &m, &n);

    if (m < 1 || m >= MAX_DIM || n < 1 || n >= MAX_DIM) {
        printf("Error: values of m and n must be in the range 1..24.\n");
        return 1;
    }
    input_matrix_rows(mat, m, n);
    printf("\nEntered matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}