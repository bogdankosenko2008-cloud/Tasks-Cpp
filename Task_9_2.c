#include <stdio.h>
#include <math.h>
#define MAX_SIZE 100
int input_until_zero(int *arr, int max_len) {
    int count = 0;
    int val;
    printf("Enter integers (0 to finish, maximum %d elements):\n", max_len);
    while (count < max_len) {
        printf("arr[%d] = ", count);
        scanf("%d", &val);

        if (val == 0) {
            break;
        }
        arr[count] = val;
        count++;
    }
    return count;
}
int is_perfect_square(int x) {
    if (x < 0) return 0;
    int r = (int)round(sqrt((double)x));
    return (long long)r * r == x;
}
int is_perfect_cube(int x) {
    int r = (int)round(cbrt((double)x));
    return (long long)r * r * r == x;
}
int main() {
    int arr[MAX_SIZE];
    int n = input_until_zero(arr, MAX_SIZE);
    int squares = 0;
    int cubes = 0;
    for (int i = 0; i < n; i++) {
        if (is_perfect_square(arr[i])) {
            squares++;
        }
        if (is_perfect_cube(arr[i])) {
            cubes++;
        }
    }
    printf("\nNumber of entered elements: %d\n", n);
    printf("Number of perfect squares: %d\n", squares);
    printf("Number of perfect cubes: %d\n", cubes);
    return 0;
}