#include<iostream>
#include<vector>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
};

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> result;
        if (!head) return result;

        Node *left = head;
        Node *right = head;
        while (right->next != NULL) {
            right = right->next;
        }

        while (left != right && right->next != left) {
            int currentSum = left->data + right->data;

            if (currentSum == target) {
                result.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            } 
            else if (currentSum < target) {
                left = left->next;
            } 
            else {
                right = right->prev;
            }
        }
        return result;
    }
};


int main() {
    Solution sol;
    Node* head = new Node(5);
    head->next = new Node(6);
    head->next->prev = head;
    head->next->next = new Node(7);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(8);
    head->next->next->next->prev = head->next->next;
    int target = 13;
    vector<pair<int, int>> result = sol.findPairsWithGivenSum(head, target);
    for (const auto& pair : result) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;
    return 0;
}