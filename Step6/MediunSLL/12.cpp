#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    ListNode* segregate(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* zeroD = new ListNode(0);
        ListNode* oneD = new ListNode(0);
        ListNode* twoD = new ListNode(0);

        ListNode *zero = zeroD, *one = oneD, *two = twoD;
        ListNode* curr = head;

        while (curr) {
            if (curr->val == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->val == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        zero->next = (oneD->next) ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr;

        ListNode* newHead = zeroD->next;
        delete zeroD;
        delete oneD;
        delete twoD;

        return newHead;
    }
};


int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    ListNode* newHead = sol.segregate(head);
    while (newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}