#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int** input_int_matrix(int rows, int cols) {
    if (rows < 1 || cols < 1) return NULL;
    int **mat = (int**)malloc(rows * sizeof(int*));
    if (mat == NULL) return NULL;
    for (int i = 0; i < rows; i++) {
        mat[i] = (int*)malloc(cols * sizeof(int));
        if (mat[i] == NULL) {
            for (int k = 0; k < i; k++) free(mat[k]);
            free(mat);
            return NULL;
        }
    }
    printf("Enter the elements of matrix %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("  mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    return mat;
}
void free_int_matrix(int **mat, int rows) {
    if (mat == NULL) return;
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
}
int analyze_matrix(int **mat, int rows, int cols, int *rank, double *det) {
    double **temp = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        temp[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            temp[i][j] = (double)mat[i][j];
        }
    }
    int r = 0;
    double d = 1.0;
    const double EPS = 1e-9;
    for (int col = 0; col < cols && r < rows; col++) {
        int pivot = r;
        for (int i = r + 1; i < rows; i++) {
            if (fabs(temp[i][col]) > fabs(temp[pivot][col])) {
                pivot = i;
            }
        }
        if (fabs(temp[pivot][col]) < EPS) {
            if (rows == cols) d = 0.0;
            continue;
        }
        if (pivot != r) {
            double *swap_row = temp[r];
            temp[r] = temp[pivot];
            temp[pivot] = swap_row;
            d = -d;
        }
        if (rows == cols) {
            d *= temp[r][col];
        }
        for (int i = r + 1; i < rows; i++) {
            double factor = temp[i][col] / temp[r][col];
            for (int j = col; j < cols; j++) {
                temp[i][j] -= factor * temp[r][j];
            }
        }
        r++;
    }
    *rank = r;
    if (rows == cols) {
        *det = (r < rows) ? 0.0 : d;
    }
    for (int i = 0; i < rows; i++) free(temp[i]);
    free(temp);

    return (rows == cols);
}
void print_int_matrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d ", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);
    int **mat = input_int_matrix(rows, cols);
    if (mat == NULL) {
        printf("Error: incorrect dimensions or insufficient memory.\n");
        return 1;
    }
    printf("\nEntered matrix:\n");
    print_int_matrix(mat, rows, cols);
    int rank = 0;
    double det = 0.0;
    int has_det = analyze_matrix(mat, rows, cols, &rank, &det);
    printf("\nRank of the matrix: %d\n", rank);
    if (has_det) {
        printf("Determinant of the matrix: %.2f\n", det);
    } else {
        printf("Determinant: does not exist (the matrix is not square).\n");
    }
    free_int_matrix(mat, rows);
    return 0;
}