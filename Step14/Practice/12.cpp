#include<iostream>
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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void helper(TreeNode* node) {
        if(!node) return;
        helper(node->left);
        if(prev && prev->val > node->val) {
            if(!first) {
                first = prev;
                second = node;
            }
            else {
                second = node;
            }
        }
        prev = node;
        helper(node->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first->val, second->val);
    }
};


int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    Solution sol;
    sol.recoverTree(root);
    cout << root->val << " " << root->left->val << " " << root->right->val << endl;
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}