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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root)
            if(key < root->val) root->left = deleteNode(root->left, key);
            else if(key > root->val) root->right = deleteNode(root->right, key);

            else{
                if(!root->left && !root->right) return nullptr;

                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;

                TreeNode* temp = root->left;
                while(temp->right) temp = temp->right;
                
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        return root;
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
    sol.deleteNode(root, 3);
    return 0;
}