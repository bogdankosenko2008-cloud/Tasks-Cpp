#include <stdio.h>
#define MAX_SIZE 50
void count_even_odd(const int arr[], int size, int *even, int *odd) {
    *even = 0;
    *odd = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            (*even)++;
        } else {
            (*odd)++;
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int val;
    printf("Enter positive integers (0 to finish, maximum %d elements):\n", MAX_SIZE);
    while (size < MAX_SIZE) {
        printf("arr[%d] = ", size);
        scanf("%d", &val);
        if (val == 0) {
            break;
        }
        if (val < 0) {
            printf("Number must be a positive integer (> 0). Please try again.\n");
            continue;
        }
        arr[size] = val;
        size++;
    }
    int even_count, odd_count;
    count_even_odd(arr, size, &even_count, &odd_count);
    printf("\nTotal elements entered: %d\n", size);
    printf("Count of even elements: %d\n", even_count);
    printf("Count of odd elements: %d\n", odd_count);
    return 0;
}