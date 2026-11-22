#include <stdio.h>
void input_array(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}
int find_and_print_max(const int arr[], int size) {
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    printf("Maximum value in the array: %d\n", max_val);
    return max_val;
}

int main() {
    int arr[5];
    input_array(arr, 5);
    find_and_print_max(arr, 5);
    return 0;
}