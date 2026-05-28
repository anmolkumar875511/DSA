#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        priority_queue<int,vector<int>,greater<int>> pq;
        ListNode* head = NULL; 
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]){
                if(!head) head = lists[i];
                ListNode* temp = lists[i];
                while(temp->next){
                    pq.push(temp->val);
                    temp = temp->next;
                }
                pq.push(temp->val);
                if(i < lists.size()-1){
                    int k = i+1;
                    while(k < lists.size() && !lists[k]) k++;
                    if(k < lists.size()) temp->next = lists[k];
                } 
            }
        }
        ListNode* temp = head;
        while(temp){
            temp->val = pq.top();
            pq.pop();
            temp = temp->next;
        }
        return head;
    }
};


int main() {
    Solution sol;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* merged = sol.mergeKLists(lists);
    while(merged){
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
    return 0;
}