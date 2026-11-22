#include <stdio.h>
int main() {
    int n;
    printf("Enter a natural number n: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Number n must be a natural number (n >= 1).\n");
        return 1;
    }

    double P_a = 1.0;
    double inv_fact = 1.0;
    for (int k = 1; k <= n; k++) {
        inv_fact /= k;
        double a_k = 1.0 + inv_fact;
        P_a *= a_k;
    }

    double P_b = 1.0;
    double sign_pow2 = 1.0;
    for (int k = 1; k <= n; k++) {
        if (k == 1) {
            sign_pow2 = 0.5;
        } else {
            sign_pow2 *= -0.5;
        }
        double a_k = 1.0 + sign_pow2 * (k * k);
        P_b *= a_k;
    }
    printf("a) P_%d = %lf\n", n, P_a);
    printf("b) P_%d = %lf\n", n, P_b);
    return 0;
}