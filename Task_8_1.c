#include <stdio.h>
int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int N, M;
    printf("Enter positive integers N and M: ");
    scanf("%d %d", &N, &M);
    if (N < 1 || M < 1) {
        printf("Numbers N and M must be positive integers (>= 1).\n");
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == M) {
                matrix[i][j] = N;
            }
        }
    }
    printf("New matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}