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
    vector<TreeNode*> findPreSuc(TreeNode* root, int key) {
        TreeNode* pre = nullptr;
        TreeNode* suc = nullptr;

        while (root) {
            if (root->val < key) {
                pre = root;
                root = root->right;
            }
            else if (root->val > key) {
                suc = root;
                root = root->left;
            }
            else {
                TreeNode* temp = root->left;
                while (temp) {
                    pre = temp;
                    temp = temp->right;
                }

                temp = root->right;
                while (temp) {
                    suc = temp;
                    temp = temp->left;
                }
                break;
            }
        }

        return {pre, suc};
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
    vector<TreeNode*> result = sol.findPreSuc(root, 5);
    cout << result[0]->val << " " << result[1]->val << endl;
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}