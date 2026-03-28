#include<iostream>
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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int size = q.size();
            long long mini = q.front().second;
            int first, last;
            for(int i = 0; i < size; i++) {
                long long curr_id = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = curr_id;
                if(i == size - 1) last = curr_id;
                if(node->left) q.push({node->left, 2 * curr_id + 1});
                if(node->right) q.push({node->right, 2 * curr_id + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
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

    cout << "Width of binary tree is: " << sol.widthOfBinaryTree(root) << endl; // Output: 4

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}