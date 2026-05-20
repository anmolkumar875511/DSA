#include<iostream>
#include<vector>
using namespace std;

class MinStack {
private:
    vector<pair<int, int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min_val = getMin();
        if(st.empty() || min_val > val) min_val = val;
        st.push_back({val, min_val});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.back().first;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return st.back().second;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // Output: -3
    minStack.pop();
    cout << minStack.top() << endl; // Output: 0
    cout << minStack.getMin() << endl; // Output: -2
    return 0;
}