#include <stdio.h>
#define MAX_SIZE 20
void input_matrix_elements(int mat[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void print_matrix(int mat[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int m, n;
    int mat[MAX_SIZE][MAX_SIZE];
    printf("Enter the size of the matrix m and n (1 <= m, n < 20): ");
    scanf("%d %d", &m, &n);

    if (m < 1 || m >= MAX_SIZE || n < 1 || n >= MAX_SIZE) {
        printf("Error: values of m and n must be in the range 1..19.\n");
        return 1;
    }
    input_matrix_elements(mat, m, n);
    printf("\nEntered matrix:\n");
    print_matrix(mat, m, n);
    return 0;
}