#include <stdio.h>
double calc_polynomial(double x) {
    double x2 = x * x;
    double x3 = x2 * x;
    double x6 = x3 * x3; 
    double x9 = x6 * x3;
    return x9 + x3 + 1.0;
}
int main() {
    double x;
    printf("Enter the value of x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Error: invalid input!\n");
        return 1;
    }
    double y = calc_polynomial(x);
    printf("y = %.4lf\n", y);
    return 0;
}