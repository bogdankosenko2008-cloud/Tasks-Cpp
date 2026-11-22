#include <stdio.h>
#define MAX_SIZE 50
void rotate_180(double mat[MAX_SIZE][MAX_SIZE], int size) {
    int half = size / 2; // дорівнює n
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < size; j++) {
            int opp_i = size - 1 - i;
            int opp_j = size - 1 - j;

            double temp = mat[i][j];
            mat[i][j] = mat[opp_i][opp_j];
            mat[opp_i][opp_j] = temp;
        }
    }
}
void print_matrix(double mat[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%6.2f ", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    double mat[MAX_SIZE][MAX_SIZE];
    printf("Enter n (order of the matrix 2n <= %d): ", MAX_SIZE);
    scanf("%d", &n);
    int size = 2 * n;
    if (n < 1 || size > MAX_SIZE) {
        printf("Error: n must be >= 1, and 2n <= %d.\n", MAX_SIZE);
        return 1;
    }
    printf("Enter the elements of the %dx%d matrix:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%lf", &mat[i][j]);
        }
    }
    printf("\nOriginal matrix:\n");
    print_matrix(mat, size);
    rotate_180(mat, size);
    printf("\nMatrix after rotating by 180 degrees:\n");
    print_matrix(mat, size);
    return 0;
}