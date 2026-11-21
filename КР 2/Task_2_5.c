#include <stdio.h>
#include <math.h>
double Rosenbrock2d(double x, double y) {
    return 100 * pow(x * x - y, 2) + pow(x - 1, 2);
}
int main() {
    double x1, x2, x3, y1, y2, y3;
    x1 = 2.0; x2 = 4.0; x3 = 11.0;
    y1 = 11.0; y2 = 7.0; y3 = 5.0;
    double z1 = Rosenbrock2d(x1, y1);
    double z2 = Rosenbrock2d(x2, y2);
    double z3 = Rosenbrock2d(x3, y3);
    printf("z1 = %lf\n", z1);
    printf("z2 = %lf\n", z2);
    printf("z3 = %lf\n", z3);
    return 0;
}