#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
int main() {
    int n;
    cout << "Enter a natural number n: ";
    cin >> n;
    const int col_width = 7;
    string border(n * col_width + 2, '+');
    cout << border << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << setw(col_width) << i;
    }
    cout << "\n" << border << "\n";
    for (int i = 1; i <= n; ++i) {
        int root_int = static_cast<int>(round(sqrt(i)));
        if (root_int * root_int == i) {
            cout << setw(col_width) << root_int;
        } else {
            cout << setw(col_width) << fixed << setprecision(2) << sqrt(i);
        }
    }
    cout << "\n" << border << endl;
    return 0;
}