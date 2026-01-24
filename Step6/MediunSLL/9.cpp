#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ahead = head;
        ListNode* back = head;
        while(n > 0 && ahead) {
            ahead = ahead->next;
            n--;
        }
        if(!(ahead)) {
            return back->next;
        }
        while(ahead->next) {
            ahead = ahead->next;
            back = back->next;
        }
        back->next = back->next->next;
        return head;
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
    ListNode* temp = sol.removeNthFromEnd(head, 2);
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}