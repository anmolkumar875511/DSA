#include<iostream>
#include<stack>
using namespace std;

class Solution {
  public:
    void insert(int val, stack<int> &st) {
        if(st.empty() || st.top() <= val) {
            st.push(val);
            return;
        }
        int temp = st.top();
        st.pop();
        insert(val, st);
        st.push(temp);
    }
    void sortStack(stack<int> &st) {
        if(!st.empty()) {
            int temp = st.top();
            st.pop();
            sortStack(st);
            insert(temp, st);
        }
    }
};


int main() {
    Solution sol;
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    sol.sortStack(st);
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    // Output: 1 2 3 4
    return 0;
}