#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if(fast->next != nullptr) {
                fast = fast->next;
            }
        }
        return slow;
    }
};


int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    
    ListNode* temp = sol.middleNode(head);
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}