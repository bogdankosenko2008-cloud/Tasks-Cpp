#include <stdio.h>
#include <math.h>
int main() {
    int a1, a2, a3;
    printf("a1, a2, a3: ");
    scanf("%d %d %d", &a1, &a2, &a3);
    if (a1 <= abs(pow(2, 10)) && a2 <= abs(pow(2, 10)) && a3 <= abs(pow(2, 10))) {
        printf("<2^10: %d\n", a1*a2*a3);
    }
    if (a1 <= abs(pow(2, 21)) && a2 <= abs(pow(2, 21)) && a3 <= abs(pow(2, 21))){
        printf("<2^21: %d\n", a1*a2*a3);
    }
    return 0;
}