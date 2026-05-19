#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty()) {
            int top = st1.top();
            st2.push(top);
            st1.pop();
        }
        st2.push(x);
        while(!st2.empty())  {
            int top = st2.top();
            st1.push(top);
            st2.pop();
        }
    }
    
    int pop() {
        int top = st1.top();
        st1.pop();
        return top;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
    return 0;
}