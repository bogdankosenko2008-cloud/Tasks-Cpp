#include <iostream>
#include <stack> // Standard STL stack for verification
#include <stdexcept>

using namespace std;

namespace Task2Namespace {

    // Custom template Stack class for any data type
    template <typename T>
    class Stack {
    private:
        struct Node {
            T data;
            Node* next;
            Node(const T& val, Node* nxt) : data(val), next(nxt) {}
        };

        Node* topNode;
        size_t count;

    public:
        Stack() : topNode(nullptr), count(0) {}

        ~Stack() {
            while (!empty()) {
                pop();
            }
        }

        void push(const T& value) {
            topNode = new Node(value, topNode);
            count++;
        }

        void pop() {
            if (empty()) {
                throw underflow_error("Stack is empty.");
            }
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
            count--;
        }

        T& top() {
            if (empty()) {
                throw underflow_error("Stack is empty.");
            }
            return topNode->data;
        }

        const T& top() const {
            if (empty()) {
                throw underflow_error("Stack is empty.");
            }
            return topNode->data;
        }

        bool empty() const {
            return topNode == nullptr;
        }

        size_t size() const {
            return count;
        }
    };

    // Function inputs numbers until 0, fills dynamic array via reference,
    // and returns the count of elements
    template <typename T>
    int readUntilZero(T*& arr) {
        Stack<T> s;
        T value;

        cout << "Enter numbers (0 to finish): ";
        while (cin >> value && value != static_cast<T>(0)) {
            s.push(value);
        }

        int n = static_cast<int>(s.size());
        if (n == 0) {
            arr = nullptr;
            return 0;
        }

        arr = new T[n];
        for (int i = n - 1; i >= 0; --i) {
            arr[i] = s.top();
            s.pop();
        }

        return n;
    }

} // namespace Task2Namespace

int main() {
    // 1. Test with integers (int)
    cout << "--- Test 1: Integers (int) ---\n";
    int* intArray = nullptr;
    int intCount = Task2Namespace::readUntilZero(intArray);

    cout << "Array size: " << intCount << "\nElements: ";
    for (int i = 0; i < intCount; ++i) {
        cout << intArray[i] << " ";
    }
    cout << "\n\n";
    delete[] intArray;

    // 2. Test with another numeric type (double) + verification with STL std::stack
    cout << "--- Test 2: Floating-point numbers (double) & STL verification ---\n";
    double* doubleArray = nullptr;
    int doubleCount = Task2Namespace::readUntilZero(doubleArray);

    Task2Namespace::Stack<double> customStack;
    std::stack<double> stlStack;

    for (int i = 0; i < doubleCount; ++i) {
        customStack.push(doubleArray[i]);
        stlStack.push(doubleArray[i]);
    }

    cout << "Popping elements (Custom Stack vs STL Stack):\n";
    bool isSame = true;
    while (!customStack.empty() && !stlStack.empty()) {
        cout << "Custom: " << customStack.top() << " | STL: " << stlStack.top() << "\n";
        if (customStack.top() != stlStack.top()) {
            isSame = false;
        }
        customStack.pop();
        stlStack.pop();
    }

    cout << "Verification result: " << (isSame ? "PASSED" : "FAILED") << "\n";
    delete[] doubleArray;

    return 0;
}