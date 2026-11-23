#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input14_1.txt");
    if (!fin.is_open()) {
        cerr << "Error: could not open input14_1.txt.\n";
        return 1;
    }

    double result = 0.0, num = 0.0;
    char op;

    if (!(fin >> result)) {
        cerr << "Error: invalid expression format.\n";
        return 1;
    }

    while (fin >> op && op != '=') {
        if (!(fin >> num)) {
            cerr << "Error: expected a number after operator.\n";
            return 1;
        }
        if (op == '+') {
            result += num;
        } else if (op == '-') {
            result -= num;
        }
    }

    fin.close();
    cout << "Result: " << result << endl;
    return 0;
}