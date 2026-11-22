#include <stdio.h>
int main() {
    long long n;
    printf("Enter a positive integer n: ");
    scanf("%lld", &n);
    if (n < 1) {
        printf("Error: n must be a positive integer.\n");
        return 1;
    }
    long long res = 1;
    int r = 0;
    while (res <= n) {
        res *= 2;
        r++;
    }
    printf("The smallest number: %lld (2^%d > %lld)\n", res, r, n);
    return 0;
}