#include <stdio.h>
#include <stdlib.h>
int main() {
    long long n;
    printf("Enter an integer number: ");
    scanf("%lld", &n);
    int count[10] = {0};
    if (n == 0) {
        count[0] = 1;
    } else {
        unsigned long long temp = (n < 0) ? (unsigned long long)(-(n + 1)) + 1 : (unsigned long long)n;
        while (temp > 0) {
            int digit = temp % 10;
            count[digit]++;
            temp /= 10;
        }
    }
    int max_freq = 0;
    int best_digit = 0;
    for (int d = 0; d <= 9; d++) {
        if (count[d] >= max_freq && count[d] > 0) {
            max_freq = count[d];
            best_digit = d;
        }
    }
    printf("The digit that appears most frequently: %d (frequency: %d)\n", best_digit, max_freq);
    return 0;
}