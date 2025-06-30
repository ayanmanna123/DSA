#include <iostream>
using namespace std;

class OutputRestrictedQueue {
private:
    int arr[100];
    int frontIndex, rearIndex;
    int count;

public:
    OutputRestrictedQueue() {
        frontIndex = 50;
        rearIndex = 49;
        count = 0;
    }

    // ✅ Insert at rear
    void push_back(int value) {
        if (rearIndex == 99) {
            cout << "No space at rear\n";
            return;
        }
        rearIndex++;
        arr[rearIndex] = value;
        count++;
    }

    // ✅ Insert at front
    void push_front(int value) {
        if (frontIndex == 0) {
            cout << "No space at front\n";
            return;
        }
        frontIndex--;
        arr[frontIndex] = value;
        count++;
    }

    // ✅ Delete from front only
    void pop_front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }
        frontIndex++;
        count--;
    }

    // ❌ No deletion from back
    void pop_back() {
        cout << "Deletion from back is not allowed in Output-Restricted Queue\n";
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

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
    OutputRestrictedQueue q;

    q.push_back(20);
    q.push_front(10);
    q.push_back(30);

    cout << "Front: " << q.front() << endl; // 10
    cout << "Back: " << q.back() << endl;   // 30

    q.pop_back(); // Should show error message
    q.pop_front(); // Removes 10

    cout << "New Front: " << q.front() << endl; // 20

    return 0;
}
