#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
bool isDelimiter(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t' ||
           ch == ',' || ch == '.' || ch == '!' || ch == '?';
}
int main() {
    ifstream fin("input_14_3.txt");
    if (!fin.is_open()) {
        cerr << "Error: could not open input_14_3.txt.\n";
        return 1;
    }
    ofstream fout("output_14_3.txt");
    string word;
    char ch;
    while (fin.get(ch)) {
        if (isDelimiter(ch)) {
            if (!word.empty()) {
                reverse(word.begin(), word.end());
                fout << word;
                word.clear();
            }
            fout << ch;
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        reverse(word.begin(), word.end());
        fout << word;
    }
    fin.close();
    fout.close();
    cout << "Message decrypted to output_14_3.txt.\n";
    return 0;
}