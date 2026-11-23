#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> inputVector(int d) {
    vector<double> v(d);
    for (int i = 0; i < d; ++i) {
        cin >> v[i];
    }
    return v;
}

double vectorNorm(const vector<double>& v) {
    double sumSq = 0.0;
    for (double x : v) {
        sumSq += x * x;
    }
    return sqrt(sumSq);
}

int main() {
    int d, n;
    cout << "Enter vector dimension d: ";
    cin >> d;
    cout << "Enter number of vectors n: ";
    cin >> n;

    vector<vector<double>> vectors(n);
    double totalNormSum = 0.0;

    for (int i = 0; i < n; ++i) {
        cout << "Enter " << d << " coordinates for vector #" << i + 1 << ": ";
        vectors[i] = inputVector(d);
        totalNormSum += vectorNorm(vectors[i]);
    }

    cout << "\nSum of norms of all vectors: " << totalNormSum << "\n";
    return 0;
}