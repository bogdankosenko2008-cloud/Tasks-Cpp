#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cout << "Enter matrix dimensions n and m (n, m < 100): ";
    cin >> n >> m;

    if (n <= 0 || n >= 100 || m <= 0 || m >= 100) {
        cerr << "Error: n and m must be between 1 and 99.\n";
        return 1;
    }

    vector<list<double>> matrix(n);
    cout << "Enter matrix elements (" << n << " rows of " << m << " numbers):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            double val;
            cin >> val;
            matrix[i].push_back(val);
        }
    }

    // Sort rows in descending order of their maximum elements
    sort(matrix.begin(), matrix.end(), [](const list<double>& a, const list<double>& b) {
        double maxA = *max_element(a.begin(), a.end());
        double maxB = *max_element(b.begin(), b.end());
        return maxA > maxB;
    });

    cout << "\nMatrix after sorting rows by descending maximum element:\n";
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << val << "\t";
        }
        cout << " (max = " << *max_element(row.begin(), row.end()) << ")\n";
    }

    return 0;
}