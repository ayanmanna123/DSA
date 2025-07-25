#include <bits/stdc++.h>
using namespace std;
class heap
{

public:
    int arr[100];
    int size = 0;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deletnode()
    {
        if (size == 0)
        {
            cout << "no element is avalable" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i <= size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }
};

int main()
{
    heap h;
    h.insert(3);
    h.insert(5);
    h.insert(1);
    h.insert(4);
    h.insert(7);
    h.insert(9);
    h.insert(8);
    h.insert(0);

    h.print();
    h.deletnode();
    h.print();
}
