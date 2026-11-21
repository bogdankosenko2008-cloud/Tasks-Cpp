#include <stdio.h>
int main() {
    double x;
    printf("x: ");
    scanf("%lf", &x);
    int int_part_manual = (int)x;
    double frac_part_manual = x - int_part_manual;
    // Найменше ціле, більше x (аналог ceil)
    int ceil_manual = (x > int_part_manual) ? (int_part_manual + 1) : int_part_manual;
    // Найбільше ціле, менше x (аналог floor)
    int floor_manual = (x < int_part_manual) ? (int_part_manual - 1) : int_part_manual;
    // Округлене значення (аналог round)
    int round_manual = (x >= 0) ? (int)(x + 0.5) : (int)(x - 0.5);
    printf("Tsila chastyna:   %d\n", int_part_manual);
    printf("Drobova chastyna: %g\n", frac_part_manual);
    printf("Bilshe tsile:     %d\n", ceil_manual);
    printf("Menshe tsile:     %d\n", floor_manual);
    printf("Okruglene:        %d\n", round_manual);
    return 0;
}
