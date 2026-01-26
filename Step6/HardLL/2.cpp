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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* a = head;
        int n = 1;
        while(a->next) {
            a = a->next;
            n++;
        }
        
        k = k % n;
        a->next = head;

        for(int i = k; i < n; i++) {
            a = a->next;
        }

        head = a->next;
        a->next = nullptr;
        return head;
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
    ListNode* result = sol.rotateRight(head, k);
    while(result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}