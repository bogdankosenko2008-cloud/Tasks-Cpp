#include <stdio.h>
#include <math.h>
#define MAX_N 20
double determinant(double mat[MAX_N][MAX_N], int n) {
    double det = 1.0;
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int r = i + 1; r < n; r++) {
            if (fabs(mat[r][i]) > fabs(mat[pivot][i])) {
                pivot = r;
            }
        }
        if (fabs(mat[pivot][i]) < 1e-12) {
            return 0.0;
        }
        if (pivot != i) {
            for (int c = i; c < n; c++) {
                double temp = mat[i][c];
                mat[i][c] = mat[pivot][c];
                mat[pivot][c] = temp;
            }
            det = -det;
        }
        det *= mat[i][i];
        for (int r = i + 1; r < n; r++) {
            double factor = mat[r][i] / mat[i][i];
            for (int c = i + 1; c < n; c++) {
                mat[r][c] -= factor * mat[i][c];
            }
        }
    }
    return det;
}

int main() {
    int n;
    double mat[MAX_N][MAX_N];
    printf("Enter the size of the square matrix n (1 <= n <= 20): ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_N) {
        printf("Error: the size n must be in the range 1..20.\n");
        return 1;
    }
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%lf", &mat[i][j]);
        }
    }
    double det = determinant(mat, n);
    printf("Determinant of the matrix: %.4f\n", det);
    return 0;
}