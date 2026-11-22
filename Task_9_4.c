#include <stdio.h>
#include <stdlib.h>
double** create_matrix_2d(int n) {
    if (n < 1) return NULL;
    double **mat = (double**)calloc(n, sizeof(double*));
    if (mat == NULL) return NULL;
    for (int i = 0; i < n; i++) {
        mat[i] = (double*)calloc(n, sizeof(double));
        if (mat[i] == NULL) {
            // Якщо пам'ять закінчилась посередині — звільняємо вже виділені рядки
            for (int k = 0; k < i; k++) free(mat[k]);
            free(mat);
            return NULL;
        }
    }
    return mat;
}
void free_matrix_2d(double **mat, int n) {
    if (mat == NULL) return;
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

double** input_matrix_2d(int n) {
    double **mat = create_matrix_2d(n);
    if (mat == NULL) return NULL;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("  mat[%d][%d] = ", i, j);
            scanf("%lf", &mat[i][j]);
        }
    }
    return mat;
}
double** multiply_matrices_2d(double **A, int n1, double **B, int n2) {
    if (A == NULL || B == NULL || n1 != n2 || n1 < 1) return NULL;
    double **C = create_matrix_2d(n1);
    if (C == NULL) return NULL;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            for (int k = 0; k < n1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
int main() {
    int n1, n2;

    printf("Enter the dimensionality of the first matrix n1: ");
    scanf("%d", &n1);
    double **A = input_matrix_2d(n1);
    if (A == NULL) {
        printf("Error allocating memory for matrix A.\n");
        return 1;
    }

    printf("Enter the dimensionality of the second matrix n2: ");
    scanf("%d", &n2);
    double **B = input_matrix_2d(n2);
    if (B == NULL) {
        printf("Error allocating memory for matrix B.\n");
        free_matrix_2d(A, n1);
        return 1;
    }

    double **C = multiply_matrices_2d(A, n1, B, n2);
    if (C == NULL) {
        printf("\nProduct impossible: matrix dimensions do not match (%d != %d).\n", n1, n2);
    } else {
        printf("\nProduct of matrices A * B:\n");
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n1; j++) {
                printf("%8.2f ", C[i][j]);
            }
            printf("\n");
        }
        free_matrix_2d(C, n1);
    }
    free_matrix_2d(A, n1);
    free_matrix_2d(B, n2);
    return 0;
}