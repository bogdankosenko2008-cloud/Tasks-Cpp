#include <stdio.h>
#define MAX_DIM 20
// 1. Функція вводу n-вимірного вектору дійсних чисел
void input_vector(double v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("  element [%d] = ", i);
        scanf("%lf", &v[i]);
    }
}
// 2. Функція виводу n-вимірного вектору дійсних чисел
void print_vector(const double v[], int n) {
    printf("(");
    for (int i = 0; i < n; i++) {
        printf("%.2f", v[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf(")\n");
}
// 3. Функція рахує суму двох векторів (результат записує в аргумент res[])
void sum_vectors(const double v1[], const double v2[], double res[], int n) {
    for (int i = 0; i < n; i++) {
        res[i] = v1[i] + v2[i];
    }
}
// 4. Функція рахує скалярний добуток двох векторів однакового розміру
double dot_product(const double v1[], const double v2[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += v1[i] * v2[i];
    }
    return sum;
}

int main() {
    int n;
    double vec1[MAX_DIM], vec2[MAX_DIM], vec_sum[MAX_DIM];
    printf("Enter the dimension of the vectors n (1 <= n < 20): ");
    scanf("%d", &n);

    if (n < 1 || n >= MAX_DIM) {
        printf("Error: the dimension n must be between 1 and 19.\n");
        return 1;
    }

    printf("\nFirst vector: ");
    input_vector(vec1, n);

    printf("Second vector: ");
    input_vector(vec2, n);

    sum_vectors(vec1, vec2, vec_sum, n);
    double scalar = dot_product(vec1, vec2, n);

    printf("\nFirst vector: ");
    print_vector(vec1, n);
    printf("Second vector: ");
    print_vector(vec2, n);
    printf("Sum of vectors: ");
    print_vector(vec_sum, n);
    printf("Scalar product: %.4f\n", scalar);
    return 0;
}