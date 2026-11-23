#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class Polynomial {
private:
    int n;          // Number of elements (degree is n - 1)
    double* coeffs; // Dynamic array of coefficients

public:
    // Constructor with size N (and optional array initialization)
    Polynomial(int size, const double* initCoeffs = nullptr) : n(size) {
        if (n <= 0) {
            throw invalid_argument("Size N must be positive.");
        }
        coeffs = new double[n];
        for (int i = 0; i < n; ++i) {
            coeffs[i] = initCoeffs ? initCoeffs[i] : 0.0;
        }
    }

    // Copy constructor
    Polynomial(const Polynomial& other) : n(other.n) {
        coeffs = new double[n];
        for (int i = 0; i < n; ++i) {
            coeffs[i] = other.coeffs[i];
        }
    }

    // Copy assignment operator (Rule of Three)
    Polynomial& operator=(const Polynomial& other) {
        if (this == &other) return *this;
        delete[] coeffs;
        n = other.n;
        coeffs = new double[n];
        for (int i = 0; i < n; ++i) {
            coeffs[i] = other.coeffs[i];
        }
        return *this;
    }

    // Destructor
    ~Polynomial() {
        delete[] coeffs;
    }

    // Method to fill all coefficients
    void fillAll() {
        cout << "Enter " << n << " coefficients (from x^0 to x^" << n - 1 << "): ";
        for (int i = 0; i < n; ++i) {
            cin >> coeffs[i];
        }
    }

    // Method to set a specific coefficient by index
    void setCoefficient(int index, double value) {
        if (index < 0 || index >= n) {
            throw out_of_range("Coefficient index out of range.");
        }
        coeffs[index] = value;
    }

    // Method to display the polynomial
    void print() const {
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1 && coeffs[i] >= 0) cout << "+";
            cout << coeffs[i];
            if (i > 0) cout << "x^" << i << " ";
        }
        cout << "\n";
    }

    // Friend functions for console input and binary file I/O
    friend istream& operator>>(istream& is, Polynomial& p);
    friend void writeToBinary(const string& filename, const Polynomial& p);
    friend void readFromBinary(const string& filename, Polynomial& p);
};

// Friend function: input from console
istream& operator>>(istream& is, Polynomial& p) {
    cout << "Enter " << p.n << " coefficients (from x^0 to x^" << p.n - 1 << "): ";
    for (int i = 0; i < p.n; ++i) {
        is >> p.coeffs[i];
    }
    return is;
}

// Friend function: write polynomial to a binary file
void writeToBinary(const string& filename, const Polynomial& p) {
    ofstream fout(filename, ios::binary);
    if (!fout.is_open()) {
        throw runtime_error("Could not open binary file for writing.");
    }
    fout.write(reinterpret_cast<const char*>(&p.n), sizeof(p.n));
    fout.write(reinterpret_cast<const char*>(p.coeffs), p.n * sizeof(double));
    fout.close();
}

// Friend function: read polynomial from a binary file
void readFromBinary(const string& filename, Polynomial& p) {
    ifstream fin(filename, ios::binary);
    if (!fin.is_open()) {
        throw runtime_error("Could not open binary file for reading.");
    }
    int fileN = 0;
    fin.read(reinterpret_cast<char*>(&fileN), sizeof(fileN));
    if (fileN <= 0) {
        throw runtime_error("Invalid data in binary file.");
    }

    delete[] p.coeffs;
    p.n = fileN;
    p.coeffs = new double[p.n];
    fin.read(reinterpret_cast<char*>(p.coeffs), p.n * sizeof(double));
    fin.close();
}

int main() {
    try {
        int n;
        cout << "Enter number of polynomial coefficients N: ";
        cin >> n;

        Polynomial p1(n);
        cin >> p1; // Using friend input function

        cout << "Polynomial P1: ";
        p1.print();

        // Update one coefficient by index
        if (n > 1) {
            p1.setCoefficient(1, 9.5);
            cout << "After updating coefficient at index 1 to 9.5: ";
            p1.print();
        }

        // Write to binary file and read into another object
        const string binFile = "poly.bin";
        writeToBinary(binFile, p1);
        cout << "Saved P1 to " << binFile << ".\n";

        Polynomial p2(1);
        readFromBinary(binFile, p2);
        cout << "Loaded P2 from " << binFile << ": ";
        p2.print();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}