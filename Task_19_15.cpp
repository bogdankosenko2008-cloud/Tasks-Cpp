#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cout << "Enter number of integers n: ";
    cin >> n;

    list<int> L;
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        L.push_back(val);
    }

    // 1. Output in original order
    cout << "\nOriginal order: ";
    for (auto it = L.begin(); it != L.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    // 2. Output in reverse order using reverse iterators
    cout << "Reverse order:  ";
    for (auto rit = L.rbegin(); rit != L.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << "\n";

    // 3. Sort ascending in the list, then output descending (in reverse)
    L.sort();

    cout << "Sorted ascending, printed descending: ";
    for (auto rit = L.rbegin(); rit != L.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << "\n";

    return 0;
}