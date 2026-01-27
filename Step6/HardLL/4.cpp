#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* newHead = head->next;
        Node* currOld = head;
        Node* currNew = newHead;
        
        while (currOld) {
            currOld->next = currOld->next->next;
            if (currNew->next) {
                currNew->next = currNew->next->next;
            }
            currOld = currOld->next;
            currNew = currNew->next;
        }

        return newHead;
    }
};


int main() {
    Solution sol;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    
    Node* newHead = sol.copyRandomList(head);
    Node* temp = newHead;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}