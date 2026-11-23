#include <iostream>
#include <utility>
#include <string>
#include <stdexcept>
#include <type_traits>
#include <cmath>
#include <numeric>

using namespace std;

// ============================================================================
// 1. Primary template Rational<N, D> based on std::pair<N, D>
// ============================================================================
template <typename N, typename D>
class Rational {
private:
    pair<N, D> data;

    void normalize() {
        if (data.second == static_cast<D>(0)) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        if (data.second < static_cast<D>(0)) {
            data.first = -data.first;
            data.second = -data.second;
        }
        if constexpr (is_integral_v<N> && is_integral_v<D>) {
            if (data.first == 0) {
                data.second = 1;
            } else {
                auto g = gcd(abs(static_cast<long long>(data.first)),
                             abs(static_cast<long long>(data.second)));
                data.first = static_cast<N>(data.first / g);
                data.second = static_cast<D>(data.second / g);
            }
        }
    }

public:
    Rational(N num = N(0), D den = D(1)) : data(num, den) {
        normalize();
    }

    // Accessors
    N getNumerator() const { return data.first; }
    D getDenominator() const { return data.second; }
    void setNumerator(N num) { data.first = num; normalize(); }
    void setDenominator(D den) { data.second = den; normalize(); }
    const pair<N, D>& asPair() const { return data; }

    // Arithmetic operators
    template <typename N2, typename D2>
    auto operator+(const Rational<N2, D2>& o) const {
        using C = common_type_t<N, D, N2, D2>;
        C num = static_cast<C>(data.first) * o.getDenominator() +
                static_cast<C>(o.getNumerator()) * data.second;
        C den = static_cast<C>(data.second) * o.getDenominator();
        return Rational<C, C>(num, den);
    }

    template <typename N2, typename D2>
    auto operator-(const Rational<N2, D2>& o) const {
        using C = common_type_t<N, D, N2, D2>;
        C num = static_cast<C>(data.first) * o.getDenominator() -
                static_cast<C>(o.getNumerator()) * data.second;
        C den = static_cast<C>(data.second) * o.getDenominator();
        return Rational<C, C>(num, den);
    }

    template <typename N2, typename D2>
    auto operator*(const Rational<N2, D2>& o) const {
        using C = common_type_t<N, D, N2, D2>;
        return Rational<C, C>(static_cast<C>(data.first) * o.getNumerator(),
                              static_cast<C>(data.second) * o.getDenominator());
    }

    template <typename N2, typename D2>
    auto operator/(const Rational<N2, D2>& o) const {
        if (o.getNumerator() == 0) {
            throw domain_error("Division by zero fraction.");
        }
        using C = common_type_t<N, D, N2, D2>;
        return Rational<C, C>(static_cast<C>(data.first) * o.getDenominator(),
                              static_cast<C>(data.second) * o.getNumerator());
    }

    // Remainder: divide fractions and remove the integer part
    template <typename N2, typename D2>
    auto operator%(const Rational<N2, D2>& o) const {
        if (o.getNumerator() == 0) {
            throw domain_error("Modulo by zero fraction.");
        }
        using C = common_type_t<N, D, N2, D2>;
        C num = static_cast<C>(data.first) * o.getDenominator();
        C den = static_cast<C>(data.second) * o.getNumerator();

        if constexpr (is_integral_v<C>) {
            num = num % den; // Removes integer part (truncates toward zero)
        } else {
            num = fmod(num, den);
        }
        return Rational<C, C>(num, den);
    }

    // Comparison operators
    template <typename N2, typename D2>
    bool operator==(const Rational<N2, D2>& o) const {
        using C = common_type_t<N, D, N2, D2>;
        return static_cast<C>(data.first) * o.getDenominator() ==
               static_cast<C>(o.getNumerator()) * data.second;
    }

    template <typename N2, typename D2>
    bool operator!=(const Rational<N2, D2>& o) const { return !(*this == o); }

    template <typename N2, typename D2>
    bool operator<(const Rational<N2, D2>& o) const {
        using C = common_type_t<N, D, N2, D2>;
        return static_cast<C>(data.first) * o.getDenominator() <
               static_cast<C>(o.getNumerator()) * data.second;
    }

    template <typename N2, typename D2>
    bool operator>(const Rational<N2, D2>& o) const { return o < *this; }

    template <typename N2, typename D2>
    bool operator<=(const Rational<N2, D2>& o) const { return !(*this > o); }

    template <typename N2, typename D2>
    bool operator>=(const Rational<N2, D2>& o) const { return !(*this < o); }

    // Stream I/O
    friend ostream& operator<<(ostream& os, const Rational<N, D>& r) {
        os << r.data.first << "/" << r.data.second;
        return os;
    }

    friend istream& operator>>(istream& is, Rational<N, D>& r) {
        N num;
        D den;
        is >> num >> den;
        r = Rational<N, D>(num, den);
        return is;
    }
};

// ============================================================================
// 2. Partial Specializations when Numerator and/or Denominator is std::string
// ============================================================================
template <typename N, typename D>
class StringRationalBase {
protected:
    pair<N, D> data;
    string repr;

    static string toStr(const string& s) { return s; }
    template <typename T>
    static string toStr(const T& val) { return to_string(val); }

    void updateRepr() {
        repr = toStr(data.first) + "/" + toStr(data.second);
    }

public:
    StringRationalBase(N num = N(), D den = D()) : data(num, den) {
        updateRepr();
    }

    // Accessors
    N getNumerator() const { return data.first; }
    D getDenominator() const { return data.second; }
    void setNumerator(const N& num) { data.first = num; updateRepr(); }
    void setDenominator(const D& den) { data.second = den; updateRepr(); }
    const string& str() const { return repr; }
    const pair<N, D>& asPair() const { return data; }

    // Addition = string concatenation
    string operator+(const StringRationalBase& other) const {
        return repr + other.repr;
    }

    // Other arithmetic operations throw exceptions
    string operator-(const StringRationalBase&) const {
        throw logic_error("Subtraction is not supported for string Rational.");
    }
    string operator*(const StringRationalBase&) const {
        throw logic_error("Multiplication is not supported for string Rational.");
    }
    string operator/(const StringRationalBase&) const {
        throw logic_error("Division is not supported for string Rational.");
    }
    string operator%(const StringRationalBase&) const {
        throw logic_error("Modulo is not supported for string Rational.");
    }

    // Comparison operators (compare formatted strings "num/den")
    bool operator==(const StringRationalBase& o) const { return repr == o.repr; }
    bool operator!=(const StringRationalBase& o) const { return repr != o.repr; }
    bool operator<(const StringRationalBase& o) const { return repr < o.repr; }
    bool operator>(const StringRationalBase& o) const { return repr > o.repr; }
    bool operator<=(const StringRationalBase& o) const { return repr <= o.repr; }
    bool operator>=(const StringRationalBase& o) const { return repr >= o.repr; }

    friend ostream& operator<<(ostream& os, const StringRationalBase& r) {
        os << r.repr;
        return os;
    }

    friend istream& operator>>(istream& is, StringRationalBase& r) {
        is >> r.data.first >> r.data.second;
        r.updateRepr();
        return is;
    }
};

// Specialization 1: Both numerator and denominator are std::string
template <>
class Rational<string, string> : public StringRationalBase<string, string> {
public:
    using StringRationalBase<string, string>::StringRationalBase;
};

// Specialization 2: Numerator is std::string, Denominator is any type D
template <typename D>
class Rational<string, D> : public StringRationalBase<string, D> {
public:
    using StringRationalBase<string, D>::StringRationalBase;
};

// Specialization 3: Numerator is any type N, Denominator is std::string
template <typename N>
class Rational<N, string> : public StringRationalBase<N, string> {
public:
    using StringRationalBase<N, string>::StringRationalBase;
};

// ============================================================================
// Main function to demonstrate numeric and string specializations
// ============================================================================
int main() {
    cout << "=== 1. Numeric Rational<int, long> ===\n";
    Rational<int, long> r1(7, 4);
    Rational<int, long> r2(1, 2);

    cout << "r1 = " << r1 << ", r2 = " << r2 << "\n";
    cout << "r1 + r2 = " << (r1 + r2) << "\n";
    cout << "r1 - r2 = " << (r1 - r2) << "\n";
    cout << "r1 * r2 = " << (r1 * r2) << "\n";
    cout << "r1 / r2 = " << (r1 / r2) << "\n";
    cout << "r1 % r2 = " << (r1 % r2) << " (7/4 div 1/2 = 3.5 -> remainder 0.5 = 1/2)\n";
    cout << "r1 > r2: " << boolalpha << (r1 > r2) << "\n\n";

    cout << "=== 2. String Specializations ===\n";
    Rational<string, int> sr1("alpha", 10);
    Rational<string, int> sr2("beta", 20);
    Rational<string, string> sr3("hello", "world");

    cout << "sr1 = " << sr1 << "\n";
    cout << "sr2 = " << sr2 << "\n";
    cout << "sr3 = " << sr3 << "\n";
    cout << "sr1 + sr2 (concatenation): " << (sr1 + sr2) << "\n";
    cout << "sr1 < sr2: " << (sr1 < sr2) << "\n";

    try {
        cout << "Trying sr1 * sr2: ";
        cout << (sr1 * sr2) << "\n";
    } catch (const exception& e) {
        cout << "Caught expected exception -> " << e.what() << "\n";
    }

    return 0;
}