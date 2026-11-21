#include <stdio.h>
int main() {
    double a, b, c;
    printf("A=xxx.xxx, B=xxExxx C=xxx.xxxx: \n");
    if (scanf("A=%lf, B=%lf C=%lf", &a, &b, &c) != 3) {
        printf("error.\n");
        return 1;
    }
    if (a == 0 || b == 0 || c == 0) {
        printf("error.\n");
        return 1;
    }
    double sum_inv = (1.0 / a) + (1.0 / b) + (1.0 / c);
    if (sum_inv == 0) {
        printf("error.\n");
        return 1;
    }
    double arithmetic_mean = (a + b + c) / 3.0;
    double harmonic_mean = 3.0 / sum_inv;
    printf("\n Middle arithmetic:\n");
    printf("With fixed point: %.4f\n", arithmetic_mean);
    printf("Scientific format: %.4e\n", arithmetic_mean);

    printf("\n Middle harmonic:\n");
    printf("With fixed point: %.4f\n", harmonic_mean);
    printf("Scientific format: %.4e\n", harmonic_mean);
    return 0;
}