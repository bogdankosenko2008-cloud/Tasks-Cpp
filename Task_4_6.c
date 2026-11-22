#include <stdio.h>
#include <math.h>
int main(){
    int n;
    printf("Enter the number of terms n: ");
    scanf("%d", &n);
    // а)
    double res_a = 0.0;
    for (int i = 0; i < n; i++) {
        res_a = sqrt(2.0 + res_a);
    }
    // б)
    double res_b = 0.0;
    for (int i = n; i >= 1; i--) {
        res_b = sqrt(3.0 * i + res_b);
    }
    printf("a) Result: %lf\n", res_a);
    printf("b) Result: %lf\n", res_b);
    return 0;
}