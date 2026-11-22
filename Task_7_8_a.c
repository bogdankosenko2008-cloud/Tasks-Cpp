#include <stdio.h>
#include <math.h>
int is_prime(int num) {
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    for (int i = 3; (long long)i * i <= num; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
int is_square_of_prime(int x) {
    if (x < 4) return 0;
    int root = (int)round(sqrt((double)x));
    if ((long long)root * root == x && is_prime(root)) {
        return 1;
    }
    return 0;
}
int main() {
    int N;
    printf("Enter size of array N: ");
    scanf("%d", &N);

    if (N < 1) {
        printf("The size of the array must be a positive integer (N >= 1).\n");
        return 1;
    }
    int arr[N];
    printf("Enter %d positive integers:\n", N);
    for (int i = 0; i < N; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0 && is_square_of_prime(arr[i])) {
            count++;
        }
    }
    printf("Number of perfect squares of prime numbers: %d\n", count);
    return 0;
}