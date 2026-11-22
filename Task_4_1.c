#include <stdio.h>
#include <math.h>
int main() {
    double x;
    int n;
    printf("Enter the argument x (in radians): ");
    scanf("%lf", &x);
    printf("Enter the number of repetitions n: ");
    scanf("%d", &n);
    double result = x;
    for (int i = 0; i < n; i++) {
        result = sin(result);
    }
    printf("Result after %d applications of sin: %lf\n", n, result);
    return 0;
}