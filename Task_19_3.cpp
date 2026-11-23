#include <iostream>
#include <list>
#include <vector>
#include <numeric>
#include <stdexcept>

using namespace std;

// Rational class from previous tasks
class Rational {
private:
    long long nom, denom;

    void reduce() {
        if (denom < 0) { nom = -nom; denom = -denom; }
        if (nom == 0) { denom = 1; return; }
        long long g = gcd(abs(nom), denom);
        nom /= g;
        denom /= g;
    }

public:
    Rational(long long n = 0, long long d = 1) : nom(n), denom(d) {
        if (denom == 0) throw invalid_argument("Denominator cannot be zero.");
        reduce();
    }

    Rational operator+(const Rational& o) const {
        return Rational(nom * o.denom + o.nom * denom, denom * o.denom);
    }
    Rational operator*(const Rational& o) const {
        return Rational(nom * o.nom, denom * o.denom);
    }
    bool operator==(const Rational& o) const {
        return nom == o.nom && denom == o.denom;
    }
    bool operator!=(const Rational& o) const { return !(*this == o); }

    friend ostream& operator<<(ostream& os, const Rational& r) {
        if (r.denom == 1) os << r.nom;
        else os << r.nom << "/" << r.denom;
        return os;
    }
    friend istream& operator>>(istream& is, Rational& r) {
        long long n, d;
        is >> n >> d;
        r = Rational(n, d);
        return is;
    }
};

// Template Polynomial based on std::list<T>
template <typename T>
class Polynomial {
private:
    list<T> coeffs; // Stored from x^0 to x^n

public:
    Polynomial() = default;
    Polynomial(const list<T>& c) : coeffs(c) {}

    // Input from stream
    void input(int degree) {
        coeffs.clear();
        cout << "Enter " << degree + 1 << " coefficients (from x^0 to x^" << degree << "): ";
        for (int i = 0; i <= degree; ++i) {
            T val;
            cin >> val;
            coeffs.push_back(val);
        }
    }

    // Output to stream
    void print() const {
        if (coeffs.empty()) {
            cout << "0\n";
            return;
        }
        int power = 0;
        bool first = true;
        for (const T& c : coeffs) {
            if (!first) cout << " + ";
            cout << "(" << c << ")";
            if (power > 0) cout << "*x^" << power;
            first = false;
            power++;
        }
        cout << "\n";
    }

    // Addition
    Polynomial<T> operator+(const Polynomial<T>& other) const {
        list<T> res;
        auto it1 = coeffs.begin();
        auto it2 = other.coeffs.begin();

        while (it1 != coeffs.end() || it2 != other.coeffs.end()) {
            T val = T(0);
            if (it1 != coeffs.end()) { val = val + *it1; ++it1; }
            if (it2 != other.coeffs.end()) { val = val + *it2; ++it2; }
            res.push_back(val);
        }
        return Polynomial<T>(res);
    }

    // Multiplication
    Polynomial<T> operator*(const Polynomial<T>& other) const {
        if (coeffs.empty() || other.coeffs.empty()) return Polynomial<T>();

        size_t resSize = coeffs.size() + other.coeffs.size() - 1;
        vector<T> temp(resSize, T(0));

        size_t i = 0;
        for (auto it1 = coeffs.begin(); it1 != coeffs.end(); ++it1, ++i) {
            size_t j = 0;
            for (auto it2 = other.coeffs.begin(); it2 != other.coeffs.end(); ++it2, ++j) {
                temp[i + j] = temp[i + j] + (*it1 * *it2);
            }
        }
        return Polynomial<T>(list<T>(temp.begin(), temp.end()));
    }

    // Evaluate polynomial at point x using Horner's method
    T evaluate(const T& x) const {
        T result = T(0);
        for (auto it = coeffs.rbegin(); it != coeffs.rend(); ++it) {
            result = result * x + *it;
        }
        return result;
    }
};

int main() {
    // 1. Test with int
    cout << "=== 1. Polynomial<int> ===\n";
    Polynomial<int> pInt1({1, 2, 3}); // 1 + 2x + 3x^2
    Polynomial<int> pInt2({4, 5});    // 4 + 5x
    cout << "P1: "; pInt1.print();
    cout << "P2: "; pInt2.print();
    cout << "P1 + P2: "; (pInt1 + pInt2).print();
    cout << "P1 * P2: "; (pInt1 * pInt2).print();
    cout << "P1(2) = " << pInt1.evaluate(2) << "\n\n";

    // 2. Test with double
    cout << "=== 2. Polynomial<double> ===\n";
    Polynomial<double> pDbl1({1.5, -2.0});
    Polynomial<double> pDbl2({0.5, 4.0});
    cout << "P1 + P2: "; (pDbl1 + pDbl2).print();
    cout << "P1 * P2: "; (pDbl1 * pDbl2).print();
    cout << "P1(1.5) = " << pDbl1.evaluate(1.5) << "\n\n";

    // 3. Test with Rational
    cout << "=== 3. Polynomial<Rational> ===\n";
    Polynomial<Rational> pRat1({Rational(1, 2), Rational(2, 3)}); // 1/2 + 2/3 x
    Polynomial<Rational> pRat2({Rational(3, 4), Rational(1, 3)}); // 3/4 + 1/3 x
    cout << "P1: "; pRat1.print();
    cout << "P2: "; pRat2.print();
    cout << "P1 + P2: "; (pRat1 + pRat2).print();
    cout << "P1 * P2: "; (pRat1 * pRat2).print();
    cout << "P1(1/2) = " << pRat1.evaluate(Rational(1, 2)) << "\n";

    return 0;
}