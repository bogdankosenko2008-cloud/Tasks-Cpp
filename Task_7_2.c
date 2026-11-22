#include <stdio.h>
int main() {
    int arr[4] = {5, 112, 4, 3};
    for (int i = 3; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf(".\n");
    return 0;
}