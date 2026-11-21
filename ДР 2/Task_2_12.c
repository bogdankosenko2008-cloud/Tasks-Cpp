#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
int main() {
    double R, h, S;
    printf("R: ");
    scanf("%lf", &R);
    printf("h: ");
    scanf("%lf", &h);
    S = (M_PI * pow(R, 2) * h)/3.0;
    printf("Square: %lf\n", S);
    return 0;
}