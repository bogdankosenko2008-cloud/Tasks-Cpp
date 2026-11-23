#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
string toLowerStr(string s) {
    for (char& c : s) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }
    return s;
}
int main() {
    ifstream fin("input14_2.txt");
    if (!fin.is_open()) {
        cerr << "Error: could not open input14_2.txt.\n";
        return 1;
    }
    ofstream fout("output14_2.txt");
    string word, prevWord;
    bool first = true;
    while (fin >> word) {
        string prevLower = toLowerStr(prevWord);
        if (prevLower == "die" || prevLower == "der" || prevLower == "das") {
            word[0] = static_cast<char>(toupper(static_cast<unsigned char>(word[0])));
        }
        if (!first) fout << " ";
        fout << word;
        first = false;
        prevWord = word;
    }
    fin.close();
    fout.close();
    cout << "Done. Result written to output14_2.txt.\n";
    return 0;
}