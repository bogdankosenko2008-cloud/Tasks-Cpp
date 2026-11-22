#include <stdio.h>
int main() {
    long long x1 = -99;
    long long x2 = -99;
    long long x3 = -99;
    long long x_curr = 0;
    int n = 3;
    while (1) {
        n++;
        x_curr = x3 + x1 + 100;
        if (x_curr > 0) {
            break;
        }
        x1 = x2;
        x2 = x3;
        x3 = x_curr;
    }
    printf("Smallest positive term of the sequence: x_%d = %lld\n", n, x_curr);
    return 0;
}