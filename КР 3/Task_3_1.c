#include <stdio.h>
int main() {
    int a, a1, a2, a3, sum, reverse;
    printf("a: ");
    scanf("%d", &a);
    a1 = a / 100;
    a2 = (a / 10) % 10;
    a3 = a % 10;
    sum = a1 + a2 + a3;
    reverse = a3 * 100 + a2 * 10 + a1;
    printf("Digits: %d, %d, %d\n", a1, a2, a3);
    printf("Sum: %d\n", sum);
    printf("Reverse number: %d\n", reverse);
    return 0;
}