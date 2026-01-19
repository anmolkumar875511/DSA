#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }

    Node(int x, Node* next){
        data = x;
        this->next = next;
    }
};

class Solution{
    public:
    Node* insertAtHead(Node* head, int x){
        Node* temp = new Node(x, head);
        return temp;
    }

    void print(Node* head) {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};


int main() {
    Solution s;
    Node* head = nullptr;
    head = s.insertAtHead(head, 10);
    head = s.insertAtHead(head, 20);
    head = s.insertAtHead(head, 30);
    s.print(head);
    return 0;
}