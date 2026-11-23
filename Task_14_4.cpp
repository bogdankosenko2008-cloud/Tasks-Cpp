#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream fin("input14_4.txt");
    if (!fin.is_open()) {
        cerr << "Error: could not open input14_4.txt.\n";
        return 1;
    }
    string text((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();
    int balance = 0;
    bool isValid = true;
    for (size_t i = 0; i < text.size(); ++i) {
        if (text.compare(i, 4, "<td>") == 0) {
            balance++;
            i += 3;
        } else if (text.compare(i, 5, "</td>") == 0) {
            balance--;
            if (balance < 0) {
                isValid = false;
                break;
            }
            i += 4;
        }
    }
    if (balance != 0) isValid = false;

    if (isValid) {
        cout << "Tags are placed correctly.\n";
    } else {
        cout << "Error: incorrect tag placement.\n";
    }
    return 0;
}