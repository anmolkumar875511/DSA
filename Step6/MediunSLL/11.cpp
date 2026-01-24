#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }

private:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(4);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(1);
    ListNode* fourth = new ListNode(3);
    head->next = second;
    second->next = third;
    third->next = fourth;
    ListNode* temp = sol.sortList(head);
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}