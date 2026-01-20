#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while(temp != nullptr) {
            size++;
            temp = temp->next;
        }
        return size;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    head->next = second;
    second->next = third;
    
    cout << sol.getLength(head);
    return 0;
}