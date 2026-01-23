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
    int lengthOfLoop(ListNode *head) {
        ListNode *temp1 = meetPoint(head);
        if(temp1 == nullptr) {
            return 0;
        }
        ListNode *temp2 = temp1;
        int cnt = 1;
        while(temp1 != temp2->next) {
            temp2 = temp2->next;
            cnt++;
        }
        return cnt;
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
    cout << sol.lengthOfLoop(head);
    return 0;
}