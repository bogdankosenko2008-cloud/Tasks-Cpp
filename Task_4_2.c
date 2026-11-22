#include <stdio.h>
#include <math.h>
int main() {
    int n;
    printf("Enter the number of repetitions n: ");
    scanf("%d", &n);
    int result = 1;
    printf("%d! = ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
        if (i < n) {
            printf("*");
        }
    }
    printf("\n");
    printf("%d! = ", n);
    for (int i = n; i >= 1; i--) {
        printf("%d", i);
        if (i > 1) {
            printf("*");
        }
    }
    printf("\n");
    return 0;
}