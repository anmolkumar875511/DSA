#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> temp;
        unordered_map<TreeNode*, int> level;
        int curr_level = 0;
        q.push(root);
        level[root] = 1;
        if(!root) return res;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr_level != level[curr]) {
                if(curr_level > 0) res.push_back(temp);
                curr_level ++;
                temp.clear();
            }
            temp.push_back(curr->val);
            if(curr->left) {
                q.push(curr->left);
                level[curr->left] = level[curr] + 1;
            }
            if(curr->right) {
                q.push(curr->right);
                level[curr->right] = level[curr] + 1;
            }
        }
        res.push_back(temp);
        return res;
    }
};


int main() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> res = sol.levelOrder(root);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}