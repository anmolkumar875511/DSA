#include<iostream>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int findCeil(TreeNode* root, int x) {
        TreeNode* curr = root;
        int ans = INT_MAX;
        while(curr) {
            if(curr->val > x) {
                ans = min(ans, curr->val);
                curr = curr->left;
            }
            else if(curr->val < x) {
                curr = curr->right;
            }
            else {
                ans = x;
                return ans;
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    Solution sol;
    cout << sol.findCeil(root, 5) << endl;
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}