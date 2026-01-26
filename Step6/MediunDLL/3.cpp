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

    Node *removeDuplicates(struct Node *head) {
        if(!head || !head->next) {
            return head;
        }
        Node* curr = head;
        while(curr->next) {
            if(curr->data == curr->next->data) {
                Node* duplicate = curr->next;
                curr->next = duplicate->next;
                if (curr->next) {
                    curr->next->prev = curr;
                }
                delete duplicate;
            }
            else {
                curr = curr->next;
            }
        }
        return head;
    }
};

int main() {
    Solution sol;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;
    head = sol.removeDuplicates(head);
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}