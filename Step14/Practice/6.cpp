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
    bool isBSTUtil(TreeNode* node, long long min, long long max) {
        if (node == nullptr) 
            return true;

        if (node->val <= min || node->val >= max) 
            return false;

        return isBSTUtil(node->left, min, node->val) &&
               isBSTUtil(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
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
    cout << sol.isValidBST(root);
    return 0;
}