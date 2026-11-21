#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    
    printf("a, b,c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double min_abs = a;
    double max_abs = a;

    if (fabs(b) < fabs(min_abs)) {
        min_abs = b;
    }
    if (fabs(b) > fabs(max_abs)) {
        max_abs = b;
    }

    // Перевіряємо третє число
    if (fabs(c) < fabs(min_abs)) {
        min_abs = c;
    }
    if (fabs(c) > fabs(max_abs)) {
        max_abs = c;
    }

    printf("Min by module: %g\n", min_abs);
    printf("Max by module: %g\n", max_abs);

    return 0;
}