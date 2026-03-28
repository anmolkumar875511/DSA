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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stp, stq;
        stp.push(p);
        stq.push(q);
        while(!stp.empty() && !stq.empty()) {
            TreeNode* currp = stp.top();
            TreeNode* currq = stq.top();
            stp.pop();
            stq.pop();
            if(currp && currq) {
                if(currp->val != currq->val) return false;
                stp.push(currp->right);
                stp.push(currp->left);
                stq.push(currq->right);
                stq.push(currq->left);
            }
            else if((currp && (!currq)) || (currq && (!currp))) return false;
        }
        return true;
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

    cout << "Is binary trees same? "; 
    if(sol.isSameTree(root, root)) cout << "True"; // Output: True
    else cout << "False";
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}