#include<iostream>
#include<stack>
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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        int max_depth = 0;
        if(!root) return max_depth;
        while(!st.empty()) {
            pair<TreeNode*, int> tp = st.top();
            st.pop();
            TreeNode* curr = tp.first;
            int depth = tp.second;
            while(curr) {
                depth++;
                max_depth = max(max_depth, depth);
                if(curr->right) st.push({curr->right, depth});
                curr = curr->left;
            }
        }
        return max_depth;
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

    cout << "Maximum depth of binary tree is: " << sol.maxDepth(root) << endl; // Output: 3

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}