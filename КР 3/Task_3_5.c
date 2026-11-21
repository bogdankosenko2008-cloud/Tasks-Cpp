#include <stdio.h>
int main() {
    int x, y;
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);
    if (x > y) {
        printf("x is maximum, y is minimum\n");
    } else if (y > x) {
        printf("y is maximum, x is minimum\n");
    } else {
        printf("x and y are equal\n");
    }
    return 0;
}