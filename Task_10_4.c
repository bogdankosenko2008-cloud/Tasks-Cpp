#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numerator;
    unsigned int denominator;
} Rational;

unsigned int gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Rational reduce_rational(Rational r) {
    if (r.denominator == 0) {
        printf("Error: denominator cannot be zero! Setting to 1.\n");
        r.denominator = 1;
    }
    if (r.numerator == 0) {
        r.denominator = 1;
        return r;
    }

    unsigned int abs_num = (unsigned int)abs(r.numerator);
    unsigned int common = gcd(abs_num, r.denominator);

    r.numerator /= (int)common;
    r.denominator /= common;
    return r;
}

Rational input_rational() {
    Rational r;
    int den;
    printf("Enter rational number (numerator denominator, e.g., -3 4): ");
    scanf("%d %d", &r.numerator, &den);

    if (den == 0) {
        printf("Denominator cannot be 0. Using 1 instead.\n");
        den = 1;
    } else if (den < 0) {
        r.numerator = -r.numerator;
        den = -den;
    }
    r.denominator = (unsigned int)den;
    return reduce_rational(r);
}

void print_rational(Rational r) {
    if (r.denominator == 1) {
        printf("%d", r.numerator);
    } else {
        printf("%d/%u", r.numerator, r.denominator);
    }
}

Rational add_rational(Rational a, Rational b) {
    Rational res;
    res.numerator = a.numerator * (int)b.denominator + b.numerator * (int)a.denominator;
    res.denominator = a.denominator * b.denominator;
    return reduce_rational(res);
}

Rational multiply_rational(Rational a, Rational b) {
    Rational res;
    res.numerator = a.numerator * b.numerator;
    res.denominator = a.denominator * b.denominator;
    return reduce_rational(res);
}

int compare_rational(Rational a, Rational b) {
    long long left = (long long)a.numerator * b.denominator;
    long long right = (long long)b.numerator * a.denominator;

    if (left < right) return -1;
    if (left > right) return 1;
    return 0;
}

int main() {
    printf("=== Built-in Examples ===\n");
    Rational raw = {-12, 18};
    printf("Raw fraction: -12/18 -> Reduced: ");
    print_rational(reduce_rational(raw));
    printf("\n");

    Rational r1 = {2, 3};
    Rational r2 = {3, 4};

    printf("r1 = "); print_rational(r1);
    printf(", r2 = "); print_rational(r2);
    printf("\n");

    printf("Sum (r1 + r2) = ");
    print_rational(add_rational(r1, r2));
    printf("\n");

    printf("Product (r1 * r2) = ");
    print_rational(multiply_rational(r1, r2));
    printf("\n");
    int cmp = compare_rational(r1, r2);
    printf("Comparison: ");
    print_rational(r1);
    if (cmp < 0) printf(" < ");
    else if (cmp > 0) printf(" > ");
    else printf(" == ");
    print_rational(r2);
    printf("\n\n");

    printf("=== Interactive Input ===\n");
    printf("First rational number:\n");
    Rational user1 = input_rational();
    printf("Second rational number:\n");
    Rational user2 = input_rational();
    printf("\nReduced first: "); print_rational(user1);
    printf("\nReduced second: "); print_rational(user2);
    printf("\nSum: "); print_rational(add_rational(user1, user2));
    printf("\nProduct: "); print_rational(multiply_rational(user1, user2));
    int user_cmp = compare_rational(user1, user2);
    printf("\nComparison: ");
    print_rational(user1);
    if (user_cmp < 0) printf(" < ");
    else if (user_cmp > 0) printf(" > ");
    else printf(" == ");
    print_rational(user2);
    printf("\n");
    return 0;
}