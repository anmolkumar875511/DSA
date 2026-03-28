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
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) return true;
        else if(root->left && root->right) {
            queue<TreeNode*> lq, rq;
            lq.push(root->left);
            rq.push(root->right);
            while(!lq.empty() && !rq.empty()) {
                TreeNode* left_node = lq.front();
                TreeNode* right_node = rq.front();
                lq.pop();
                rq.pop();
                if((left_node->val != right_node->val)  
                || (left_node->left && !right_node->right)
                || (!left_node->left && right_node->right)
                || (left_node->right && !right_node->left)
                || (!left_node->right && right_node->left)){
                    return false;
                }
                if(left_node->left && right_node->right) {
                    lq.push(left_node->left);
                    rq.push(right_node->right);
                }
                if(left_node->right && right_node->left) {
                    lq.push(left_node->right);
                    rq.push(right_node->left);
                }
            }
            return true;
        }
        return false;
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

    cout << "Is binary trees symmetric? "; 
    if(sol.isSymmetric(root)) cout << "True"; // Output: False
    else cout << "False";
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}