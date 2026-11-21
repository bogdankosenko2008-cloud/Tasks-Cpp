#include <stdio.h>
#include <math.h>

#define EPS 1e-9

int main() {
    double a, b, c;
    printf("Enter coefficients a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Input error!\n");
        return 1;
    }

    if (fabs(a) < EPS) {
        if (fabs(b) < EPS) {
            if (fabs(c) < EPS) {
                printf("Number of solutions: infinite (any real number)\n");
            } else {
                printf("Number of solutions: 0 (no solutions)\n");
            }
        } else {
            double x = -c / b;
            if (fabs(x) < EPS) x = 0.0;
            printf("Number of solutions: 1\n");
            printf("x = %.4lf\n", x);
        }
        return 0;
    }

    double D = b * b - 4 * a * c;
    if (D < -EPS) {
        printf("Number of solutions: 0 (no real solutions)\n");
    } else if (fabs(D) <= EPS) {
        double x = -b / (2 * a);
        if (fabs(x) < EPS) x = 0.0;
        printf("Number of solutions: 1\n");
        printf("x = %.4lf\n", x);
    } else {
        double x1 = (-b - sqrt(D)) / (2 * a);
        double x2 = (-b + sqrt(D)) / (2 * a);
        if (fabs(x1) < EPS) x1 = 0.0;
        if (fabs(x2) < EPS) x2 = 0.0;
        printf("Number of solutions: 2\n");
        printf("x1 = %.4lf, x2 = %.4lf\n", x1, x2);
    }

    return 0;
}