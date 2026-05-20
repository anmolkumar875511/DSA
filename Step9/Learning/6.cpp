#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next; 
    Node(int d) {
        val = d;
        next = nullptr;
    }
};

class LinkedListQueue {
private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedListQueue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    void push(int x) {
        Node* newNode = new Node(x);
        if(!size) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    int pop() {
        if(!head) return -1;
        Node* front = head;
        if(!head->next) {
            head = nullptr;
        }
        else {
            head = front->next;
        }
        int val = front->val;
        delete front;
        size--;
        return val;
    }
    
    int peek() {
        if(!head) return -1;
        return head->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    LinkedListQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}