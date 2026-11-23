#include <stdio.h>
#include <stdlib.h>
void writeArrayToFile(const char *filename, const double *arr, int n) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error to open file for writing");
        return;
    }
    fwrite(arr, sizeof(double), n, file);
    fclose(file);
}

void printFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error to open file for reading");
        return;
    }
    double num;
    int isFirst = 1;
    while (fread(&num, sizeof(double), 1, file) == 1) {
        if (!isFirst) {
            printf(", ");
        }
        printf("%g", num);
        isFirst = 0;
    }
    printf("\n");
    fclose(file);
}

int main() {
    int n;
    char filename[100];
    printf("Input name of file (ex, data.bin): ");
    scanf("%99s", filename);
    printf("Input lenght of array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Incorrect lenght of array.\n");
        return 1;
    }
    double *arr = (double *)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Error of highlighting memory.\n");
        return 1;
    }
    printf("Input %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
    writeArrayToFile(filename, arr, n);
    free(arr);
    printf("Consisting File %s: ", filename);
    printFile(filename);
    return 0;
}