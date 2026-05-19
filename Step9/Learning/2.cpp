#include<iostream>
using namespace std;

class ArrayQueue {
private:
    int* queue;
    int capacity;
    int head;
    int tail;

public:
    ArrayQueue(int size = 1000) {
        capacity = size;
        queue = new int[capacity];
        head = 0;
        tail = -1;
    }

    void push(int x) {
        if(tail >= capacity - 1) {
            cout << "Queue Overflow!!" << endl;
            return;
        }

        queue[++tail] = x;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return queue[head++];
    }

    int peek() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return queue[head];
    }

    bool isEmpty() {
        return head > tail;
    }

    ~ArrayQueue() {
        delete[] queue;
    }
};

int main() {
    ArrayQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.pop() << endl;
    cout << q.peek() << endl;
    return 0;
}