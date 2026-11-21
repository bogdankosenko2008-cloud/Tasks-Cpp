#include <stdio.h>
#include <math.h>
double calc_polynomial(double x) {
    double t = 2.0 * x;
    double t2 = pow(t, 2);
    return (t2 + 1.0) * (t2 + t) + 1.0;
}
int main() {
    double x;
    printf("x: ");
    scanf("%lf", &x);
    double y = calc_polynomial(x);
    printf("y = %lf\n", y);
    return 0;
}