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
    Node *deleteHead(Node *&head) {
        if(head == nullptr) {
            return nullptr;
        }
        Node *temp = head;
        head = head->next;

        if(head != nullptr) {
            head->prev = nullptr;
        }
        
        delete temp;
        return head;
    }
};