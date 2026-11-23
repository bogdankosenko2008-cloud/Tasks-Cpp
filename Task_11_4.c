#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    int id;
    double x1, y1;
    double x2, y2;
} Rectangle;

double calcArea(Rectangle r) {
    return fabs(r.x2 - r.x1) * fabs(r.y2 - r.y1);
}

void createFile(const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("Error creating file");
        return;
    }
    int n;
    printf("Enter number of rectangles: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid count.\n");
        fclose(f);
        return;
    }
    for (int i = 0; i < n; i++) {
        Rectangle r;
        printf("\nRectangle #%d:\n", i + 1);
        printf("  ID (number): ");
        scanf("%d", &r.id);
        printf("  Top-left corner (x1 y1): ");
        scanf("%lf %lf", &r.x1, &r.y1);
        printf("  Bottom-right corner (x2 y2): ");
        scanf("%lf %lf", &r.x2, &r.y2);
        fwrite(&r, sizeof(Rectangle), 1, f);
    }
    fclose(f);
}

void printFile(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Error opening file");
        return;
    }
    Rectangle r;
    int index = 1;
    printf("\n--- File Contents ---\n");
    while (fread(&r, sizeof(Rectangle), 1, f) == 1) {
        printf("[%d] ID: %d | Top-Left: (%g, %g) | Bottom-Right: (%g, %g) | Area: %g\n",
               index++, r.id, r.x1, r.y1, r.x2, r.y2, calcArea(r));
    }
    if (index == 1) {
        printf("(file is empty)\n");
    }
    printf("---------------------\n");
    fclose(f);
}

int findMaxArea(const char *filename, double *maxArea) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Error opening file");
        return -1;
    }
    Rectangle r;
    int maxId = -1;
    *maxArea = -1.0;
    while (fread(&r, sizeof(Rectangle), 1, f) == 1) {
        double area = calcArea(r);
        if (area > *maxArea) {
            *maxArea = area;
            maxId = r.id;
        }
    }
    fclose(f);
    return maxId;
}

void deleteById(const char *filename, int targetId) {
    const char *tempFile = "temp_rect.bin";
    FILE *f = fopen(filename, "rb");
    FILE *temp = fopen(tempFile, "wb");
    if (!f || !temp) {
        perror("Error opening files");
        if (f) fclose(f);
        if (temp) fclose(temp);
        return;
    }
    Rectangle r;
    int found = 0;
    while (fread(&r, sizeof(Rectangle), 1, f) == 1) {
        if (r.id == targetId) {
            found = 1;
        } else {
            fwrite(&r, sizeof(Rectangle), 1, temp);
        }
    }
    fclose(f);
    fclose(temp);
    remove(filename);
    rename(tempFile, filename);
    if (found) {
        printf("Rectangle with ID %d deleted.\n", targetId);
    } else {
        printf("Rectangle with ID %d not found.\n", targetId);
    }
}

void replaceByPosition(const char *filename, int pos, Rectangle newRect) {
    FILE *f = fopen(filename, "r+b");
    if (!f) {
        perror("Error opening file");
        return;
    }

    fseek(f, 0, SEEK_END);
    long totalRecords = ftell(f) / sizeof(Rectangle);

    if (pos < 1 || pos > totalRecords) {
        printf("Invalid ordinal position (valid range: 1 to %ld).\n", totalRecords);
        fclose(f);
        return;
    }

    fseek(f, (pos - 1) * sizeof(Rectangle), SEEK_SET);
    fwrite(&newRect, sizeof(Rectangle), 1, f);
    fclose(f);
    printf("Record #%d successfully replaced.\n", pos);
}
int main() {
    const char *filename = "rectangles.bin";

    createFile(filename);
    printFile(filename);

    double maxArea = 0.0;
    int maxId = findMaxArea(filename, &maxArea);
    if (maxId != -1) {
        printf("\nRectangle with max area -> ID: %d, Area: %g\n", maxId, maxArea);
    }

    int delId;
    printf("\nEnter rectangle ID to delete: ");
    if (scanf("%d", &delId) == 1) {
        deleteById(filename, delId);
        printFile(filename);
    }

    int pos;
    printf("\nEnter ordinal position in file to replace (starting from 1): ");
    if (scanf("%d", &pos) == 1) {
        Rectangle newRect;
        printf("Enter new rectangle data:\n");
        printf("  New ID: ");
        scanf("%d", &newRect.id);
        printf("  Top-left corner (x1 y1): ");
        scanf("%lf %lf", &newRect.x1, &newRect.y1);
        printf("  Bottom-right corner (x2 y2): ");
        scanf("%lf %lf", &newRect.x2, &newRect.y2);
        replaceByPosition(filename, pos, newRect);
        printFile(filename);
    }
    return 0;
}