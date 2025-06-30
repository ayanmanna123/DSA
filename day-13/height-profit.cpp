#include <bits/stdc++.h>
using namespace std;

int main() {
     queue<int > q;
     queue <int > q1;
     q.push(8);
      q.push(9);
       q.push(5);
        q.push(6);

//     cout << q.front() <<endl;
//     cout<< q.back() <<endl;
//     cout << q.empty() <<endl;
//     q.pop() ;
//     q.push(7);
//    cout <<  q.size() <<endl;
//    q.swap(q1);
      int n=q.size();
   for(int i=0;i<n;i++){
    int tem= q.front();
    cout << tem<< " ";
    q.pop();
   }
}