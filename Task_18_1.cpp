#include <iostream>
#include <string>
#include <numeric>
#include <stdexcept>

using namespace std;

namespace Task1Namespace {

    // Template function for finding maximum of two values
    template <typename T>
    T getMax(const T& a, const T& b) {
        return (a > b) ? a : b;
    }

    // Class Rational from previous lectures with overloaded operator>
    class Rational {
    private:
        long long nom;
        long long denom;

        void reduce() {
            if (denom < 0) {
                nom = -nom;
                denom = -denom;
            }
            if (nom == 0) {
                denom = 1;
                return;
            }
            long long g = gcd(abs(nom), denom);
            nom /= g;
            denom /= g;
        }

    public:
        Rational(long long n = 0, long long d = 1) : nom(n), denom(d) {
            if (denom == 0) throw invalid_argument("Denominator cannot be zero.");
            reduce();
        }

        // Overloading operator> so getMax works with Rational
        bool operator>(const Rational& other) const {
            return nom * other.denom > other.nom * denom;
        }

        friend ostream& operator<<(ostream& os, const Rational& r) {
            if (r.denom == 1) os << r.nom;
            else os << r.nom << "/" << r.denom;
            return os;
        }
    };

} // namespace Task1Namespace

int main() {
    using namespace Task1Namespace;

    // 1. Standard numeric types
    cout << "Max int (15, 42): " << getMax(15, 42) << "\n";
    cout << "Max double (-3.5, 2.1): " << getMax(-3.5, 2.1) << "\n";

    // 2. Strings (works for std::string because operator> is already defined for it)
    string s1 = "apple", s2 = "orange";
    cout << "Max string (\"apple\", \"orange\"): " << getMax(s1, s2) << "\n";

    // 3. Rational fractions (works because we overloaded operator>)
    Rational r1(2, 3), r2(3, 4);
    cout << "Max Rational (2/3, 3/4): " << getMax(r1, r2) << "\n";

    return 0;
}