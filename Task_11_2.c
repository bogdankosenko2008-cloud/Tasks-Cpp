#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void printFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    double num;
    int isFirst = 1;
    while (fread(&num, sizeof(double), 1, file) == 1) {
        if (!isFirst) printf(", ");
        printf("%g", num);
        isFirst = 0;
    }
    printf("\n");
    fclose(file);
}

void processFiles(const char *fileF, const char *fileG, double a) {
    const char *tempFile = "temp.bin";
    FILE *f = fopen(fileF, "rb");
    FILE *g = fopen(fileG, "wb");
    FILE *temp = fopen(tempFile, "wb");
    if (!f || !g || !temp) {
        perror("Error opening files");
        if (f) fclose(f);
        if (g) fclose(g);
        if (temp) fclose(temp);
        return;
    }

    double num;
    while (fread(&num, sizeof(double), 1, f) == 1) {
        if (fabs(num) < a) {
            // Write numbers with |x| < a to file G
            fwrite(&num, sizeof(double), 1, g);
        } else {
            fwrite(&num, sizeof(double), 1, temp);
        }
    }
    fclose(f);
    fclose(g);
    fclose(temp);
    remove(fileF);
    rename(tempFile, fileF);
}

int main() {
    const char *fileF = "F.bin";
    const char *fileG = "G.bin";
    double initialData[] = { -5.4, 1.2, -0.8, 3.0, -2.5, 0.5, 4.1 };
    int count = sizeof(initialData) / sizeof(initialData[0]);
    FILE *initF = fopen(fileF, "wb");
    if (initF) {
        fwrite(initialData, sizeof(double), count, initF);
        fclose(initF);
    }
    printf("Initial file F: ");
    printFile(fileF);
    double a;
    printf("Enter a number a > 0: ");
    if (scanf("%lf", &a) != 1 || a <= 0) {
        printf("Error: number 'a' must be greater than 0.\n");
        return 1;
    }
    processFiles(fileF, fileG, a);
    printf("\nFile G (numbers with |x| < %g): ", a);
    printFile(fileG);
    printf("Updated file F (after removal): ");
    printFile(fileF);
    return 0;
}