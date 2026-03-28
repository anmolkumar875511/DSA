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
    bool isSumProperty(TreeNode *root) {
        if(!root || (!(root->left) && !(root->right))) return true;
        int left = 0, right = 0;
        bool is_left = true, is_right = true;
        if(root->left) {
            left = root->left->val;
            is_left = isSumProperty(root->left);
        }
        if(root->right) {
            right = root->right->val;
            is_right = isSumProperty(root->right);
        }
        if(is_left && is_right && root->val == left + right) return true;
        return false;
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

    cout << "Is binary tree sum property? "; 
    if(sol.isSumProperty(root)) cout << "True"; // Output: False
    else cout << "False";
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}