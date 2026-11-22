#include <stdio.h>
int main() {
    int arr[5] = {10, -4, 7, 25, 3};
    double x;
    int count = 0;
    printf("Enter a real number: ");
    scanf("%lf", &x);
    for (int i = 0; i < 5; i++) {
        if (arr[i] < x) {
            count++;
        }
    }
    printf("Number of array elements lower than %lf: %d\n", x, count);
    return 0;
}