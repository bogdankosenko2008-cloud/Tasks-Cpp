#include <stdio.h>
#include <stdlib.h>
void printFile(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Error opening file");
        return;
    }
    int num, isFirst = 1;
    while (fread(&num, sizeof(int), 1, f) == 1) {
        if (!isFirst) printf(", ");
        printf("%d", num);
        isFirst = 0;
    }
    if (isFirst) printf("(empty)");
    printf("\n");
    fclose(f);
}
int main() {
    const char *fileF = "F.bin";
    const char *fileH = "H.bin";
    const char *fileG = "G.bin";

    int n;
    printf("Enter total count of numbers for file F: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid count.\n");
        return 1;
    }
    FILE *f = fopen(fileF, "wb");
    if (!f) {
        perror("Error creating file F");
        return 1;
    }
    printf("Enter %d non-zero integers:\n", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        fwrite(&val, sizeof(int), 1, f);
    }
    fclose(f);
    printf("\nFile F: ");
    printFile(fileF);

    f = fopen(fileF, "rb");
    int num, posCount = 0, negCount = 0, zeroCount = 0;
    while (fread(&num, sizeof(int), 1, f) == 1) {
        if (num > 0) posCount++;
        else if (num < 0) negCount++;
        else zeroCount++;
    }
    fclose(f);
    if (zeroCount > 0 || posCount != negCount) {
        printf("Condition failed: file F does not contain an equal number of positive and negative numbers (zeros are not allowed). Nothing done.\n");
        return 0;
    }

    f = fopen(fileF, "rb");
    FILE *h = fopen(fileH, "wb");
    while (fread(&num, sizeof(int), 1, f) == 1) {
        if (num < 0) {
            fwrite(&num, sizeof(int), 1, h);
        }
    }
    fclose(f);
    fclose(h);

    f = fopen(fileF, "rb");
    h = fopen(fileH, "rb");
    FILE *g = fopen(fileG, "wb");
    int posNum, negNum;
    for (int i = 0; i < posCount; i++) {
        while (fread(&posNum, sizeof(int), 1, f) == 1) {
            if (posNum > 0) break;
        }
        fread(&negNum, sizeof(int), 1, h);

        fwrite(&posNum, sizeof(int), 1, g);
        fwrite(&negNum, sizeof(int), 1, g);
    }
    fclose(f);
    fclose(h);
    fclose(g);
    printf("File G (alternating signs): ");
    printFile(fileG);
    return 0;
}