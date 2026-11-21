#include <stdio.h>
#include <math.h>
double Square_of_triangle(double xa, double xb, double xc, double ya, double yb, double yc) {
    double AB = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
    double AC = sqrt(pow(xc - xa, 2) + pow(yc - ya, 2));
    double BC = sqrt(pow(xc - xb, 2) + pow(yc - yb, 2));
    double p = (AB + AC + BC) / 2;
    double area = sqrt(p * (p - AB) * (p - AC) * (p - BC));
    return area;
}
int main() {
    double xa, xb, xc, ya, yb, yc;
    printf("xa, ya: ");
    scanf("%lf %lf", &xa, &ya);
    printf("xb, yb: ");
    scanf("%lf %lf", &xb, &yb);
    printf("xc, yc: ");
    scanf("%lf %lf", &xc, &yc);
    double S = Square_of_triangle(xa, xb, xc, ya, yb, yc);
    printf("%lf\n", S);
    return 0;
}