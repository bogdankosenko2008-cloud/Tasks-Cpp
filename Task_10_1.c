#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int day;
    int month;
    int year;
} Date;

Date input_date() {
    Date d;
    printf("Enter date (day month year separated by spaces): ");
    scanf("%d %d %d", &d.day, &d.month, &d.year);
    return d;
}

void print_date(Date d) {
    printf("%02d.%02d.%04d", d.day, d.month, d.year);
}

typedef struct {
    char file;
    int rank;
} ChessSquare;

ChessSquare input_square() {
    ChessSquare sq;
    printf("Enter chessboard square (e.g., a5): ");
    scanf(" %c%d", &sq.file, &sq.rank);
    return sq;
}

void print_square(ChessSquare sq) {
    printf("%c%d", sq.file, sq.rank);
}

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Rectangle;

Rectangle input_rectangle() {
    Rectangle rect;
    printf("Enter coordinates of the first vertex (x1 y1): ");
    scanf("%lf %lf", &rect.p1.x, &rect.p1.y);
    printf("Enter coordinates of the opposite vertex (x2 y2): ");
    scanf("%lf %lf", &rect.p2.x, &rect.p2.y);
    return rect;
}

void print_rectangle(Rectangle rect) {
    printf("Rectangle [(%.2f, %.2f); (%.2f, %.2f)]",
           rect.p1.x, rect.p1.y, rect.p2.x, rect.p2.y);
}

typedef struct {
    int degree;
    double *coeffs;
} Polynomial;

Polynomial input_polynomial() {
    Polynomial p;
    printf("Enter polynomial degree n: ");
    scanf("%d", &p.degree);

    if (p.degree < 0) p.degree = 0;

    p.coeffs = (double*)malloc((p.degree + 1) * sizeof(double));
    for (int i = 0; i <= p.degree; i++) {
        printf("  coefficient for x^%d: ", i);
        scanf("%lf", &p.coeffs[i]);
    }
    return p;
}
void print_polynomial(Polynomial p) {
    for (int i = p.degree; i >= 0; i--) {
        if (i < p.degree && p.coeffs[i] >= 0) printf(" + ");
        else if (p.coeffs[i] < 0) printf(" - ");
        double val = (p.coeffs[i] < 0) ? -p.coeffs[i] : p.coeffs[i];
        if (i == 0) printf("%.2f", val);
        else if (i == 1) printf("%.2f*x", val);
        else printf("%.2f*x^%d", val, i);
    }
}

void free_polynomial(Polynomial *p) {
    free(p->coeffs);
    p->coeffs = NULL;
}
int main() {
    printf("=== 1a) Date ===\n");
    Date d = input_date();
    printf("Entered date: ");
    print_date(d);
    printf("\n\n");
    printf("=== 1b) Chessboard Square ===\n");
    ChessSquare sq = input_square();
    printf("Entered square: ");
    print_square(sq);
    printf("\n\n");
    printf("=== 1c) Rectangle ===\n");
    Rectangle rect = input_rectangle();
    print_rectangle(rect);
    printf("\n\n");
    printf("=== 1d) Polynomial ===\n");
    Polynomial poly = input_polynomial();
    printf("Polynomial: P(x) = ");
    print_polynomial(poly);
    printf("\n");
    free_polynomial(&poly);
    return 0;
}