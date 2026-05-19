#include<iostream>
using namespace std;

class ArrayStack {
private:
    int* stack;
    int capacity;
    int idx;
public:
    ArrayStack(int size = 1000) {
        capacity = size;
        stack = new int[capacity];
        idx = -1;
    }
    
    void push(int x) {
        if(idx >= capacity - 1) {
            cout << "Stack Overflow!!" << endl;
            return;
        }
        stack[++idx] = x;
    }
    
    int pop() {
        if(idx < 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stack[idx--];
    }
    
    int top() {
        if(idx < 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stack[idx];
    }
    
    bool isEmpty() {
        return idx == -1;
    }
};


int main() {
    ArrayStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << endl;
    cout << s.top() << endl;
    return 0;
}