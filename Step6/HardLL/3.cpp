#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
public:
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        
        Node* result;
        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }
        result->next = nullptr;
        return result;
    }

    Node* flatten(Node* root) {
        if (!root || !root->next) return root;
        root->next = flatten(root->next);
        root = merge(root, root->next);
        
        return root;
    }
};


int main() {
    Solution sol;
    Node* head = new Node(5);
    head->bottom = new Node(10);
    head->bottom->bottom = new Node(19);
    head->bottom->bottom->bottom = new Node(28);
    head->bottom->bottom->bottom->bottom = new Node(35);
    head->bottom->bottom->bottom->bottom->bottom = new Node(40);
    head->bottom->bottom->bottom->bottom->bottom->bottom = new Node(45);
    head->bottom->bottom->bottom->bottom->bottom->bottom->bottom = new Node(50);
    
    head = sol.flatten(head);
    
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    return 0;
}
