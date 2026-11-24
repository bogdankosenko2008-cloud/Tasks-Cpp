#include <iostream>
#include <stdexcept>
#include <limits>
#include <iomanip>
class Matrix {
private:
    size_t rows;    // Кількість рядків (n)
    size_t cols;    // Кількість стовпців (m)
    double* data;   // Вказівник на єдиний динамічний блок пам'яті
public:
    // 1. Конструктор із перевіркою розмірів та захистом від переповнення
    Matrix(size_t n, size_t m) : rows(n), cols(m), data(nullptr) {
        // Перевірка на нульові розміри
        if (n == 0 || m == 0) {
            throw std::invalid_argument("Error: Matrix dimensions must be greater than zero.");
        }
        // Перевірка на можливе переповнення при множенні n * m
        if (n > std::numeric_limits<size_t>::max() / m) {
            throw std::overflow_error("Error: Matrix size overflow (n * m is too large).");
        }
        // Виділення єдиного неперервного блоку пам'яті для n * m елементів
        // Круглі дужки () ініціалізують усі елементи нулями
        data = new double[rows * cols]();
    }
    // 2. Деструктор для звільнення виділеної пам'яті (запобігання витоку пам'яті)
    ~Matrix() {
        delete[] data;
    }
    // 3. Конструктор копіювання (незалежне глибоке копіювання)
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(nullptr) {
        size_t total_elements = rows * cols;
        // Виділяємо новий блок пам'яті для копії
        data = new double[total_elements];
        // Поелементно копіюємо дані зі старої матриці в нову
        for (size_t i = 0; i < total_elements; ++i) {
            data[i] = other.data[i];
        }
    }
    // 4. Оператор присвоєння з безпечною обробкою самоприсвоєння
    Matrix& operator=(const Matrix& other) {
        // Перевірка на самоприсвоєння (наприклад, a = a)
        if (this == &other) {
            return *this;
        }
        size_t total_elements = other.rows * other.cols;
        // Спочатку виділяємо нову пам'ять (безпека при винятках: якщо new впаде, старі дані не втратяться)
        double* new_data = new double[total_elements];
        for (size_t i = 0; i < total_elements; ++i) {
            new_data[i] = other.data[i];
        }
        // Звільняємо стару пам'ять поточного об'єкта
        delete[] data;
        // Оновлюємо поля об'єкта
        rows = other.rows;
        cols = other.cols;
        data = new_data;
        return *this;
    }
    // Допоміжні методи доступу до елементів (перетворення 2D-індексів у 1D-індекс)
    double& at(size_t r, size_t c) {
        return data[r * cols + c];
    }
    const double& at(size_t r, size_t c) const {
        return data[r * cols + c];
    }
    // Геттери для отримання розмірів
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }
    // 5. Метод транспонування матриці (повертає новий об'єкт Matrix розміром m x n)
    Matrix transpose() const {
        // Створюємо нову матрицю зі зміненими місцями рядками та стовпцями
        Matrix result(cols, rows);
        // Заповнюємо транспоновану матрицю: елемент [i][j] стає [j][i]
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.at(j, i) = this->at(i, j);
            }
        }
        return result;
    }
    // Метод для виведення матриці в консоль
    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << std::setw(8) << at(i, j) << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    try {
        size_t n, m;

        // Зчитування розмірів матриці
        std::cout << "Enter number of rows (1..20): ";
        if (!(std::cin >> n)) {
            std::cerr << "Invalid input format.\n";
            return 1;
        }
        std::cout << "Enter number of columns (1..20): ";
        if (!(std::cin >> m)) {
            std::cerr << "Invalid input format.\n";
            return 1;
        }
        // Валідація діапазону 1..20 згідно з умовою задачі
        if (n < 1 || n > 20 || m < 1 || m > 20) {
            std::cerr << "Error: Dimensions must be between 1 and 20.\n";
            return 1;
        }
        // Створення початкової матриці
        Matrix original(n, m);
        // Зчитування елементів матриці з клавіатури
        std::cout << "Enter " << n * m << " real numbers:\n";
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (!(std::cin >> original.at(i, j))) {
                    std::cerr << "Error reading matrix element.\n";
                    return 1;
                }
            }
        }
        // Створення незалежної копії матриці (викликається конструктор копіювання)
        Matrix copyMatrix = original;
        // Перевірка оператора присвоєння та самоприсвоєння (для демонстрації безпеки)
        copyMatrix = copyMatrix;
        // Транспонування скопійованої матриці
        Matrix transposedMatrix = copyMatrix.transpose();
        // Виведення результатів англійською мовою
        std::cout << "\nOriginal Matrix (" << original.getRows() << "x" << original.getCols() << "):\n";
        original.print();
        std::cout << "\nTransposed Copy (" << transposedMatrix.getRows() << "x" << transposedMatrix.getCols() << "):\n";
        transposedMatrix.print();
    } catch (const std::exception& e) {
        // Перехоплення та виведення будь-яких винятків (помилки пам'яті або розмірів)
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0; // Усі деструктори автоматично викличуться тут, пам'ять буде очищено
}