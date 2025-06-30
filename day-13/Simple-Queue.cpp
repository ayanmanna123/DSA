#include <iostream>
using namespace std;

class SimpleQueue {
private:
    int frontIndex, rearIndex;
    int arr[100];      // Fixed size queue
    int capacity;

public:
    SimpleQueue() {
        frontIndex = 0;
        rearIndex = -1;
        capacity = 0;
    }

    // Push element to the rear
    void push(int value) {
        if (rearIndex == 99) {
            cout << "Queue is full\n";
            return;
        }
        rearIndex++;
        arr[rearIndex] = value;
        capacity++;
    }

    // Remove element from the front
    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }
        frontIndex++;
        capacity--;
    }

    // Return front element
    int front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    // Check if queue is empty
    bool empty() {
        return capacity == 0;
    }

    // Return size of queue
    int size() {
        return capacity;
    }
};
int main() {
    SimpleQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // 10
    q.pop();
    cout << "Front after pop: " << q.front() << endl; // 20

    cout << "Queue size: " << q.size() << endl;

    while (!q.empty()) {
        cout << "Removing: " << q.front() << endl;
        q.pop();
    }

    q.pop(); // Should show "Queue is empty"
    return 0;
}
