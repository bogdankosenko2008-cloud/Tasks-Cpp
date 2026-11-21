#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c;
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);
    double p = (a + b + c) / 2;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%lf\n", S);
    return 0;
}