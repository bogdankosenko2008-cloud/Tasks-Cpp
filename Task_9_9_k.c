#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double** create_matrix(int N, int M) {
    if (N < 1 || M < 1) return NULL;

    double **mat = (double**)malloc(N * sizeof(double*));
    if (mat == NULL) return NULL;

    for (int i = 0; i < N; i++) {
        mat[i] = (double*)malloc(M * sizeof(double));
        if (mat[i] == NULL) {
            for (int r = 0; r < i; r++) free(mat[r]);
            free(mat);
            return NULL;
        }
    }
    return mat;
}
void free_matrix(double ***mat, int *N, int *M) {
    if (mat == NULL || *mat == NULL) return;
    for (int i = 0; i < *N; i++) {
        free((*mat)[i]);
    }
    free(*mat);
    *mat = NULL;
    *N = 0;
    *M = 0;
}
void print_matrix(double **mat, int N, int M) {
    if (mat == NULL || N <= 0 || M <= 0) {
        printf("The matrix is empty.\n");
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%7.2f ", mat[i][j]);
        }
        printf("\n");
    }
}
int delete_column(double ***mat, int *N, int *M, int k) {
    if (mat == NULL || *mat == NULL || *N <= 0 || *M <= 0) {
        printf("Error: The matrixis empty.\n");
        return 0;
    }
    if (k < 0 || k >= *M) {
        printf("Error: the incorrect number of k = %d (aviable from 0 to %d).\n", k, *M - 1);
        return 0;
    }
    if (*M == 1) {
        free_matrix(mat, N, M);
        return 1;
    }
    int new_M = *M - 1;
    for (int i = 0; i < *N; i++) {
        for (int j = k; j < new_M; j++) {
            (*mat)[i][j] = (*mat)[i][j + 1];
        }
        double *resized_row = (double*)realloc((*mat)[i], new_M * sizeof(double));
        if (resized_row != NULL) {
            (*mat)[i] = resized_row;
        }
    }
    *M = new_M;
    return 1;
}
int main() {
    int N, M, choice, k;
    printf("Enter size of matrix N (rows) and M (coloums): ");
    scanf("%d %d", &N, &M);
    double **mat = create_matrix(N, M);
    if (mat == NULL) {
        printf("Error: incorrect size or memory leak.\n");
        return 1;
    }
    printf("Choose the variant of filling (1 - random numbers, 2 - from console): ");
    scanf("%d", &choice);
    if (choice == 1) {
        srand((unsigned int)time(NULL));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                mat[i][j] = ((rand() % 2001) - 1000) / 100.0;
            }
        }
    } else {
        printf("Enter elements of matrix %dx%d:\n", N, M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("  mat[%d][%d] = ", i, j);
                scanf("%lf", &mat[i][j]);
            }
        }
    }
    printf("\nStart matrix (%dx%d):\n", N, M);
    print_matrix(mat, N, M);
    printf("\nEnter number of coloum k for delete (from 0 to %d): ", M - 1);
    scanf("%d", &k);

    if (delete_column(&mat, &N, &M, k)) {
        printf("\nMatrix after deleting of coloums %d (%dx%d):\n", k, N, M);
        print_matrix(mat, N, M);
    }
    free_matrix(&mat, &N, &M);
    return 0;
}