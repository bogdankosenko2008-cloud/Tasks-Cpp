#include <stdio.h>

int main() {
    int n;
    int x;
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("Enter value of x: ");
    scanf("%d", &x);
    if (n < 1) {
        printf("Number n must be a positive integer (n >= 1).\n");
        return 1;
    }
    int sum = 0;
    int x_pow = 1;
    for (int i = 1; i <= n; i++) {
        x_pow *= x;
        sum += i * x_pow;
    }
    printf("Result: %d\n", sum);
    return 0;
}