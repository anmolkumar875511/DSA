#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while(temp1 != temp2) {
            temp1 = temp1 ? temp1->next : headB;
            temp2 = temp2 ? temp2->next : headA;
        }
        return temp1;
    }
};


int main() {
    Solution sol;
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    ListNode* head2 = new ListNode(4);
    head2->next = new ListNode(5);
    head2->next->next = new ListNode(6);
    ListNode* newHead = sol.getIntersectionNode(head1, head2);
    while (newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}