#include<iostream>
#include<vector>
#include<map>
#include<queue>
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
    vector<int> bottomView(TreeNode *root) {
        
        vector<int> res;
        map<int, int> ver;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        if(!root) return res;
        
        while(!q.empty()) {
            
            auto ele = q.front();
            q.pop();
            TreeNode* curr = ele.first;
            int x = ele.second;
            
            ver[x] = curr->val;
            if(curr->left) q.push({curr->left, x - 1});
            if(curr->right) q.push({curr->right, x + 1});
        }
        
        for(auto const& [x, val] : ver) res.push_back(val);
        
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

    vector<int> results = sol.bottomView(root);

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