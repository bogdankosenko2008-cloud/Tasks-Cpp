#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <stdexcept>
using namespace std;
class Rational {
private:
    long long nominator;
    long long denominator;
    // Private method to reduce the fraction using GCD
    void reduce() {
        if (denominator < 0) {
            nominator = -nominator;
            denominator = -denominator;
        }
        if (nominator == 0) {
            denominator = 1;
            return;
        }
        long long common = gcd(abs(nominator), denominator);
        nominator /= common;
        denominator /= common;
    }
public:
    // Default constructor (initializes to 1/1)
    Rational() : nominator(1), denominator(1) {}
    // Parameterized constructor
    Rational(long long nom, long long denom = 1) {
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        nominator = nom;
        denominator = denom;
        reduce();
    }
    // Separate setters with validation
    void setNominator(long long nom) {
        nominator = nom;
        reduce();
    }
    void setDenominator(long long denom) {
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        denominator = denom;
        reduce();
    }
    long long getNominator() const { return nominator; }
    long long getDenominator() const { return denominator; }
    double toDouble() const { return static_cast<double>(nominator) / denominator; }
    // Input and output methods from terminal
    void input() {
        long long nom, denom;
        cout << "Enter nominator and denominator: ";
        cin >> nom >> denom;
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        nominator = nom;
        denominator = denom;
        reduce();
    }
    void print() const {
        if (denominator == 1) {
            cout << nominator;
        } else {
            cout << nominator << "/" << denominator;
        }
    }
    // Addition and multiplication methods
    Rational add(const Rational& other) const {
        return Rational(
            nominator * other.denominator + other.nominator * denominator,
            denominator * other.denominator
        );
    }
    Rational multiply(const Rational& other) const {
        return Rational(
            nominator * other.nominator,
            denominator * other.denominator
        );
    }
    // Overloaded arithmetic operators
    Rational operator+(const Rational& other) const { return add(other); }
    Rational operator-(const Rational& other) const {
        return Rational(
            nominator * other.denominator - other.nominator * denominator,
            denominator * other.denominator
        );
    }
    Rational operator*(const Rational& other) const { return multiply(other); }
    Rational operator/(const Rational& other) const {
        if (other.nominator == 0) {
            throw invalid_argument("Division by zero.");
        }
        return Rational(
            nominator * other.denominator,
            denominator * other.nominator
        );
    }
    // Overloaded comparison operators
    bool operator==(const Rational& other) const {
        return nominator == other.nominator && denominator == other.denominator;
    }
    bool operator!=(const Rational& other) const { return !(*this == other); }
    bool operator<(const Rational& other) const {
        return nominator * other.denominator < other.nominator * denominator;
    }
    bool operator>(const Rational& other) const { return other < *this; }
    bool operator<=(const Rational& other) const { return !(*this > other); }
    bool operator>=(const Rational& other) const { return !(*this < other); }
    // Overloaded stream operators
    friend ostream& operator<<(ostream& os, const Rational& r) {
        if (r.denominator == 1) os << r.nominator;
        else os << r.nominator << "/" << r.denominator;
        return os;
    }
    friend istream& operator>>(istream& is, Rational& r) {
        long long nom, denom;
        is >> nom >> denom;
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        r.nominator = nom;
        r.denominator = denom;
        r.reduce();
        return is;
    }
};
int main() {
    try {
        // --- Task 1: Find the minimum rational number in an array ---
        int n;
        cout << "Enter number of rational elements: ";
        cin >> n;
        vector<Rational> arr(n);
        for (int i = 0; i < n; ++i) {
            cout << "Element #" << i + 1 << " - ";
            arr[i].input();
        }
        Rational minVal = arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
        }
        cout << "Minimum rational number: " << minVal << "\n\n";
        // --- Task 2: Calculate the series sum with precision 0.01 ---
        // Series: 1 - 1/2^2 + 1/3^2 - 1/4^2 + ... = pi^2 / 12
        const double eps = 0.01;
        Rational sum(0, 1);
        long long k = 1;
        while (true) {
            long long sign = (k % 2 == 1) ? 1 : -1;
            Rational term(sign, k * k);

            if (abs(term.toDouble()) < eps) {
                break;
            }
            sum = sum + term;
            k++;
        }
        double pi = acos(-1.0);
        double expected = (pi * pi) / 12.0;
        cout << "Series sum (rational): " << sum << "\n";
        cout << "Series sum (decimal):  " << sum.toDouble() << "\n";
        cout << "Expected value pi^2/12: " << expected << "\n";
        cout << "Difference:            " << abs(sum.toDouble() - expected) << "\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}