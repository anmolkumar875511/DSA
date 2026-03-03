#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void in_order(vector<int>& v, TreeNode* node) {
        if (node == nullptr) return;
        in_order(v, node->left);
        v.push_back(node->data);
        in_order(v, node->right);
    }

    void pre_order(vector<int>& v, TreeNode* node) {
        if (node == nullptr) return;
        v.push_back(node->data);
        pre_order(v, node->left);
        pre_order(v, node->right);
    }

    void post_order(vector<int>& v, TreeNode* node) {
        if (node == nullptr) return;
        post_order(v, node->left);
        post_order(v, node->right);
        v.push_back(node->data);
    }

    vector<vector<int>> treeTraversal(TreeNode* root) {
        vector<int> inOrder, preOrder, postOrder;
        in_order(inOrder, root);
        pre_order(preOrder, root);
        post_order(postOrder, root);
        return {inOrder, preOrder, postOrder};
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
    vector<vector<int>> results = sol.treeTraversal(root);

    string names[] = {"Inorder", "Preorder", "Postorder"};
    for (int i = 0; i < 3; i++) {
        cout << names[i] << ": ";
        for (int val : results[i]) {
            cout << val << " ";
        }
        cout << endl;
    }

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
