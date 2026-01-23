#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public: 
    ListNode *meetPoint(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return slow;
            }
        }
        return nullptr;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *temp1 = head;
        ListNode *temp2 = meetPoint(head);
        if(temp2 == nullptr) {
            return temp2;
        }
        while(temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};


int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    head->next = second;
    second->next = third;
    third->next = second;
    cout << sol.detectCycle(head)->val;
    return 0;
}