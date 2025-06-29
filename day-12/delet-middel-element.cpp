#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    stack<int> ans;
    st.push(3);
    st.push(4);
    st.push(5);

    st.push(6);
    st.push(7);
    int mid = (st.size() / 2);
    int n = st.size();
    for (int i = 0; i < n; i++)
    {   
        int tem=st.top();

        if (i != mid)
        {
            ans.push(tem);
        }
        st.pop();
    }
    int n1=ans.size();
    for(int i=0;i<n1;i++){
        int tem=ans.top();
        cout<< tem <<" ";
        ans.pop();
    }
}