#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int x, Node *next, Node *prev) {
        data = x;
        this->next = next;
        this->prev = prev;
    }

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};


int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    head->next = second;
    second->prev = head;
    
    for(Node* temp = head; temp != nullptr; temp = temp->next) {
        cout << temp->data << " ";
    }
    
    return 0;
}