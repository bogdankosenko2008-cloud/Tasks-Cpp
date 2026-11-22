#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double height;
} Mountain;

void input_mountains(Mountain arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Mountain #%d:\n", i + 1);
        printf("  Name (single word or with underscores, e.g., Hoverla): ");
        scanf("%49s", arr[i].name);
        printf("  Height (in meters): ");
        scanf("%lf", &arr[i].height);
    }
}

void print_mountains(const Mountain arr[], int n) {
    printf("List of mountains:\n");
    for (int i = 0; i < n; i++) {
        printf("  %d. %s - %.1f m\n", i + 1, arr[i].name, arr[i].height);
    }
}

const char* find_highest_mountain(const Mountain arr[], int n) {
    if (n <= 0) return "None";

    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].height > arr[max_idx].height) {
            max_idx = i;
        }
    }
    return arr[max_idx].name;
}

void print_height_by_name(const Mountain arr[], int n, const char *target_name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, target_name) == 0) {
            printf("Height of '%s': %.1f m\n", target_name, arr[i].height);
            return;
        }
    }
    printf("Mountain '%s' was not found in the array.\n", target_name);
}

int main() {
    printf("Built-in Examples\n");
    Mountain sample_mountains[] = {
        {"Hoverla", 2061.0},
        {"Everest", 8848.8},
        {"Mont_Blanc", 4807.8},
        {"Pip_Ivan", 2028.5}
    };
    int sample_n = 4;

    print_mountains(sample_mountains, sample_n);
    printf("Highest peak: %s\n", find_highest_mountain(sample_mountains, sample_n));
    print_height_by_name(sample_mountains, sample_n, "Hoverla");
    print_height_by_name(sample_mountains, sample_n, "K2");
    printf("\n");

    printf("=== Interactive Input ===\n");
    int n;
    printf("Enter number of mountains N (1..50): ");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("Invalid N.\n");
        return 1;
    }

    Mountain mountains[50];
    input_mountains(mountains, n);

    printf("\n");
    print_mountains(mountains, n);
    printf("Highest peak: %s\n", find_highest_mountain(mountains, n));

    char search_name[MAX_NAME_LEN];
    printf("\nEnter mountain name to search its height: ");
    scanf("%49s", search_name);
    print_height_by_name(mountains, n, search_name);

    return 0;
}