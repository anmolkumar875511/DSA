#include<iostream>
#include<vector>
#include<map>
#include<set>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> col_wise;
        vector<vector<int>> res;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        if(!root) return res;
        
        while(!q.empty()) {
            pair<TreeNode*, pair<int, int>> ele = q.front();
            q.pop();

            TreeNode* curr = ele.first;
            int x = ele.second.first;
            int y = ele.second.second;
            col_wise[x][y].insert(curr->val);

            if(curr->left) q.push({curr->left, {x - 1, y+1}});
            if(curr->right) q.push({curr->right, {x + 1, y+1}});
        }
        
        for(auto p : col_wise) {
            vector<int> col;
            for(auto q : p.second) col.insert(col.end(), q.second.begin(), q.second.end());
            res.push_back(col);
        }

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

    vector<vector<int>> results = sol.verticalTraversal(root);

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