#include <stdio.h>
#include <float.h>
int main() {
    float a = 1.0f;
    while (1.0f + a != 1.0f) {
        a /= 2.0f;
    }
    printf("The found value of a: %.10e\n", a);
    printf("FLT_EPSILON / 2 from <float.h>: %.10e\n", FLT_EPSILON / 2.0f);
    return 0;
}