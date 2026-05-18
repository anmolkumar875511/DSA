#include<iostream>
#include<climits>
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
    int ans = 0;

    struct Info {
        bool isBST;
        int mini;
        int maxi;
        int sum;
    };

    Info dfs(TreeNode* root) {
        if (!root) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        if (left.isBST && right.isBST &&
            root->val > left.maxi &&
            root->val < right.mini) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return {
                true,
                min(root->val, left.mini),
                max(root->val, right.maxi),
                currSum
            };
        }

        return {false, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
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
    Solution sol;
    cout << sol.maxSumBST(root);
    return 0;
}