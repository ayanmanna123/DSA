#include <iostream>
using namespace std;

class InputRestrictedQueue {
private:
    int arr[100];
    int frontIndex, rearIndex;
    int count;

public:
    InputRestrictedQueue() {
        frontIndex = 50;
        rearIndex = 49;
        count = 0;
    }

    // ✅ Insert at rear only
    void push_back(int value) {
        if (rearIndex == 99) {
            cout << "Queue is full at rear\n";
            return;
        }
        rearIndex++;
        arr[rearIndex] = value;
        count++;
    }

    // ❌ No push_front allowed
    void push_front(int value) {
        cout << "Insertion at front is not allowed in Input-Restricted Queue\n";
    }

    // ✅ Delete from front
    void pop_front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }
        frontIndex++;
        count--;
    }

    // ✅ Delete from rear
    void pop_back() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }
        rearIndex--;
        count--;
    }

    // Front element
    int front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    // Rear element
    int back() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rearIndex];
    }

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};
int main() {
    InputRestrictedQueue q;

    q.push_back(10);
    q.push_back(20);
    q.push_back(30);

    cout << "Front: " << q.front() << endl; // 10
    cout << "Back: " << q.back() << endl;   // 30

    q.pop_front(); // removes 10
    q.pop_back();  // removes 30

    q.push_front(5); // Should show error message

    cout << "Front now: " << q.front() << endl; // 20

    return 0;
}
