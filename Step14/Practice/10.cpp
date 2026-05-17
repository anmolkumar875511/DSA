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

class BSTIterator {
private:
    int idx = 0;
    vector<int> inorder;
    void InOrder(TreeNode* node) {
        if(!node) return;
        if(node->left) InOrder(node->left);
        inorder.push_back(node->val);
        if(node->right) InOrder(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        InOrder(root);
    }
    
    int next() {
        return inorder[idx++];
    }
    
    bool hasNext() {
        return idx < inorder.size();
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
    BSTIterator it = BSTIterator(root);
    while(it.hasNext()) {
        cout << it.next() << " ";
    }
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}