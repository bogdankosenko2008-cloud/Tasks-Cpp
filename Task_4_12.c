#include <stdio.h>
int main() {
    int n;
    printf("Enter a positive integer n (n < 25): ");
    scanf("%d", &n);
    if (n < 1 || n >= 25) {
        printf("Error: n should be a positive integer less than 25.\n");
        return 1;
    }
    double subfact = 1.0;
    int sign = -1;
    for (int i = 1; i <= n; i++) {
        subfact = i * subfact + sign;
        sign = -sign;
    }
    printf("!%d = %.0f\n", n, subfact);
    return 0;
}