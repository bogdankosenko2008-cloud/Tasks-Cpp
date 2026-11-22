#include <stdio.h>
#include <math.h>
int main() {
    double x;
    int n;
    printf("Enter |x| < 1: ");
    scanf("%lf", &x);
    printf("Enter n >= 0: ");
    scanf("%d", &n);
    if (fabs(x) >= 1.0) {
        printf("Error: |x| must be less than 1.\n");
        return 1;
    }
    if (n < 0) {
        printf("Error: n must be a non-negative integer.\n");
        return 1;
    }
    double sum = 1.0;
    double term = 1.0;
    for (int i = 1; i <= n; i++) {
        term *= x / i;
        sum += term;
    }
    printf("y = %lf\n", sum);
    return 0;
}