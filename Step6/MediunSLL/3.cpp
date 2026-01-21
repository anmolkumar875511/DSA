#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reccursion(ListNode* temp1, ListNode* temp2) {
        if(temp2 == nullptr) {
            return temp1;
        }
        ListNode* temp3 = temp2->next;
        temp2->next = temp1;
        return reccursion(temp2, temp3);
    }
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode* temp2 = head->next;
        ListNode* temp1 = head;
        temp1->next = nullptr;
        return reccursion(temp1, temp2);
    }
};


int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    head->next = second;
    second->next = third;
    
    ListNode* temp = sol.reverseList(head);
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}