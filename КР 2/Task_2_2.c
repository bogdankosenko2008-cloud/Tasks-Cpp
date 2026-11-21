#include <stdio.h>
#include <math.h>
int main() {
    double a, b;
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    double c = sqrt(a * a + b * b);
    printf("%lf\n", c);
    return 0;
}