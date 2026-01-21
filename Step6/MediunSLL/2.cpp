#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode* temp1 = head->next;
        ListNode* temp2 = head;
        ListNode* temp3 = nullptr;

        while(temp1 != nullptr) {
            temp2->next = temp3;
            temp3 = temp2;
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp3;
        return temp2;
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