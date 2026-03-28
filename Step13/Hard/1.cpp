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
    void helper(vector<vector<int>>& v, vector<int>& a, TreeNode* node) {
        a.push_back(node->val);
        if(!node->left && !node->right) {
            v.push_back(a);
            return;
        }
        if(node->left) {
            helper(v, a, node->left);
            a.pop_back();
        }
        if(node->right) {
            helper(v, a, node->right);
            a.pop_back();
        }
    }
    vector<vector<int>> Paths(TreeNode* root) {
            vector<vector<int>> v;
            vector<int> a;
            helper(v, a, root);
            return v;
    }
};


int main(){
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

    vector<vector<int>> results = sol.Paths(root);

    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
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