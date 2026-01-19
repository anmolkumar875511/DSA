#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    Node(int data,Node* next){
        this->data=data;
        this->next=next;
    }
};

int main() {
    Node* head = new Node(10);
    Node* third = new Node(30);
    Node* second = new Node(20, third);
    head->next = second;
    
    for(int i = 0; i < 3; i++) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}