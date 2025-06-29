#include <iostream>
#include <stack>
using namespace std;

int main() {
    
    stack <int> st;
    st.push(2);
    st.push(3);
    st.push(4);
    int s=1;
    stack<int> st2;
    st2.push(s);
    st.swap(st2);
//     cout << st.size()<<endl;
//     cout << st.top() <<endl;
//     st.pop();
//     cout << st.top() <<endl;
//     st.pop();
//     st.pop();
//      cout << st.size()<<endl;

//    cout << st.empty()<<endl;
  for (int i = 0; i < 3; i++)
  {
    cout << st.top() <<endl;
    st.pop();

  }
  

}