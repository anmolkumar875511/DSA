#include<iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int d) {
        val = d;
        next = nullptr;
    }
};
class LinkedListStack {
private:
    Node* head;
    int size;
public:
    LinkedListStack() {
        head = nullptr;
        size = 0;
    }
    
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    int pop() {
        if(!head) return -1;
        Node* top = head;
        head = top->next;
        int val = top->val;
        delete top;
        size--;
        return val;
    }
    
    int top() {
        if(!head) return -1;
        return head->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    LinkedListStack s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}