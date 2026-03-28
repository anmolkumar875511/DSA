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
    int max_sum = INT_MIN;
    int helper(TreeNode* node) {
        if(!node) return 0;
        int left_sum = max(helper(node->left), 0);
        int right_sum = max(helper(node->right), 0);
        max_sum = max(max_sum, node->val + left_sum + right_sum);
        return node->val + max(left_sum, right_sum);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return max_sum;
    }
};

int main() {
    /* 
       Constructing a sample tree:
             1
            / \
           2   3
          / \
         4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;

    cout << "Maximum path sum in binary tree is: " << sol.maxPathSum(root) << endl; // Output: 11

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}