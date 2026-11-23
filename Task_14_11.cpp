#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main() {
    const string filename = "input14_11.txt";
    const int MAX_WIDTH = 50;
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error: could not open " << filename << ".\n";
        return 1;
    }
    vector<string> lines;
    string line;
    while (getline(fin, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        lines.push_back(line);
    }
    fin.close();

    for (string& s : lines) {
        if (s.empty()) {
            continue;
        }
        if (static_cast<int>(s.length()) < MAX_WIDTH) {
            if (s.length() % 2 != 0) {
                s = " " + s;
            }
            int leftSpaces = (MAX_WIDTH - static_cast<int>(s.length())) / 2;
            s = string(leftSpaces, ' ') + s;
        }
    }
    ofstream fout(filename);
    if (!fout.is_open()) {
        cerr << "Error: could not open " << filename << " for writing.\n";
        return 1;
    }
    for (size_t i = 0; i < lines.size(); ++i) {
        fout << lines[i];
        if (i + 1 < lines.size()) {
            fout << "\n";
        }
    }
    fout.close();
    cout << "File " << filename << " has been successfully centered.\n";
    return 0;
}