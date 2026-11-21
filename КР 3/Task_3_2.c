#include <stdio.h>
int main() {
    int a, a1, a2, a3, a132, a213, a231, a312, a321;
    printf("a: ");
    scanf("%d", &a);
    a1 = a / 100;
    a2 = (a / 10) % 10;
    a3 = a % 10;
    a132 = a1 * 100 + a3 * 10 + a2;
    a213 = a2 * 100 + a1 * 10 + a3;
    a231 = a2 * 100 + a3 * 10 + a1;
    a312 = a3 * 100 + a1 * 10 + a2;
    a321 = a3 * 100 + a2 * 10 + a1;
    if (a1 != a2 && a1 != a3 && a2 != a3) {
        printf("All possible numbers: %d, %d, %d, %d, %d\n", a132, a213, a231, a312, a321);
    }
    return 0;
}