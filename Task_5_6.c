#include <stdio.h>
int main() {
    int n;
    double b;
    printf("Enter a natural number n: ");
    scanf("%d", &n);
    printf("Enter a real number b (for part a, b != 0): ");
    scanf("%lf", &b);
    if (n < 1 || b == 0.0) {
        printf("Error: n must be >= 1, and b != 0.\n");
        return 1;
    }

    double res_a = b;
    for (int k = 1; k <= n; k++) {
        res_a = b + 1.0 / res_a;
    }

    double res_b = 4.0 * n + 2.0;
    for (int k = 1; k <= n; k++) {
        res_b = 4.0 * (n - k) + 2.0 + 1.0 / res_b;
    }

    double res_c = 2.0;
    for (int k = 1; k <= 2 * n; k++) {
        double term = (k % 2 != 0) ? 1.0 : 2.0;
        res_c = term + 1.0 / res_c;
    }
    printf("a) b_%d = %lf\n", n, res_a);
    printf("b) lambda_%d = %lf\n", n, res_b);
    printf("c) x_%d = %lf\n", 2 * n, res_c);
    return 0;
}