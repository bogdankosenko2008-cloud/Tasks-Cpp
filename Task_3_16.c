#include <stdio.h>
#include <math.h>

#define EPS 1e-9

int main() {
    double x1, y1, r1;
    double x2, y2, r2;
    printf("coordinates of the first circle (x1 y1 r1): ");
    if (scanf("%lf %lf %lf", &x1, &y1, &r1) != 3 || r1 <= 0) {
        printf("Error: incorrect data for the first circle (radius must be > 0).\n");
        return 1;
    }
    printf("coordinates of the second circle (x2 y2 r2): ");
    if (scanf("%lf %lf %lf", &x2, &y2, &r2) != 3 || r2 <= 0) {
        printf("Error: incorrect data for the second circle (radius must be > 0).\n");
        return 1;
    }
    double d = hypot(x2 - x1, y2 - y1);
    double r_sum = r1 + r2;
    double r_diff = fabs(r1 - r2);
    if (d < EPS && r_diff < EPS) {
        printf("Circles coincide (infinite number of common points).\n");
    } else if (d > r_sum + EPS) {
        printf("Circles do not intersect (placed separately from each other).\n");
    } else if (d < r_diff - EPS) {
        printf("Circles do not intersect (one circle lies entirely inside the other).\n");
    } else if (fabs(d - r_sum) <= EPS) {
        printf("Circles intersect at 1 point (external tangent).\n");
    } else if (fabs(d - r_diff) <= EPS) {
        printf("Circles intersect at 1 point (internal tangent).\n");
    } else {
        printf("Circles intersect at 2 points.\n");
    }
    return 0;
}