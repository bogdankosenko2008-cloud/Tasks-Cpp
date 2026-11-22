#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_N 100
typedef struct {
    int day;
    int month;
    int year;
} Date;
typedef struct {
    char surname[50];
    char name[50];
    char gender[10];
    char position[50];
    Date birthDate;
} Employee;
void inputEmployees(Employee P[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Employee #%d ---\n", i + 1);
        printf("Surname: ");
        scanf("%49s", P[i].surname);
        printf("Name: ");
        scanf("%49s", P[i].name);
        printf("Gender (M/F): ");
        scanf("%9s", P[i].gender);
        printf("Position: ");
        scanf("%49s", P[i].position);
        printf("Birth date (dd mm yyyy): ");
        scanf("%d %d %d", &P[i].birthDate.day, &P[i].birthDate.month, &P[i].birthDate.year);
    }
}
void printEmployee(Employee emp) {
    printf("%s %s | Gender: %s | Position: %s | DOB: %02d.%02d.%04d\n",
           emp.surname, emp.name, emp.gender, emp.position,
           emp.birthDate.day, emp.birthDate.month, emp.birthDate.year);
}
// а)
void findMostCommonPosition(Employee P[], int n) {
    if (n <= 0) return;
    int maxCount = 0;
    int bestIndex = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(P[i].position, P[j].position) == 0) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            bestIndex = i;
        }
    }
    printf("\na) Most common position: %s (%d employee(s))\n", P[bestIndex].position, maxCount);
}
// б)
void findSameNames(Employee P[], int n) {
    printf("\nb) Employees with the same names:\n");
    int foundAny = 0;
    for (int i = 0; i < n; i++) {
        int alreadyChecked = 0;
        for (int k = 0; k < i; k++) {
            if (strcmp(P[i].name, P[k].name) == 0) {
                alreadyChecked = 1;
                break;
            }
        }
        if (alreadyChecked) continue;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(P[i].name, P[j].name) == 0) {
                count++;
            }
        }
        if (count > 1) {
            foundAny = 1;
            printf("Name \"%s\":\n", P[i].name);
            for (int j = 0; j < n; j++) {
                if (strcmp(P[i].name, P[j].name) == 0) {
                    printf("  - ");
                    printEmployee(P[j]);
                }
            }
        }
    }
    if (!foundAny) {
        printf("  No employees with identical names found.\n");
    }
}
// в)
void findBySurnameLetter(Employee P[], int n, char letter) {
    printf("\nc) Employees whose surname starts with '%c':\n", letter);
    int found = 0;
    char target = toupper((unsigned char)letter);
    for (int i = 0; i < n; i++) {
        if (toupper((unsigned char)P[i].surname[0]) == target) {
            printf("  - ");
            printEmployee(P[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("  No matching employees found.\n");
    }
}

int main() {
    int n;
    Employee P[MAX_N];
    printf("Enter number of employees (N): ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_N) {
        printf("Invalid number of employees.\n");
        return 1;
    }
    inputEmployees(P, n);
    findMostCommonPosition(P, n);
    findSameNames(P, n);

    char letter;
    printf("\nEnter starting letter of surname to search: ");
    scanf(" %c", &letter);
    findBySurnameLetter(P, n, letter);

    return 0;
}