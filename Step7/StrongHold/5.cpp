#include<iostream>
#include<stack>
using namespace std;

class Solution {
  public:
    void insert(stack<int> &st, int t) {
        if(st.empty()) {
            st.push(t);
            return ;
        }
        int temp = st.top();
        st.pop();
        insert(st, t);
        st.push(temp);
    }
    void reverseStack(stack<int> &st) {
        int t = st.top();
        st.pop();
        if(st.empty()) {
            insert(st, t);
            return;
        }
        reverseStack(st);
        insert(st, t);
    }
};


int main() {
    Solution sol;
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    sol.reverseStack(st);
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    // Output: 1 2 3 4
    return 0;
}