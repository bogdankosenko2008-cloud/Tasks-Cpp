#include <stdio.h>
#define MAX_N 20
void transpose_matrix(double mat[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}
void print_square_matrix(double mat[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.2f ", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n = 3;
    double mat[MAX_N][MAX_N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printf("Original matrix:\n");
    print_square_matrix(mat, n);
    transpose_matrix(mat, n);
    printf("\nTransposed matrix:\n");
    print_square_matrix(mat, n);
    return 0;
}