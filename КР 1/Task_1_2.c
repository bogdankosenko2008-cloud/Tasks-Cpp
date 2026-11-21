#include <stdio.h>
#include <math.h>
int main() {
    float f1 = 1e-4f;
    float f2 = 24.33e5f;
    float f3 = 3.1415926f;
    float f4 = 2.7182818f;
    float f5 = sqrtf(5.0f);
    float f6 = logf(100.0f);

    double d1 = 1e-4;
    double d2 = 24.33e5;
    double d3 = 3.141592653589793;
    double d4 = 2.718281828459045;
    double d5 = sqrt(5.0);
    double d6 = log(100.0);

    long double ld1 = 1e-4L;
    long double ld2 = 24.33e5L;
    long double ld3 = 3.14159265358979323846L;
    long double ld4 = 2.71828182845904523536L;
    long double ld5 = sqrtl(5.0L);
    long double ld6 = logl(100.0L);

    printf("float: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", f1, f2, f3, f4, f5, f6);
    printf("double: %.2lf, %.2lf, %.2lf, %.2lf, %.2lf, %.2lf\n", d1, d2, d3, d4, d5, d6);
    printf("long double: %.2Lf, %.2Lf, %.2Lf, %.2Lf, %.2Lf, %.2Lf\n", ld1, ld2, ld3, ld4, ld5, ld6);
    return 0;
}