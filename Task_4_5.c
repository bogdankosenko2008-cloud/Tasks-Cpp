#include <stdio.h>
#include <math.h>
int main() {
    int n;
    printf("Enter the number of repetitions n: ");
    scanf("%d", &n);
    long long int result = 1;
    if (n % 2 == 0) {
        for (int i = 2; i <= n; i += 2) {
            result *= i;
        }
    } else {
        for (int i = 1; i <= n; i += 2) {
            result *= i;
        }
    }
    printf("%d!! = %lld\n", n, result);
    return 0;
}