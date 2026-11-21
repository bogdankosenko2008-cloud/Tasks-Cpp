#include <stdio.h>
#include <math.h>
int main() {
    double m1, m2, r, F;
    const double G = 6.67430e-11;
    scanf("%lf %lf %lf", &m1, &m2, &r);
    F = (G * m1 * m2) / (r * r);
    printf("F = %lf or %e\n", F, F);
    return 0;
}