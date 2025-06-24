#include <iostream>
using namespace std;

class MyClass {
    int* data;

public:
    // Constructor
    MyClass(int value) {
        data = new int;
        *data = value;
    }

    // Deep Copy Constructor
    MyClass(const MyClass& other) {
        data = new int;          // allocate new memory
        *data = *(other.data);   // copy the value
    }

    // Show data
    void show() {
        cout << "Value: " << *data << endl;
    }

    // Destructor
    ~MyClass() {
        delete data;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1;  // deep copy

    obj1.show();  // Output: Value: 10
    obj2.show();  // Output: Value: 10

    return 0;
}
