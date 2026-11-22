#include <stdio.h>
unsigned long long fib_n(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    unsigned long long prev2 = 0, prev1 = 1, curr = 0;
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int max_fib_index_le(double a) {
    if (a < 0) return -1;
    if (a < 1) return 0;
    unsigned long long prev2 = 0, prev1 = 1;
    int k = 1;
    while (prev1 + prev2 <= a) {
        unsigned long long next = prev1 + prev2;
        prev2 = prev1;
        prev1 = next;
        k++;
    }
    return k;
}
int min_fib_index_gt(double a) {
    if (a < 0) return 0;
    unsigned long long prev2 = 0, prev1 = 1;
    int k = 1;
    while (prev1 <= a) {
        unsigned long long next = prev1 + prev2;
        prev2 = prev1;
        prev1 = next;
        k++;
    }
    return k;
}
unsigned long long sum_fib_le_1000() {
    unsigned long long sum = 0;
    unsigned long long prev2 = 0, prev1 = 1;
    while (prev1 <= 1000) {
        sum += prev1;
        unsigned long long next = prev1 + prev2;
        prev2 = prev1;
        prev1 = next;
    }
    return sum;
}
int main() {
    int n;
    double a;
    printf("Enter the number n for calculating F_n: ");
    scanf("%d", &n);
    printf("a) F_%d = %llu\n\n", n, fib_n(n));
    printf("Enter the number a: ");
    scanf("%lf", &a);
    int idx_le = max_fib_index_le(a);
    if (idx_le == -1) {
        printf("b) There are no Fibonacci numbers <= %lf\n", a);
    } else {
        printf("b) The index of the largest Fibonacci number <= %lf: k = %d (F_%d = %llu)\n", a, idx_le, idx_le, fib_n(idx_le));
    }
    int idx_gt = min_fib_index_gt(a);
    printf("c) The index of the smallest Fibonacci number > %lf: k = %d (F_%d = %llu)\n\n", a, idx_gt, idx_gt, fib_n(idx_gt));
    printf("d) Sum of all Fibonacci numbers <= 1000: %llu\n", sum_fib_le_1000());
    return 0;
}