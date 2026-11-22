#include <stdio.h>
int main() {
    double a;
    printf("Enter a real number a: ");
    scanf("%lf", &a);
    double sum = 0.0;
    int n = 0;
    while (sum <= a) {
        n++;
        sum += 1.0 / n;
    }
    printf("a) First number in the sequence, greater than %lf: %lf\n", a, sum);
    printf("b) Smallest n > 0: %d\n", n);
    return 0;
}