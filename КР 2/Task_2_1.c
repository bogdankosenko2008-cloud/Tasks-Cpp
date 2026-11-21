#include <stdio.h>
#include <math.h>
int main() {
    double x;
    printf("x: ");
    scanf("%lf", &x);
    double result = cos(x);
    printf("%lf\n", result);
    return 0;
}