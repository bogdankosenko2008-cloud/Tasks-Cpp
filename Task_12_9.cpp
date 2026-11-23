#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    const string filename = "input.txt";
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error: could not open " << filename << ".\n";
        return 1;
    }
    vector<unsigned long long> nums;
    unsigned long long current;
    while (fin >> current) {
        nums.push_back(current);
    }
    fin.close();

    for (size_t i = 0; i + 1 < nums.size(); ++i) {
        if (nums[i] > nums[i + 1]) {
            nums[i] = nums[i] * nums[i];
        }
    }

    ofstream fout(filename);
    if (!fout.is_open()) {
        cerr << "Error: could not open " << filename << " for writing.\n";
        return 1;
    }
    for (size_t i = 0; i < nums.size(); ++i) {
        fout << nums[i];
        if (i + 1 < nums.size()) {
            fout << " ";
        }
    }
    fout.close();
    cout << "File " << filename << " has been successfully rewritten.\n";
    return 0;
}