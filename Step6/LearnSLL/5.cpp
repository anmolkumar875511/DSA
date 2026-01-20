#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool searchKey(ListNode* head, int key) {
        ListNode* temp = head;
        while(temp != nullptr) {
            if(temp->val == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};


int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    head->next = second;
    second->next = third;
    
    cout << sol.searchKey(head, 2) << "\n";
    return 0;
}