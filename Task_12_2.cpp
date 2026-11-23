#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<unsigned long long> arr(n, 0);
    unsigned long long sum = 0;
    cout << "Enter " << 10 * n << " digits:\n";
    for (int i = 0; i < n; ++i) {
        unsigned long long current_num = 0;
        for (int j = 0; j < 10; ++j) {
            char digit;
            cin >> digit;
            current_num = current_num * 10 + (digit - '0');
        }
        arr[i] = current_num;
        sum += arr[i];
    }
    cout << "Sum of numbers: " << sum << endl;
    return 0;
}