#include <stdio.h>
int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i, j;
    int a;
    printf("Enter indices i and j (from 0 to 2): ");
    scanf("%d %d", &i, &j);

    if (i < 0 || i >= 3 || j < 0 || j >= 3) {
        printf("Error: incorrect indices (must be in the range 0..2).\n");
        return 1;
    }
    printf("Enter an integer a: ");
    scanf("%d", &a);
    matrix[i][j] = a;
    printf("New matrix:\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            printf("%d ", (int)matrix[r][c]);
        }
        printf("\n");
    }
    return 0;
}