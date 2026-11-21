#include <stdio.h>
int main() {
    double C, F;
    printf("C= ");
    scanf("%lf", &C);
    F = (9.0 / 5.0) * C + 32.0;
    printf("F=%g\n", F);
    return 0;
}
