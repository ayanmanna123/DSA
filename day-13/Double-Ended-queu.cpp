#include <iostream>
using namespace std;

class Deque {
private:
    int arr[100];
    int frontIndex, rearIndex;
    int count;

public:
    Deque() {
        frontIndex = 50;  // start from middle for room both ends
        rearIndex = 49;
        count = 0;
    }

    void push_front(int value) {
        if (frontIndex == 0) {
            cout << "No space at front\n";
            return;
        }
        frontIndex--;
        arr[frontIndex] = value;
        count++;
    }

    void push_back(int value) {
        if (rearIndex == 99) {
            cout << "No space at back\n";
            return;
        }
        rearIndex++;
        arr[rearIndex] = value;
        count++;
    }

    void pop_front() {
        if (empty()) {
            cout << "Deque is empty\n";
            return;
        }
        frontIndex++;
        count--;
    }

    void pop_back() {
        if (empty()) {
            cout << "Deque is empty\n";
            return;
        }
        rearIndex--;
        count--;
    }

    int front() {
        if (empty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    int back() {
        if (empty()) {
            cout << "Deque is empty\n";
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
    Deque dq;

    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(15);

    cout << "Front: " << dq.front() << endl; // 5
    cout << "Back: " << dq.back() << endl;   // 15

    dq.pop_front();  // removes 5
    dq.pop_back();   // removes 15

    cout << "Front now: " << dq.front() << endl; // 10
    cout << "Size: " << dq.size() << endl;

    dq.pop_back();   // removes 10

    if (dq.empty()) {
        cout << "Deque is now empty.\n";
    }

    return 0;
}
