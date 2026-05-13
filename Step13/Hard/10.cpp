#include<iostream>
#include<vector>
#include<map>
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
    TreeNode* builder(vector<int>& inorder, int inStart, int inEnd,
                      vector<int>& postorder, int postStart, int postEnd,
                      map<int, int>& mp) {

        if (postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mp[postorder[postEnd]];
        int leftSize = inRoot - inStart;

        root->left = builder(inorder, inStart, inRoot - 1,
                             postorder, postStart, postStart + leftSize - 1, mp);

        root->right = builder(inorder, inRoot + 1, inEnd,
                              postorder, postStart + leftSize, postEnd - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return builder(inorder, 0, inorder.size() - 1,
                       postorder, 0, postorder.size() - 1, mp);
    }
};


int main() {
    Solution sol;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = sol.buildTree(inorder, postorder);
    return 0;
}