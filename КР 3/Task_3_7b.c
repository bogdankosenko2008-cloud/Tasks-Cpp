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

    // Випадок a == 0 (рівняння зводиться до bx^2 + c = 0)
    if (fabs(a) < EPS) {
        if (fabs(b) < EPS) {
            if (fabs(c) < EPS) {
                printf("Number of solutions: infinite (any real number)\n");
            } else {
                printf("Number of solutions: 0 (no solutions)\n");
            }
        } else {
            double t = -c / b;
            if (t < -EPS) {
                printf("Number of solutions: 0\n");
            } else if (fabs(t) <= EPS) {
                printf("Number of solutions: 1\n");
                printf("x = 0.0000\n");
            } else {
                double x = sqrt(t);
                printf("Number of solutions: 2\n");
                printf("x1 = %.4lf, x2 = %.4lf\n", -x, x);
            }
        }
        return 0;
    }

    // Випадок a != 0
    double D = b * b - 4 * a * c;

    if (D < -EPS) {
        printf("Number of solutions: 0 (no real solutions)\n");
        return 0;
    }

    double roots[4];
    int count = 0;

    if (fabs(D) <= EPS) {
        double t = -b / (2 * a);
        if (fabs(t) <= EPS) {
            roots[count++] = 0.0;
        } else if (t > EPS) {
            roots[count++] = -sqrt(t);
            roots[count++] = sqrt(t);
        }
    } else {
        double t[2] = {
            (-b - sqrt(D)) / (2 * a),
            (-b + sqrt(D)) / (2 * a)
        };

        for (int i = 0; i < 2; i++) {
            if (fabs(t[i]) <= EPS) {
                roots[count++] = 0.0;
            } else if (t[i] > EPS) {
                roots[count++] = -sqrt(t[i]);
                roots[count++] = sqrt(t[i]);
            }
        }
    }

    printf("Number of solutions: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("x%d = %.4lf\n", i + 1, roots[i]);
    }

    return 0;
}