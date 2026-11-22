#include <stdio.h>
#include <math.h>
double poly_a(double x, int n) {
    double sum = 1.0;
    double term = 1.0;
    for (int i = 1; i <= n; i++) {
        term *= x;
        sum += term;
    }
    return sum;
}
double poly_b(double x, double y, int n) {
    double sum = 1.0;
    for (int i = 1; i <= n; i++) {
        double term = pow(x, pow(2, i)) * pow(y, i);
        sum += term;
    }
    return sum;
}
int main() {
    int n_a = 3;
    double x_a = 2.0;
    printf("a) For n = %d, x = %.2f: y = %.2f\n", n_a, x_a, poly_a(x_a, n_a));

    int n_b = 4;
    double x_b = 1.0, y_b = 2.0;
    printf("b) For n = %d, x = %.2f, y = %.2f: y = %.2f\n", n_b, x_b, y_b, poly_b(x_b, y_b, n_b));

    return 0;
}