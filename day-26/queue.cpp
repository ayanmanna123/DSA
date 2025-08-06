#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int>q;
    q.push(1);
    int j=2;
     q.push(j++);
     q.pop();
      cout<< q.front() << endl;
}