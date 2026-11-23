#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// ==========================================
// 8a) Class Time (hours, minutes, seconds)
// ==========================================
class Time {
private:
    int hours;
    int minutes;
    int seconds;

    int toTotalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void input() {
        cout << "Enter time (hours minutes seconds): ";
        cin >> hours >> minutes >> seconds;
    }

    void print() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << ":"
             << setfill('0') << setw(2) << seconds;
    }

    // Method to find the difference between two Time objects
    Time difference(const Time& other) const {
        int diffSec = abs(this->toTotalSeconds() - other.toTotalSeconds());
        int h = diffSec / 3600;
        diffSec %= 3600;
        int m = diffSec / 60;
        int s = diffSec % 60;
        return Time(h, m, s);
    }
};

// ==========================================
// 8b) Class Date (year, month, day)
// Protected with include guards so it can be defined only once
// ==========================================
#ifndef DATE_H
#define DATE_H

class Date {
private:
    int year;
    int month;
    int day;

    // Helper method: converts date to total number of days (accounts for leap years)
    long long toTotalDays() const {
        int y = year;
        int m = month;
        if (m <= 2) {
            y -= 1;
            m += 12;
        }
        return 365LL * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + day - 306;
    }

public:
    Date(int y = 2000, int m = 1, int d = 1) : year(y), month(m), day(d) {}

    void input() {
        cout << "Enter date (year month day): ";
        cin >> year >> month >> day;
    }

    void print() const {
        cout << year << "-"
             << setfill('0') << setw(2) << month << "-"
             << setfill('0') << setw(2) << day;
    }

    // Method to find the difference in days between two Date objects
    long long differenceInDays(const Date& other) const {
        return abs(this->toTotalDays() - other.toTotalDays());
    }
};

#endif // DATE_H

// ==========================================
// Main program to test both classes
// ==========================================
int main() {
    // --- Test Time ---
    cout << "--- Time Difference ---\n";
    Time t1, t2;
    cout << "First ";
    t1.input();
    cout << "Second ";
    t2.input();

    Time tDiff = t1.difference(t2);
    cout << "Difference between ";
    t1.print();
    cout << " and ";
    t2.print();
    cout << " is: ";
    tDiff.print();
    cout << "\n\n";

    // --- Test Date ---
    cout << "--- Date Difference ---\n";
    Date d1, d2;
    cout << "First ";
    d1.input();
    cout << "Second ";
    d2.input();

    long long daysDiff = d1.differenceInDays(d2);
    cout << "Difference between ";
    d1.print();
    cout << " and ";
    d2.print();
    cout << " is: " << daysDiff << " days.\n";

    return 0;
}