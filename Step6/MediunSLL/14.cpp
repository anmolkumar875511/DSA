#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addOne(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int carry = 1;
        while(carry && curr) {
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;
            prev = curr;
            curr = curr->next;
        }
            if(carry && prev) {
                prev->next = new ListNode(carry);
                carry = 0;
            }
        head = reverse(head);
        return head;
    }
};


int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    ListNode* newHead = s.addOne(head);
    while(newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}