#include <stdio.h>
int poly_b(int x, int n) {
    int sum = 1;
    int term = x * x * x;
    for (int i = 1; i <= n; i++) {
        sum += term;
        term = term * term * term;
    }
    return sum;
}
int main() {
    int x;
    int n;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Error: n must be a positive integer (n >= 1).\n");
        return 1;
    }
    int result = poly_b(x, n);
    printf("y = %d\n", result);
    return 0;
}