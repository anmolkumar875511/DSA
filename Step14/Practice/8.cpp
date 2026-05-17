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
    TreeNode* builder(TreeNode* node, vector<int>& preorder, int s, int e) {
        if(s < 0 || s > e || e >= preorder.size()) {
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(preorder[s]);
        node = newNode;
        int i = s + 1;
        while(i <= e && preorder[s] > preorder[i]) i++;
        node->left = builder(node->left, preorder, s + 1, i - 1);
        node->right = builder(node->left, preorder, i, e);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root;
        return builder(root, preorder, 0, preorder.size() - 1);
    }
};


int main() {
    Solution sol;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode* root = sol.bstFromPreorder(preorder);
    cout << root->val << endl;
    return 0;
}