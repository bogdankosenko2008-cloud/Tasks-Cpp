#include <stdio.h>
#include <math.h>
int main() {
    printf("Part 1: Entering real numbers (0 to finish)\n");
    int val, sum = 0;
    int idx = 0;

    while (1) {
        printf("a[%d]= ", idx);
        scanf("%d", &val);
        if (val == 0) {
            break;
        }
        sum += val;
        idx++;
    }
    printf("The sum of the entered numbers: %d\n\n", sum);
    printf("Part 2: Entering non-zero numbers (0 to finish)\n");
    double num, arith_sum = 0.0, prod = 1.0;
    int count = 0;
    while (1) {
        printf("a[%d]= ", count);
        scanf("%lf", &num);
        if (num == 0.0) {
            break;
        }
        arith_sum += num;
        prod *= num;
        count++;
    }
    if (count > 0) {
        double arith_mean = arith_sum / count;
        printf("The arithmetic mean: %lf\n", arith_mean);
        if (prod >= 0.0 || count % 2 != 0) {
            double geom_mean = (prod < 0) ? -pow(-prod, 1.0 / count) : pow(prod, 1.0 / count);
            printf("The geometric mean: %lf\n", geom_mean);
        } else {
            printf("The geometric mean: does not exist in the set of real numbers (negative product with even count).\n");
        }
    } else {
        printf("No non-zero numbers were entered.\n");
    }
    return 0;
}