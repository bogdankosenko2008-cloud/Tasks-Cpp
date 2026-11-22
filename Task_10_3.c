#include <stdio.h>
#include <stdbool.h>

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

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return (month >= 1 && month <= 12) ? days[month] : 0;
}

Date tomorrow_date(Date d) {
    d.day++;
    if (d.day > days_in_month(d.month, d.year)) {
        d.day = 1;
        d.month++;
        if (d.month > 12) {
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

const char* get_day_of_week(Date d) {
    const char *names[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int y = d.year;
    if (d.month < 3) {
        y -= 1;
    }
    int dow = (y + y / 4 - y / 100 + y / 400 + t[d.month - 1] + d.day) % 7;
    return names[dow];
}

int main() {
    printf("Built-in Examples\n");
    Date samples[] = {
        {28, 2, 2024},
        {31, 12, 2026},
        {23, 11, 2026}
    };

    for (int i = 0; i < 3; i++) {
        Date next = tomorrow_date(samples[i]);
        print_date(samples[i]);
        printf(" (%s) -> Tomorrow: ", get_day_of_week(samples[i]));
        print_date(next);
        printf(" (%s)\n", get_day_of_week(next));
    }
    printf("\n");
    printf("Interactive Input\n");
    Date d = input_date();

    printf("Entered date: ");
    print_date(d);
    printf(" (%s)\n", get_day_of_week(d));

    Date next_d = tomorrow_date(d);
    printf("Tomorrow's date: ");
    print_date(next_d);
    printf(" (%s)\n", get_day_of_week(next_d));
    return 0;
}