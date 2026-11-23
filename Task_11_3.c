#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
// a) Even numbers
bool isEven(int x) {
    return x % 2 == 0;
}
// b) Power of 3 (1, 3, 9, 27, ...)
bool isPowerOfThree(int x) {
    if (x < 1) return false;
    while (x % 3 == 0) {
        x /= 3;
    }
    return x == 1;
}
// c) Perfect squares (0, 1, 4, 9, 16, ...)
bool isPerfectSquare(int x) {
    if (x < 0) return false;
    int root = (int)round(sqrt((double)x));
    return root * root == x;
}
// d) Numbers with exactly 3 divisors (squares of prime numbers: 4, 9, 25, 49, ...)
bool hasThreeDivisors(int x) {
    if (x < 4) return false;
    int root = (int)round(sqrt((double)x));
    return (root * root == x) && isPrime(root);
}
// e) Palindromes (7, 11, 121, ...)
bool isPalindrome(int x) {
    if (x < 0) return false;
    int original = x;
    long long reversed = 0;
    while (x > 0) {
        reversed = reversed * 10 + (x % 10);
        x /= 10;
    }
    return original == reversed;
}
// f) Fibonacci numbers (0, 1, 1, 2, 3, 5, 8, 13, ...)
bool isFibonacci(int x) {
    if (x < 0) return false;
    long long a = 0, b = 1;
    while (a < x) {
        long long next = a + b;
        a = b;
        b = next;
    }
    return a == x;
}
void printFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    int num;
    int isFirst = 1;
    while (fread(&num, sizeof(int), 1, file) == 1) {
        if (!isFirst) printf(", ");
        printf("%d", num);
        isFirst = 0;
    }
    if (isFirst) printf("(empty)");
    printf("\n");
    fclose(file);
}

void filterAndPrint(const char *fileF, const char *fileG, const char *label, bool (*condition)(int)) {
    FILE *f = fopen(fileF, "rb");
    FILE *g = fopen(fileG, "wb");
    if (!f || !g) {
        perror("Error opening files");
        if (f) fclose(f);
        if (g) fclose(g);
        return;
    }
    int num;
    while (fread(&num, sizeof(int), 1, f) == 1) {
        if (condition(num)) {
            fwrite(&num, sizeof(int), 1, g);
        }
    }
    fclose(f);
    fclose(g);
    printf("%s: ", label);
    printFile(fileG);
}
int main() {
    const char *fileF = "F.bin";
    const char *fileG = "G.bin";
    FILE *f = fopen(fileF, "wb");
    if (f == NULL) {
        perror("Error creating file F");
        return 1;
    }
    printf("Enter integers for file F (enter 0 to stop):\n");
    int num;
    while (1) {
        if (scanf("%d", &num) != 1) {
            printf("Invalid input.\n");
            fclose(f);
            return 1;
        }
        if (num == 0) {
            break;
        }
        fwrite(&num, sizeof(int), 1, f);
    }
    fclose(f);
    printf("\nContents of file F: ");
    printFile(fileF);
    printf("\n--- Results for file G ---\n");

    filterAndPrint(fileF, fileG, "a) Even numbers", isEven);
    filterAndPrint(fileF, fileG, "b) Powers of 3", isPowerOfThree);
    filterAndPrint(fileF, fileG, "c) Perfect squares", isPerfectSquare);
    filterAndPrint(fileF, fileG, "d) Exactly 3 divisors", hasThreeDivisors);
    filterAndPrint(fileF, fileG, "e) Palindromes", isPalindrome);
    filterAndPrint(fileF, fileG, "f) Fibonacci numbers", isFibonacci);

    return 0;
}