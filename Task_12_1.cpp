#include <iostream>
#include <cmath>
#include <iomanip>
int main() {
    double x, y;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
    double result = std::pow(x, y);
    std::cout << "Decimal format: " << std::fixed << std::setprecision(6) << result << "\n";
    std::cout << "Scientific format: " << std::scientific << std::setprecision(6) << result << "\n";
    return 0;
}