#include<iostream>
#include<vector>
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
    void func(TreeNode* node, vector<int>& v) {
        if(!node) return;
        if(node->left) func(node->left, v);
        v.push_back(node->val);
        if(node->right) func(node->right, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        func(root, v);
        return v[k - 1];
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
    cout << sol.kthSmallest(root, 3);
    return 0;
}