#include <stdio.h>
int main() {
    int n;
    printf("Enter a natural number n: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Number n must be a natural number (n >= 1).\n");
        return 1;
    }
    double a_prev2 = 0.0, a_prev1 = 1.0;
    double b_prev2 = 1.0, b_prev1 = 0.0;
    double pow2 = 2.0;
    double sum = 0.0;
    for (int k = 1; k <= n; k++) {
        double a_curr, b_curr;
        if (k == 1) {
            a_curr = a_prev2;
            b_curr = b_prev2;
        } else if (k == 2) {
            a_curr = a_prev1;
            b_curr = b_prev1;
        } else {
            b_curr = b_prev1 + a_prev1;
            a_curr = (a_prev1 / k) + a_prev2 * b_curr;
            a_prev2 = a_prev1;
            a_prev1 = a_curr;
            b_prev2 = b_prev1;
            b_prev1 = b_curr;
        }
        sum += pow2 / (a_curr + b_curr);
        pow2 *= 2.0;
    }
    printf("S_%d = %lf\n", n, sum);
    return 0;
}