#include <stdio.h>
int main() {
    long long m;
    printf("Enter a positive integer m >= 1: ");
    scanf("%lld", &m);
    if (m < 1) {
        printf("Error: m must be a positive integer.\n");
        return 1;
    }
    int k = 0;
    long long power = 1;
    while (power <= m / 4) {
        power *= 4;
        k++;
    }
    printf("Maximum k = %d (4^%d = %lld <= %lld)\n", k, k, power, m);
    return 0;
}