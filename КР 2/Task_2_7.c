#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
int main() {
    double r1, r2, S;
    printf("r1: ");
    scanf("%lf", &r1);
    printf("r2: ");
    scanf("%lf", &r2);
    S = M_PI * r1 * r2;
    printf("Square: %lf\n", S);
    return 0;
}