#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Array {
private:
    int size;
    T* data;

public:
    // Constructor
    Array(int n = 0) : size(n) {
        if (n < 0) {
            throw invalid_argument("Array size cannot be negative.");
        }
        data = (size > 0) ? new T[size]() : nullptr;
    }

    // Copy constructor
    Array(const Array& other) : size(other.size) {
        data = (size > 0) ? new T[size] : nullptr;
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment operator
    Array& operator=(const Array& other) {
        if (this == &other) return *this;
        delete[] data;
        size = other.size;
        data = (size > 0) ? new T[size] : nullptr;
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] data;
    }

    int getSize() const { return size; }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }
        return data[index];
    }

    void input() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; ++i) {
            cin >> data[i];
        }
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }

    // 1) Static inplace Insertion Sort for any raw array
    static void insertionSort(T* arr, int n) {
        if (!arr || n <= 1) return;

        for (int i = 1; i < n; ++i) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }

    // 2) Member inplace Insertion Sort for the object's own array
    void insertionSort() {
        insertionSort(data, size);
    }
};

int main() {
    // --- 1. Testing member method on Array<int> ---
    int n;
    cout << "Enter size of integer array: ";
    cin >> n;

    Array<int> myArr(n);
    myArr.input();

    cout << "Before member insertionSort: ";
    myArr.print();

    myArr.insertionSort();

    cout << "After member insertionSort:  ";
    myArr.print();

    // --- 2. Testing static method on raw double array ---
    double rawArr[] = {4.2, -1.5, 3.8, 0.0, 2.1};
    int rawSize = 5;

    cout << "\nRaw double array before static insertionSort: ";
    for (int i = 0; i < rawSize; ++i) cout << rawArr[i] << " ";
    cout << "\n";

    Array<double>::insertionSort(rawArr, rawSize);

    cout << "Raw double array after static insertionSort:  ";
    for (int i = 0; i < rawSize; ++i) cout << rawArr[i] << " ";
    cout << "\n";

    return 0;
}