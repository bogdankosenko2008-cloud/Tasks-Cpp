#include <stdio.h>
int main() {
    int x, y, result;
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);
    if (x >=0 && x <= 255 && y >=0 && y <= 255) {
        result = x * y;
        if (result >= 0 && result <= 65535) {
            printf("%d\n", result);
        } else {
            printf("Error: result is out of range [0, 65535]\n");
        }
    } else {
        printf("Error: x and y must be in the range [0, 255]\n");
    }
    return 0;
}
