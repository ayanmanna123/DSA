#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    vector<int> a;
    a = {9, 8, 7, 6, 5, 4, 3, 2};
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
        a.pop_back();
    }
    stack<int> st;
    for (int i = 0; i < n; i++)
    {

        st.push(pq.top());
        pq.pop();
    }

    for (int i = 0; i < n; i++)
    {
        a.push_back(st.top());
        st.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}