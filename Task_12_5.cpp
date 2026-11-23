#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    ifstream fin("input2.txt");
    if (!fin.is_open()) {
        cerr << "Error: could not open input2.txt.\n";
        return 1;
    }
    vector<unsigned long long> nums;
    unsigned long long current;
    while (fin >> current) {
        nums.push_back(current);
    }
    fin.close();
    cout << fixed << setprecision(3);
    for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i) {
        cout << sqrtl(static_cast<long double>(nums[i])) << "\n";
    }
    return 0;
}