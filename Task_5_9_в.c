#include <stdio.h>
double calc_v(int n) {
    if (n == 0 || n == 1) return 0.0;
    if (n == 2) return 1.5;
    double v_prev3 = 0.0;
    double v_prev2 = 0.0;
    double v_prev1 = 1.5;
    double v_curr = 0.0;
    for (int i = 3; i <= n; i++) {
        double denom = (i - 3.0) * (i - 3.0) + 1.0;
        v_curr = ((i - 2.0) / denom) * v_prev1 - (v_prev2 * v_prev3) + 1.0;
        v_prev3 = v_prev2;
        v_prev2 = v_prev1;
        v_prev1 = v_curr;
    }
    return v_curr;
}
int main() {
    int n;
    printf("Enter the index of the element n (n >= 0): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("The index of the element must be a non-negative integer (n >= 0).\n");
        return 1;
    }
    printf("v_%d = %lf\n", n, calc_v(n));
    return 0;
}