#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// а)
double taylor_exp(double x, double eps) {
    double sum = 0.0;
    double term = 1.0;
    int k = 1;
    while (fabs(term) >= eps) {
        sum += term;
        term *= x / k;
        k++;
    }
    return sum;
}

// б)
double taylor_phi(double x, double eps) {
    double sum = 0.0;
    double t = x;
    double term = x;
    int k = 1;
    while (fabs(term) >= eps) {
        sum += term;
        t = -t * (x * x) / k;
        term = t / (2.0 * k + 1.0);
        k++;
    }
    return sum;
}
int main() {
    double x, eps;
    printf("Enter an argument x: ");
    scanf("%lf", &x);
    printf("Enter a positive tolerance eps (e.g., 1e-6): ");
    scanf("%lf", &eps);

    if (eps <= 0.0) {
        printf("Tolerance eps must be positive.\n");
        return 1;
    }

    // Пункт а)
    double my_exp = taylor_exp(x, eps);
    double std_exp = exp(x);
    printf("\na) e^%lf:\n", x);
    printf("For Taylor series: %lf\n", my_exp);
    printf("Standard exp(): %lf\n", std_exp);
    printf("Difference: %.2e\n", fabs(my_exp - std_exp));

    // Пункт б)
    double my_phi = taylor_phi(x, eps);
    double std_phi = (sqrt(M_PI) / 2.0) * erf(x);
    printf("\nb) Phi(%lf):\n", x);
    printf("For Taylor series: %lf\n", my_phi);
    printf("Standard Phi(): %lf\n", std_phi);
    printf("Difference: %.2e\n", fabs(my_phi - std_phi));

    return 0;
}