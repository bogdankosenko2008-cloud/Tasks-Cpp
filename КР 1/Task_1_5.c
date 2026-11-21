#include <stdio.h>

int main() {
    double x;
    scanf("%lf", &x);
    // а) x^4 за дві операції
    double x2 = x * x;
    double x4 = x2 * x2;
    // б) x^6 за три операції (x2 вже є: 1 операція)
    double x6 = x4 * x2;
    // в) x^9 за чотири операції
    double x8 = x4 * x4;
    double x9 = x8 * x;
    // г) x^15 за п'ять операцій
    double x3 = x2 * x;
    double x6_g = x3 * x3;
    double x12 = x6_g * x6_g;
    double x15 = x12 * x3;
    // Чистий ланцюжок для д) у 6 операцій:
    double d_x2 = x * x;
    double d_x3 = d_x2 * x;
    double d_x4 = d_x2 * d_x2;
    double d_x7 = d_x4 * d_x3;
    double d_x14 = d_x7 * d_x7;
    double d_x28 = d_x14 * d_x14;
    // е) x^64 за шість операцій (послідовне піднесення до квадрату)
    double e_x2 = x * x;
    double e_x4 = e_x2 * e_x2;
    double e_x8 = e_x4 * e_x4;
    double e_x16 = e_x8 * e_x8;
    double e_x32 = e_x16 * e_x16;
    double e_x64 = e_x32 * e_x32;
    printf("a) x^4  = %g\n", x4);
    printf("b) x^6  = %g\n", x6);
    printf("v) x^9  = %g\n", x9);
    printf("g) x^15 = %g\n", x15);
    printf("d) x^28 = %g\n", d_x28);
    printf("e) x^64 = %g\n", e_x64);
    return 0;
}