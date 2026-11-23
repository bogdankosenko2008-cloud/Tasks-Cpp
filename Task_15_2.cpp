#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
class Point {
private:
    double x, y;
    static int count;
public:
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {
        count++;
    }
    Point(const Point& other) : x(other.x), y(other.y) {
        count++;
    }
    ~Point() {
        count--;
    }
    static int counter() {
        return count;
    }
    double distanceTo(const Point& other) const {
        return hypot(x - other.x, y - other.y);
    }
};
// Initialize static member
int Point::count = 0;
int main() {
    vector<Point*> polygon;
    string answer;
    while (true) {
        cout << "Enter vertex? (Yes/No): ";
        cin >> answer;
        if (answer == "No" || answer == "no" || answer == "NO") {
            break;
        }
        if (answer == "Yes" || answer == "yes" || answer == "YES") {
            double x, y;
            cout << "Enter x and y coordinates: ";
            cin >> x >> y;
            polygon.push_back(new Point(x, y));
        } else {
            cout << "Please answer Yes or No.\n";
        }
    }
    int n = Point::counter();
    cout << "\nNumber of vertices in polygon: " << n << "\n";
    if (n < 3) {
        cout << "A polygon must have at least 3 vertices to calculate a perimeter.\n";
    } else {
        double perimeter = 0.0;
        for (int i = 0; i < n; ++i) {
            perimeter += polygon[i]->distanceTo(*polygon[(i + 1) % n]);
        }
        cout << "Polygon perimeter: " << perimeter << "\n";
    }
    // Free allocated memory
    for (Point* p : polygon) {
        delete p;
    }
    return 0;
}