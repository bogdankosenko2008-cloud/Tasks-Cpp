#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cout << "Enter a natural number n: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Error: n must be a natural number.\n";
        return 1;
    }
    int* m = new int[n];
    cout << "Enter " << n << " integers m_i:\n";
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Error: could not find or open input.txt.\n";
        delete[] m;
        return 1;
    }
    double* x = new double[n];
    for (int i = 0; i < n; ++i) {
        if (!(fin >> x[i])) {
            cerr << "Error: input.txt contains invalid data or fewer than " << n << " numbers.\n";
            fin.close();
            delete[] m;
            delete[] x;
            return 1;
        }
    }
    fin.close();
    ofstream fout("output.txt");
    if (!fout.is_open()) {
        cerr << "Error: could not create output.txt.\n";
        delete[] m;
        delete[] x;
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (x[i] == 0.0 && m[i] < 0) {
            cerr << "Warning: division by zero for element #" << i + 1 << ".\n";
            fout << "inf ";
        } else {
            fout << pow(x[i], m[i]) << " ";
        }
    }
    fout << "\n";
    fout.close();
    cout << "Calculation completed successfully. Results written to output.txt.\n";
    delete[] m;
    delete[] x;
    return 0;
}