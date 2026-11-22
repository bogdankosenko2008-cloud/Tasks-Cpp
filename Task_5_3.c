#include <stdio.h>
int collatz_steps(long long start, int print_seq) {
    long long a = start;
    int steps = 0;
    if (print_seq) printf("%lld", a);
    while (a != 1) {
        if (a % 2 == 0) {
            a = a / 2;
        } else {
            a = 3 * a + 1;
        }
        steps++;
        if (print_seq) printf(" -> %lld", a);
    }
    if (print_seq) printf("\n");
    return steps;
}
int main() {
    int n;
    printf("Enter a natural number n: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("The number n must be a natural number (n >= 1).\n");
        return 1;
    }
    printf("Sequence for n = %d:\n", n);
    int n_steps = collatz_steps(n, 1);
    printf("Number of steps for %d: %d\n\n", n, n_steps);
    int max_steps = -1;
    int best_num = 1;
    for (int i = 1; i < 1000; i++) {
        int s = collatz_steps(i, 0);
        if (s > max_steps) {
            max_steps = s;
            best_num = i;
        }
    }
    printf("All numbers < 1000 converge to 1.\n");
    printf("Number < 1000 with the maximum number of steps: %d (%d steps)\n", best_num, max_steps);
    return 0;
}