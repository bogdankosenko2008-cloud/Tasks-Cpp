#include <stdio.h>
#include <math.h>
#include <float.h>
double softPlus(double x) {
    return log(1.0 + exp(x));
}
double softPlus_derivative(double x) {
    double h = cbrt(DBL_EPSILON) * fmax(fabs(x), 1.0);
    return (softPlus(x + h) - softPlus(x - h)) / (2.0 * h);
}
int main() {
    double x;
    printf("x: ");
    scanf("%lf", &x);
    printf("softPlus(x) = %.6f\n", softPlus(x));
    printf("softPlus_derivative(x) = %lf\n", softPlus_derivative(x));
    return 0;
}