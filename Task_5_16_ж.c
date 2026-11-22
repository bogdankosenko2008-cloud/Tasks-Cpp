#include <stdio.h>
#include <math.h>
int main() {
    double x, eps;
    printf("Enter x (|x| < 1): ");
    scanf("%lf", &x);
    printf("Enter precision eps (eps > 0): ");
    scanf("%lf", &eps);
    if (fabs(x) >= 1.0 || eps <= 0.0) {
        printf("Error: |x| < 1 and eps > 0 must be satisfied.\n");
        return 1;
    }
    double S = 0.0;
    double a = 2.0 * x;
    int k = 1;
    while (fabs(a) >= eps) {
        S += a;
        k++;
        a = a * (x * x) * (2.0 * k - 3.0) / (2.0 * k - 1.0);
    }
    printf("Approximate value of the sum: %lf\n", S);
    printf("Exact value of ln((1+x)/(1-x)): %lf\n", log((1.0 + x) / (1.0 - x)));
    return 0;
}