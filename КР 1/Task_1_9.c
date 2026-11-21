#include <stdio.h>
int main() {
    double a, b;
    printf("a and b: ");
    scanf("%lf %lf", &a, &b);
    double arith_mean = (a + b) / 2.0;
    double harm_mean = (2.0 * a * b) / (a + b);
    printf("Middle mean : %lf\n", arith_mean);
    printf("Harmonic mean:  %lf\n", harm_mean);
  
    printf("Middle mean : %e\n", arith_mean);
    printf("Harmonic mean:  %e\n", harm_mean);
    return 0;
}