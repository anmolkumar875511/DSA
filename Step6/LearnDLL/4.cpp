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
    Node* reverseDLL(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node *curr = head;
        Node *temp = nullptr;

        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        return temp->prev;
    }
};


int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    head->next = second;
    second->prev = head;
    
    Solution s;
    head = s.reverseDLL(head);
    
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    return 0;
}