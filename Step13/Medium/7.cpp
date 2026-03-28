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
    bool isLeaf(TreeNode* node) {
        return !node->left && !node->right;
    }
    
    void addLeftBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;
        while(curr) {
            if(!isLeaf(curr)) res.push_back(curr->val);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void addLeaves(TreeNode* root, vector<int>& res) {
        if(isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        if(root->left) addLeaves(root->left, res);
        if(root->right) addLeaves(root->right, res);
    }
    
    void addRightBoundary(TreeNode* root, vector<int>& res) {
        vector<int> temp;
        TreeNode* curr = root->right;
        while(curr) {
            if(!isLeaf(curr)) temp.push_back(curr->val);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        for(int i = temp.size() - 1; i >=0; i--) res.push_back(temp[i]);
    }
    vector<int> boundaryTraversal(TreeNode *root) {
    	vector<int> res;
    	
        if(!root) return res;
        
        if(!isLeaf(root)) res.push_back(root->val);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        
        return res;
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

    vector<int> results = sol.boundaryTraversal(root);

    for (int val : results) {
        cout << val << " ";
    }
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}