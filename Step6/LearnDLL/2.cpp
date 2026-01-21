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

class Solution {
public:
    Node* insertBeforeHead(Node* head, int X) {
        Node* newNode = new Node(X);

        if(head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }

        return newNode;
    }
};


int main() {
    Solution s;
    Node* head = nullptr;
    head = s.insertBeforeHead(head, 10);
    head = s.insertBeforeHead(head, 20);
    head = s.insertBeforeHead(head, 30);
    head = s.insertBeforeHead(head, 40);
    head = s.insertBeforeHead(head, 50);

    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    return 0;
}