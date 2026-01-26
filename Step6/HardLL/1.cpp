#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> reverser(ListNode* node, int k) {

        ListNode* curr = node;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        for(int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return {prev, node, curr};
    }


    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;

        while(true) {
            ListNode* kth = groupPrev;
            for(int i = 0; i < k; i++) {
                kth = kth->next;
                if(!kth) return dummy->next;
            }
            ListNode* groupStart = groupPrev->next;
            vector<ListNode*> result = reverser(groupStart, k);

            ListNode* newGroupHead = result[0];
            ListNode* newGroupTail = result[1];
            ListNode* nextGroupStart = result[2];

            groupPrev->next = newGroupHead;
            newGroupTail->next = nextGroupStart;
            groupPrev = newGroupTail;
        }
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    ListNode* result = sol.reverseKGroup(head, k);
    while(result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}