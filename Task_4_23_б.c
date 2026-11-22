#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Number n must be a positive integer (n >= 1).\n");
        return 1;
    }
    int y, z, min_abs_z;
    for (int i = 1; i <= n; i++) {
        printf("Enter y[%d]: ", i);
        scanf("%d", &y);
        if (fabs(y) >= 1.0) {
            z = y;
        } else {
            z = 2.0;
        }
        int abs_z = fabs(z);
        if (i == 1 || abs_z < min_abs_z) {
            min_abs_z = abs_z;
        }
    }
    printf("min(|z_1|, ..., |z_%d|) = %d\n", n, min_abs_z);
    return 0;
}