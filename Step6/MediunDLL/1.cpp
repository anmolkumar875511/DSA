#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
};

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // code here
        if(!head_ref || !(*head_ref)) {
            return;
        }
        Node* curr = *head_ref;
        while(curr) {
            if(curr->data == x) {
                Node* next = curr->next;
                if(curr == *head_ref) {
                    *head_ref = curr->next;
                }
                if(curr->prev) {
                    curr->prev->next  = curr->next;
                }
                if(curr->next) {
                    curr->next->prev = curr->prev;
                }
                delete curr;
                curr = next;
            }
            else {
                curr = curr->next;
            }
        }
    }
};


int main() {
    Solution s;
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(10);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    
    s.deleteAllOccurOfX(&head, 10);
    
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}