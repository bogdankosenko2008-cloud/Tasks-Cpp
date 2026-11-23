#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
void createFile(const string& filename, int n) {
    ofstream fout(filename);
    cout << "Enter data for " << n << " students (Surname Course Group Grades separated by commas):\n";
    cout << "Example: Ivanov 2 KB-21 5, 4, 3, 4\n";
    cin.ignore(); // Clear newline after reading n

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        fout << line << "\n";
    }
    fout.close();
}
int main() {
    const string filename = "students.txt";
    int n;
    cout << "Enter number of students N: ";
    cin >> n;
    createFile(filename, n);
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error: could not open " << filename << ".\n";
        return 1;
    }
    string line;
    string worstSurname;
    double minAvg = 1e9;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        for (char& c : line) {
            if (c == ',') c = ' ';
        }
        stringstream ss(line);
        string surname, group;
        int course;
        ss >> surname >> course >> group;
        int grade, sum = 0, count = 0;
        while (ss >> grade) {
            sum += grade;
            count++;
        }
        if (count > 0) {
            double avg = static_cast<double>(sum) / count;
            if (avg < minAvg) {
                minAvg = avg;
                worstSurname = surname;
            }
        }
    }
    fin.close();
    if (!worstSurname.empty()) {
        cout << "Student with the lowest average grade: " << worstSurname
             << " (" << minAvg << ")\n";
    } else {
        cout << "No valid student records found.\n";
    }
    return 0;
}