#include <stdio.h>
#include <math.h>
int main() {
    double n;
    printf("n: ");
    if (scanf("%lf", &n) != 1 || n <= 0) {
        printf("error.\n");
        return 1;
    }
    double result = log10(n);
    printf("log10(%.3f) = %.3f\n", n, result);
    return 0;
}